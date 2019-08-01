; ************************************************************************************************************
; ************************************************************************************************************
;
;												Reset the Player
;
;	use RF.
; ************************************************************************************************************
; ************************************************************************************************************

ResetPlayer:
	lri 	rf,Player 															; initialise pointer, use RF as index
	sex 	rf
	ldi 	7*16+7																; player at (7,7)
	stxd
	ldi 	2 																	; direction 2
	stxd
	ldi 	0 	
	stxd 																		; kills 0 (2 digits)
	stxd 
	ldi 	0FFh 																; point to top of timers
	plo 	rf
	ldi 	0h 																	; clear the four timers
	stxd
	stxd
	stxd
	stxd
	return

; ************************************************************************************************************
; ************************************************************************************************************
;
;						Get Player Position as a result of a move in current direction +/- n
;										D is position RF points to the map
;
;	use RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

GetPlayerNextCurrent:
	ldi 	0 																	; set offset to 0
GetPlayerNextOffset:
	sex 	r2
	str 	r2
	lri 	rf,Direction 														; load player direction.
	ldn 	rf
	add 	 																	; get into D + offset
	ani 	3 																	; force into a position.
	adi 	PlayerDirectionTable & 255 											; get an address in the table
	plo 	re 																	; point RE to that value.
	ldi 	PlayerDirectionTable / 256
	phi 	re
	lri 	rf,Player 															; point RF to the position.
	sex 	re 																	; R(X) points to the direction table
	ldn 	rf 																	; read position
	add 																		; add direction and exit.
	plo 	rf 																	; put in RF
	ldi 	Map/256 	
	phi 	rf 																	; point RF to the map entry
	glo 	rf 																	; restore D
	return
	br 		GetPlayerNextOffset 												; re-entrant into next offset.

; ************************************************************************************************************
; ************************************************************************************************************
;
;		Draw player view at depth D (0 = outermost, 3 = innermost). Returns DF = 0 if can move forward.
;		D returned unchanged. Store new position at (RC) and increment RC.
;		  
;	Uses RA,RB,RD GetPlayerNextOffset (RE/RF) and DoorOpen(RE/RF). 
; ************************************************************************************************************
; ************************************************************************************************************

DrawPlayerViewAtDepth:
	phi 	ra 																	; save the depth in ra.1

	lri 	rd,GetPlayerNextOffset												; call to identify left/right
	ldi 	-1 																	; can we look left ?
	recall 	rd    
	ldn 	rf 																	; get what's there into rb.0
	plo 	rb
	ldi 	1 																	; can we look right ?
	recall 	rd
	ldn 	rf 																	; get what's there into rb.1
	phi 	rb
	ldi 	0 																	; look ahead
	recall 	rd
	str 	rc 																	; save position at (RC)
	ldn 	rf 																	; get what's there into ra.0
	plo 	ra 	

	lri 	rf,Player 															; update the player position from ra.1
	ldn 	rc 																	; read read position and update it
	str 	rf
	inc 	rc 																	; increment position vector pointer.

	lri 	rd,DoorOpen 														; prepare to show open door.
	glo 	rb 																	; wall on left side ?
	shl
	bdf 	__DPVNoLeftWall
	ghi 	ra 																	; open depth up
	recall 	rd 
__DPVNoLeftWall:
	ghi 	rb 																	; wall on right side ?
	shl
	bdf 	__DPVNoRightWall
	ghi 	ra 																	; open 7-depth up.
	xri 	7
	recall 	rd
__DPVNoRightWall:
	glo 	ra 																	; get what's in front.
	shl 
	bnf 	__DPVExit 															; if clear exit with DF = 0

	ghi 	ra 																	; calculate start position
	adi 	1 																	; move in one
	sex 	r2 																	; depth * 8 + depth
	str 	r2
	shl 																		; *8 * 4
	shl
	shl
	shl
	shl
	add 	 																	; *9
	plo 	rf 																	; set RF to point to first block. 
	ldi 	Buffer/256
	phi 	rf
	ldi 	0FFh 																; set writing value to $AA
	plo 	re
__DPVDrawWall:
	ghi 	ra 																	; 0123 for depths
	xri 	3 																	; 3210 for depths
	shl 																		; 6420 for depths
	bz 		__DPVExitWall 														; if nothing to draw skip.
	plo 	rb
	glo 	rf 																	; save the start position of row.
	phi 	re	
__DPVDrawLine:
	glo 	re 																	; copy one wall piece over.
	str 	rf
	inc 	rf	
	dec 	rb 																	; do required number of times
	glo 	rb
	bnz 	__DPVDrawLine
	plo 	re 																	; draw spaces from here on.
	ghi 	re 																	; get start of line RE.1
	adi 	8
	plo 	rf 																	; point RF.0 one line down.
	shl
	bnf 	__DPVDrawWall 														; go back if not reached half way.
__DPVExitWall:
	ldi 	0FFh 																; set DF.
	shl
__DPVExit:
	ghi 	ra 																	; restore D.
	return
	br 		DrawPlayerViewAtDepth

; ************************************************************************************************************
;
;										Direction to Offset table
;
; ************************************************************************************************************

PlayerDirectionTable:
	db 		1,16,-1,-16 														; direction -> offset table.
