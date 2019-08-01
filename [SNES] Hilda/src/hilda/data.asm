.include "hdr.asm"

.section ".rodata1" superfree
	; Splash graphic
	gfxsplashback: .incbin "splash.pic"
	gfxsplashback_end:
	mapsplashback: .incbin "splash.map"
	mapsplashback_end:
	palsplashback: .incbin "splash.pal"
	palsplashback_end:
.ends

.section ".rodata2" superfree
	; General Font
	snesfont: .incbin "font.pic"
	snesfont_end:
	; Player graphic
	gfxplayer: .incbin "player.pic"
	gfxplayer_end:
	palplayer: .incbin "player.pal"
.ends

.section ".rodata3" superfree
	; Title background graphic
	gfxtitleback: .incbin "title.pic"
	gfxtitleback_end:
	maptitleback: .incbin "title.map"
	maptitleback_end:
	paltitleback: .incbin "title.pal"
	paltitleback_end:
	; Title foreground graphic
	gfxtitlefore: .incbin "title-1.pic"
	gfxtitlefore_end:
	maptitlefore: .incbin "title-1.map"
	maptitlefore_end:
	paltitlefore: .incbin "title-1.pal"
	paltitlefore_end:
.ends

.section ".rodata4" superfree
	; Background graphic
	gfxbackground: .incbin "background.pic"
	gfxbackground_end:
	mapbackground: .incbin "background.map"
	mapbackground_end:
	palbackground: .incbin "background.pal"
	palbackground_end:
	; Room 1 graphic
	gfxroom1: .incbin "room1.pic"
	gfxroom1_end:
	maproom1: .incbin "room1.map"
	maproom1_end:
	palroom1: .incbin "room1.pal"
	palroom1_end:
	; Room 1 colision map
	maproom1col: .incbin "room1_col.clm"
	maproom1col_end:
.ends

.section ".rodata5" superfree
	; Room 2 graphic
	gfxroom2: .incbin "room2.pic"
	gfxroom2_end:
	maproom2: .incbin "room2.map"
	maproom2_end:
	palroom2: .incbin "room2.pal"
	palroom2_end:
	; Room 2 colision map
	maproom2col: .incbin "room2_col.clm"
	maproom2col_end:
	
	; Room 3 graphic
	gfxroom3: .incbin "room3.pic"
	gfxroom3_end:
	maproom3: .incbin "room3.map"
	maproom3_end:
	palroom3: .incbin "room3.pal"
	palroom3_end:
	; Room 3 colision map
	maproom3col: .incbin "room3_col.clm"
	maproom3col_end:
.ends

.section ".rodata6" superfree
	; Room 4 graphic
	gfxroom4: .incbin "room4.pic"
	gfxroom4_end:
	maproom4: .incbin "room4.map"
	maproom4_end:
	palroom4: .incbin "room4.pal"
	palroom4_end:
	; Room 4 colision map
	maproom4col: .incbin "room4_col.clm"
	maproom4col_end:
	
	; Room 5 graphic
	gfxroom5: .incbin "room5.pic"
	gfxroom5_end:
	maproom5: .incbin "room5.map"
	maproom5_end:
	palroom5: .incbin "room5.pal"
	palroom5_end:
	; Room 5 colision map
	maproom5col: .incbin "room5_col.clm"
	maproom5col_end:
	
	; Room 6 graphic
	gfxroom6: .incbin "room6.pic"
	gfxroom6_end:
	maproom6: .incbin "room6.map"
	maproom6_end:
	palroom6: .incbin "room6.pal"
	palroom6_end:
	; Room 6 colision map
	maproom6col: .incbin "room6_col.clm"
	maproom6col_end:
.ends

;sound_accept: .incbin "accept.brr"
;sound_accept_end:

;sound_cancel: .incbin "cancel.brr"
;sound_cancel_end:

;sound_select: .incbin "select.brr"
;sound_select_end:

;.ends
;.section ".rodata5" superfree

;sound_eni_studios: .incbin "enistudios.brr"
;sound_eni_studios_end:

;sound_footstep: .incbin "footstep.brr"
;sound_footstep_end:

;sound_jump: .incbin "jump.brr"
;sound_jump_end:

;sound_attack: .incbin "attack.brr"
;sound_attack_end:

;.ends
;.section ".rodata6" superfree

;sound_hurt: .incbin "hurt.brr"
;sound_hurt_end:

;.ends