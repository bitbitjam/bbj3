; ************************************************************************************************************
; ************************************************************************************************************
;
;									Revenge of the Killer Princesses
;									================================
;
;								  Written by Paul Robson June/July 2016
;	
;	  Written for the Netronics ELF but should port to other 1802/1861 devices with sufficient RAM memory.
;	  Main porting issue is the keyboard routine.
;
; ************************************************************************************************************
; ************************************************************************************************************

	include 1802.inc

screen =  	0F00h																; this is the display screen.
buffer = 	0E00h																; this page has the buffer in it
map = 		0D00h 																; this page has the map in it.
stack = 	0CE8h 																; stack top

timers = 	0CFCh 																; 4 timers must end at page top.
speed = 	0CFBh 																; princess speed.
spawnCount = 0CFAh 																; spawning counter
spawnSpeed = 0CF9h 																; additive to spawn counter.

ppvector =  0CF0h																; player position vector.
player = 	0CEFh 																; player offset in map
direction = 0CEEh 																; 0 = right,1 = down, 2 = left, 3 = up
kills10 =   0CEDh 																; dead princesses.
kills01 = 	0CECh

moveTimer = timers 																; first timer controls move/turn.
fireTimer = timers+1 															; second timer controls firing
prinTimer = timers+2 															; third timer controls movement
spawnTimer = timers+3 															; fourth timer controls spawning.

MAZE_Wall = 080h 																; bit 7 indicates wall
MAZE_Open = 000h 																; $00 is open space
MAZE_Princess = 001h 															; $01-$7F is princess.

	ret 																		; 1802 interrupts on. 
	nop
	lri 	r1,Interrupt 														; set interrupt vector
	lri 	r2,Stack 															; set stack address
	lri 	r3,Main 															; main program address
	sep 	r3 																	; go to main routine
Main:
	sex 	r2 																	; turn video on
	inp		1

; ************************************************************************************************************
; ************************************************************************************************************
;
;											Initialisation code
;
; ************************************************************************************************************
; ************************************************************************************************************

	call 	r4,SkillLevel 														; get the skill level
	call 	r4,CreateMaze 														; create the maze
	call 	r4,ResetPlayer 														; reset the player
	lri 	r4,speed  															; dummy speed
	ldi 	60
	str 	r4

Loop:
	call 	r4,SpawnPrincesses 													; spawn princess, possibly.
	call 	r4,MovePrincesses 													; move all the princesses
	call	r4,MovePlayer 														; move player
	call 	r4,Repaint 															; repaint display
	call 	r4,DeathCheck														; check if died
	br 		Loop

	org 	100h

code:
;
;	Block 0
;
	include maze.asm 															; maze creator & RNG ($7B)
	include drawing.asm 														; repaint outline/mirror ($64)
;
;	Block 1
;
	org 	code+100h
	include door.asm 															; door "opening" code. ($3C)
	include player.asm 															; player reset/depth view ($B0)
;
;	Block 2
;
	org	 	code+200h
	include repaint.asm 														; repaint ($8B)
	include sprites.asm 														; sprite drawing ($30)
;
; 	Block 3 
;
	org 	code+300h
	include move.asm 															; player move/fire ($A5)
	include death.asm 															; death check/end ($53)
;
;	Block 4
;
	org 	code+400h
	include radar.asm 															; radar code ($68)
	include keyboard.asm  														; keyboard driver ($14)
	include character.asm 														; character drawer ($25)
	include interrupt.asm														; screen driver ($1E)
;
;	Block 5
;
	org 	code+500h
	include princess.asm 														; princess moving/simple AI code. ($8A)
	include compass.asm 														; compass drawing code ($45)
;
;	Block 6
;
	org 	code+600h
	include spawning.asm 														; princess spawning code ($80)
	include skill.asm 															; get skill level ($2D)

	org 	code+700h
FontData:
	include font.inc 															; minimal 8x8 font.
SpriteData:	
	include graphics.inc 														; all the graphic data

;	TODO: 	
;			Princess redirection code (improvement)
