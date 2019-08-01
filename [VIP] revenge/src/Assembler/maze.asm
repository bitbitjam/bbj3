; ************************************************************************************************************
; ************************************************************************************************************
;
;												Maze Creator
;
;	Uses RB,RC,RD,RF.
; ************************************************************************************************************
; ************************************************************************************************************

CreateMaze:
	sex 	r2
	lri 	rc,map 																; point RC to the map.
__CMFill:
	ldi 	MAZE_Wall 													 		; fill the map with solid walls.
	str 	rc
	inc 	rc
	glo 	rc
	bnz 	__CMFill
	lri 	rc,map+16+1 														; row 1 column 1
	lri 	rb,RandomNumber 													; r5 = random subroutine (runs in R4)
__CMGenerate:
	glo 	rc 																	; do not overright right hand wall
	ani 	0Fh 
	xri 	0Fh
	bz 		__CMNext

	glo 	rc  																; makes the checkerboard pattern.
	ani	 	011h
	xri 	011h 																
	bnz 	__CMNext
	ldi 	MAZE_Open
	str 	rc 																	; write 00 (maze open) here.

	recall 	rb																	; random number
	ani 	15
	smi 	11 																	; check mod 16 < 11
	bdf 	__CMNotRight
	inc 	rc 																	; if so open square to right.
	ldi 	MAZE_Open
	str 	rc
	dec 	rc
__CMNotRight:

	recall 	rb 																	; random number
	ani 	15
	smi 	11 			 														; check mod 16 < 11
	bdf 	__CMNotDown
	ghi 	rc 																	; open square down - point RD to it
	phi 	rd
	glo 	rc
	adi 	16
	plo 	rd
	ldi 	MAZE_Open 															; open that square
	str 	rd
__CMNotDown:

__CMNext:
	inc 	rc 																	; next
	glo 	rc
	xri 	0DFh 																; reached bottom right ?
	bnz 	__CMGenerate
	return

; ************************************************************************************************************
; ************************************************************************************************************
;
;							Random Number Generator - same as class LFSR in gen.py
;
;	uses RF. 
; ************************************************************************************************************
; ************************************************************************************************************

RandomNumber:
	lri 	rf,__RNHighM1+1
__RNHighM1:
	ldi 	0ACh																; get seeded value
	shr 																		; shift it right
	str 	rf 																	; write it back
	ldi 	(__RNLowM1+1) & 0FFh 												; change pointer
	plo 	rf
__RNLowM1:
	ldi 	0E1h 																; get upper seeded value
	shrc  																		; rotate it right and in
	str 	rf 																	; write it back.
	sex 	r2																	; save at TOS
	str 	r2
	bnf  	__RNNoToggle 														; if bit shifted out set

	ldi 	(__RNHighM1+1) & 0FFh												; exor the high bit with $B4
	plo 	rf
	ldn 	rf
	xri 	0B4h
	str 	rf
__RNNoToggle:
	ldn 	r2 																	; read TOS.
	shl 																		; put bit 7 into DF
	ldi 	0 																	; add 0 + (R2) + DF 
	adc 	
	return 	
	br 		RandomNumber 														; is re-entrant.
