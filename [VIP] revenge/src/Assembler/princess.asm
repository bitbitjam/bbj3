; ************************************************************************************************************
; ************************************************************************************************************
;
;										Princess Movement
;
; ************************************************************************************************************
; ************************************************************************************************************

;	Maze
;
;	Bit 7 		set for solid wall
;	Bit 6 		Unused
;	Bit 5 		Moves left (Bit 2)
;	Bit 4 		Moves left (Bit 1)
;	Bit 3 		Moves left (Bit 0)
;	Bit 2 		Current Direction (High)
;	Bit 1 		Current Direction (Low)
;	Bit 0 		Set for princess.
;
; ************************************************************************************************************
;
;						Check if move time and if so move all princesses
;
; ************************************************************************************************************

MovePrincesses:
	lri 		rf,speed 														; read the princess speed into RB.0
	ldn 		rf
	plo 		rb
	ldi 		(player & 255)													; read player position into RB.1
	plo 		rf
	ldn 		rf
	phi 		rb
	ldi 		(prinTimer & 255)												; point RF to the princess timer
	plo 		rf
	ldn 		rf
	bnz			__MVExit 														; if non-zero don't move princesses
	glo 		rb 																; reset the princess timer
	str 		rf

	ldi 		map/256 														; RC points to map, RD to buffer
	phi 		rc
	ldi 		buffer/256
	phi 		rd
	ldi 		0
	plo 		rc
	plo 		rd
__MVCopyBuffer:																	; copy map to buffer.
	ldn 		rc
	str 		rd
	inc 		rc
	inc 		rd
	glo 		rc
	bnz 		__MVCopyBuffer

__MVSearchPrincesses: 															; now work backwards looking for princesses
	dec 		rc
	dec 		rd
	ldn 		rd  															; look at the map copy in the buffer.
	shl 																		; lose bit 7
	bz   		__MVNoPrincess 													; if not found , skip to next

	ldn 		rd 																; get the princess data
	ani 		00111000b 														; isolate the move count bits
	bz 			__MVNewDirection 												; if zero, we want a new direction
	call 		r5,MoveOnePrincess												; if not, move princess
	br 			__MVNoPrincess
__MVNewDirection:
	call 		r5,PrincessAI 													; find a new direction	
__MVNoPrincess:
	glo 		rc
	bnz 		__MVSearchPrincesses

__MVExit:
	return

; ************************************************************************************************************
;
;			Move princess. RC points to target map. RE.1 is player position. RC.1 is princess position
;
; preserve RB,RC,RD
; ************************************************************************************************************

MoveOnePrincess:
	ldn 	rc 																	; get princess data
	ani 	038h 																; check if move counter zero
	bz 		__MOExit 															; it shouldn't be !
	ldn 	rc 																	; get bits 2 and 1, the direction bits
	ani 	00000110b
	shr 																		; shift into bits 0 & 1
	adi 	PlayerDirectionTable & 255 											; point RF into player direction table
	plo 	rf
	ldi 	PlayerDirectionTable / 256
	phi 	rf
	sex 	rf 																	; X now points to offset.
	glo 	rc 																	; get position.
	add 																		; calculate new position
	plo 	rf 																	; make RF point to the target map.
	ghi 	rc
	phi 	rf
	ldn 	rf 																	; read what's at the new square
	bnz 	__MOCantMove 														; something there, can't move.
;
;	Move princess.
;
	ldn 	rc 																	; get princess data
	smi 	8 																	; reduce move counter by one.
	str 	rf 																	; write in new princess position
	ldi 	0
	str 	rc 																	; clear old position.

;	sex 	r2 																	; dump princess position on LEDs
;	dec 	r2
;	glo 	rc
;	str 	r2
;	out 	4

	br 		__MOExit 															; and exit
;
;	Can't move
;
__MOCantMove:
	ldn 	rc 																	; clear the move counter so it moves
	ani 	11000111b 															; next time
	str 	rc
__MOExit:
	return

; ************************************************************************************************************
;
;							  		Princess AI - Random Movement
;
; ************************************************************************************************************

PrincessAI:
	call 	r6,RandomNumber														; get a random number
	ani 	03Fh 																; clear bits 6 and 7
	ori 	1 																	; set bit 0
	str 	rc
	inc 	r2
__PAExit:
	return
	