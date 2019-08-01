; ************************************************************************************************************
; ************************************************************************************************************
;
;											Movement code
;
; ************************************************************************************************************
; ************************************************************************************************************

MOVE_TurnTime = 50 																; frames per turn
MOVE_MoveTime = 50 																; frames per move
MOVE_FireTime = 180 															; frames between firing

MovePlayer:
	lri 	rd,moveTimer 														; point RD to move timer
	lri 	rc,direction 														; point RC to direction.
	call 	r5,ScanKeyboard 													; read keyboard.
	plo 	rb 																	; save in RB.0

	ldn 	rd 																	; read move timer.
	bnz 	__MPTimer1 															; if non-zero we can't move

	glo 	rb 																	; get key press.
	xri 	KEY_Left 															; if left, go to TURN with zero.
	bz 		__MPTurn
	xri 	KEY_Left ! KEY_Right 												; if not right, go to try MOVE
	bnz 	__MPTryMove
	ldi 	2 																	; go into TURN with 2
__MPTurn:
	smi 	1 																	; make offset -1 and 1
	sex 	rc 																	; add to direction 
	add 
	str 	rc 																	; write direction back.
	ldi 	MOVE_TurnTime 														; reset the timer
	str 	rd 
	br 		__MPTryMove

__MPTryMove:
	glo 	rb 																	; get key press
	xri 	Key_Forward 														; check forward.
	bnz 	__MPTimer1

	ldi 	MOVE_MoveTime 														; reset the timer
	str 	rd 
	lri 	rc,ppvector+1 														; get the next position forward
	ldn 	rc 																	; via RC
	plo 	re 																	; save in RE.0
	ldi 	map/256 															; point RE to that map entry
	phi 	re
	ldn 	re 																	; read the map
	shl 																		; check bit 7 (wall bit)
	bdf 	__MPTimer1 															; if a solid wall then can't move.
	ldi 	(player & 255) 														; make rc point to the position
	plo 	rc
	glo 	re 																	; get the new position
	str 	rc 																	; save it.

__MPTimer1: 																
	inc 	rd 																	; point to 2nd timer, fire timer
	ldn 	rd  																; if that is non zero can't fire.
	bnz 	__MPExit 									
	glo 	rb 																	; check if fire pressed.
	xri 	Key_Fire
	bnz 	__MPExit
	ldi 	MOVE_FireTime 														; reset that timer.
	str 	rd 
;
;	Shooting effect
;
	ldi 	0 																	; use program code as random data
	plo 	rf 																	; drawn in the screen centre to
	phi 	rf 																	; give a blur effect
__MPEffect1:
	lri 	re,Screen+8*8+3 													; middle left
__MPEffect2: 
	lda 	rf 																	; copy byte from RF into two bytes
	str 	re
	inc 	re
	str 	re
	glo 	re 																	; next line down
	adi 	7
	plo 	re
	xri 	24*8+3 																; reached bottom
	bnz 	__MPEffect2
	ghi 	rf 																	; if not done whole effect go back.
	xri 	04h
	bnz 	__MPEffect1
;
;	Look for a princess to kill
;
	lri 	re,ppVector 														; point RE to the player position vector
	ldi 	map/256 															; RF is pointer to the map
	phi 	rf
__MPFindPrincess:	
	lda 	re 																	; get position + advance
	plo 	rf 																	; rf now points into map
	ldn 	rf 																	; read map element
	shl 																		; check bit 7 (wall)
	bdf 	__MPExit 															; wall present then exit.	
	bnz 	__MPKill 															; if non zero kill princess !
	glo 	re  																; see if done the whole vector
	xri 	(ppVector+4) & 255
	bnz 	__MPFindPrincess
__MPExit:
	return
;
;	Kill princess and bump score
;
__MPKill:
	ldi 	00 																	; write zero to princess position
	str 	rf
	ldi 	kills01 & 255 														; point RE to kill count
	plo 	re
	ldn 	re 		 															; bump score
	adi 	1
	str 	re
	xri 	10 																	; exit if not 10 yet.
	bnz 	__MPExit
	str 	re 																	; zero ones
	inc 	re 																	; point to tens
	ldn 	re 																	; bump 10s
	adi 	1
	str 	re
	xri 	10 																	; reached 99....
	bnz 	__MPexit
	str 	re 																	; zero tens, wraps around :)
	br 		__MPexit
