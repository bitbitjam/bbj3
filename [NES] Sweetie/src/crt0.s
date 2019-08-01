;
; Startup code for cc65 (NES version)
;
; by Groepaz/Hitmen <groepaz@gmx.net>
; based on code by Ullrich von Bassewitz <uz@cc65.org>
; edit by The Goat <goat@ridiculousglitch.com>
;

        .export         _exit, _screen_load
        .import         __cur_nametable, __scroll_x, __scroll_y
        .export         __STARTUP__ : absolute = 1      ; Mark as startup
        .import         initlib, donelib, callmain, _waitvblank
        .import         push0, popa, _main, zerobss, copydata
        .import         ppubuf_flush

        ; Linker generated symbols
        ; .import         __RAM_START__, __RAM_SIZE__
        .import         __SRAM_START__, __SRAM_SIZE__
        .import         __ROM0_START__, __ROM0_SIZE__
        .import         __STARTUP_LOAD__,__STARTUP_RUN__, __STARTUP_SIZE__
        .import         __CODE_LOAD__,__CODE_RUN__, __CODE_SIZE__
        .import         __RODATA_LOAD__,__RODATA_RUN__, __RODATA_SIZE__

        .include        "zeropage.inc"
        .include        "nes.inc"

.segment "ZEROPAGE"
        RLE_LOW:          .res 1
        RLE_HIGH:         .res 1
        RLE_TAG:          .res 1
        RLE_BYTE:         .res 1


; ------------------------------------------------------------------------
; 16 bytes INES header

.segment        "HEADER"

;    +--------+------+------------------------------------------+
;    | Offset | Size | Content(s)                               |
;    +--------+------+------------------------------------------+
;    |   0    |  3   | 'NES'                                    |
;    |   3    |  1   | $1A                                      |
;    |   4    |  1   | 16K PRG-ROM page count                   |
;    |   5    |  1   | 8K CHR-ROM page count                    |
;    |   6    |  1   | ROM Control Byte #1                      |
;    |        |      |   %####vTsM                              |
;    |        |      |    |  ||||+- 0=Horizontal mirroring      |
;    |        |      |    |  ||||   1=Vertical mirroring        |
;    |        |      |    |  |||+-- 1=SRAM enabled              |
;    |        |      |    |  ||+--- 1=512-byte trainer present  |
;    |        |      |    |  |+---- 1=Four-screen mirroring     |
;    |        |      |    |  |                                  |
;    |        |      |    +--+----- Mapper # (lower 4-bits)     |
;    |   7    |  1   | ROM Control Byte #2                      |
;    |        |      |   %####0000                              |
;    |        |      |    |  |                                  |
;    |        |      |    +--+----- Mapper # (upper 4-bits)     |
;    |  8-15  |  8   | $00                                      |
;    | 16-..  |      | Actual 16K PRG-ROM pages (in linear      |
;    |  ...   |      | order). If a trainer exists, it precedes |
;    |  ...   |      | the first PRG-ROM page.                  |
;    | ..-EOF |      | CHR-ROM pages (in ascending order).      |
;    +--------+------+------------------------------------------+

        .byte   $4e,$45,$53,$1a ; "NES"^Z
        .byte   2               ; ines prg  - Specifies the number of 16k prg banks.
        .byte   1               ; ines chr  - Specifies the number of 8k chr banks.
        .byte   %00000001       ; ines mir  - Specifies VRAM mirroring of the banks.
        .byte   %00000000       ; ines map  - Specifies the NES mapper used.
        .byte   0,0,0,0,0,0,0,0 ; 8 zeroes


; ------------------------------------------------------------------------
; Place the startup code in a special segment.

.segment        "STARTUP"

start:

; Set up the CPU and System-IRQ.

        sei
        cld
        ldx     #0
        stx     VBLANK_FLAG

        stx     ringread
        stx     ringwrite
        stx     ringcount

        txs

        lda     #$20
@l:     sta     ringbuff,x
        sta     ringbuff+$0100,x
        sta     ringbuff+$0200,x
        inx
        bne     @l

; Clear the BSS data.

        jsr     zerobss

; Initialize the data.
        jsr     copydata

; Set up the stack.

        lda     #<(__SRAM_START__ + __SRAM_SIZE__)
        ldx     #>(__SRAM_START__ + __SRAM_SIZE__)
        sta     sp
        stx     sp+1            ; Set argument stack ptr

; Call the module constructors.

        jsr     initlib

; Load tileset palette

        lda     #$3f
        sta     PPU_VRAM_ADDR2

        lda     #0
        sta     PPU_VRAM_ADDR2

        ldx     #0
@1:
        lda     tileset_palette,X
        sta     PPU_VRAM_IO
        inx
        cpx     #32
        bne     @1

; Push the command-line arguments; and, call main().

        jsr     callmain

; Call the module destructors. This is also the exit() entry.

_exit:  jsr     donelib         ; Run module destructors

; Reset the NES.

        jmp start


_screen_load:
        pha

        jsr popa
        and #$3
        asl
        asl
        adc #$20
        clc
        sta PPU_VRAM_ADDR2
        lda #0
        sta PPU_VRAM_ADDR2

        pla
        tay

        stx <RLE_HIGH
        lda #0
        sta <RLE_LOW

        lda (RLE_LOW),y
        sta <RLE_TAG
        iny
        bne @1
        inc <RLE_HIGH
@1:
        lda (RLE_LOW),y
        iny
        bne @11
        inc <RLE_HIGH
@11:
        cmp <RLE_TAG
        beq @2
        sta PPU_VRAM_IO
        sta <RLE_BYTE
        bne @1
@2:
        lda (RLE_LOW),y
        beq @4
        iny
        bne @21
        inc <RLE_HIGH
@21:
        tax
        lda <RLE_BYTE
@3:
        sta PPU_VRAM_IO
        dex
        bne @3
        beq @1
@4:
        rts


; ------------------------------------------------------------------------
; System V-Blank Interrupt
; Updates PPU Memory (buffered).
; Updates VBLANK_FLAG and tickcount.
; ------------------------------------------------------------------------

nmi:    pha
        tya
        pha
        txa
        pha

        lda     #1
        sta     VBLANK_FLAG

        inc     tickcount
        bne     @s
        inc     tickcount+1

;@s:     jsr     ppubuf_flush
;
;        ; Reset the video counter.
;        lda     #$20
;        sta     PPU_VRAM_ADDR2
;        lda     #$00
;        sta     PPU_VRAM_ADDR2
;
;        ; Reset scrolling.
;        sta     PPU_VRAM_ADDR1
;        sta     PPU_VRAM_ADDR1

@s:
        ; Set the video nametable
        lda     __cur_nametable
        ora     #$90
        sta     PPU_CTRL1

        lda     #$1e
        sta     PPU_CTRL2

        ; Reset scrolling
        lda     __scroll_x
        sta     PPU_VRAM_ADDR1

        lda     __scroll_y
        sta     PPU_VRAM_ADDR1

        ; lda     #2
        ; sta     APU_SPR_DMA

        pla
        tax
        pla
        tay
        pla

; Interrupt exit

irq2:
irq1:
timerirq:
irq:
        rti

; ------------------------------------------------------------------------
; hardware vectors
; ------------------------------------------------------------------------

.segment "VECTORS"

        .word   irq2        ; $fff4 ?
        .word   irq1        ; $fff6 ?
        .word   timerirq    ; $fff8 ?
        .word   nmi         ; $fffa vblank nmi
        .word   start       ; $fffc reset
        .word   irq         ; $fffe irq / brk

; ------------------------------------------------------------------------
; character data
; ------------------------------------------------------------------------

.segment "CHARS"
        ;.include "neschar.inc"
        .incbin "data/tileset.chr"

.segment "RODATA"
tileset_palette:
        .incbin "data/background.pal"
        .incbin "data/sprites.pal"
