; ************************************************************************************************************
; ************************************************************************************************************
;
;												Door opening
;
;	Uses RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

DoorOpen:
	plo 	re 																	; save door position.
	plo 	rf 																	; ready to mask it at rf
	ani 	4 																	; 0 for left, 4 for right.
	bz 		__DOLeftMask
	ldi 	081h 																
__DOLeftMask:																	; 0 for left $81 for right	
	xri 	080h 																; now $80 for left $01 for right
	phi 	re 																	; save in re.H
	ldi 	Buffer/256  														; finish setting up rf
	phi 	rf 
	sex 	rf
__DOMask:
	ghi 	re 																	; get mask
	and 																		; and into screen.
	str 	rf
	str 	rf
	glo 	rf 																	; next line
	adi 	8
	plo 	rf
	shl
	bnf 	__DOMask															; until done half the screen

	sex 	r2 																	; X points to stack.
	glo 	re 																	; get door position
	ani 	4 																	; 0 if left 4 if right
	bz 		__DONotRight
	ldi 	7
__DONotRight:																	; 0 if left 7 if right
	str 	r2 																	; save at TOS.
	glo 	re 																	; XOR with door position.
	xor 																		; so now D is distance in from edge.
	xri 	3 																	; now distance from the middle.
	shl 																		; up four positions per depth.
	shl
	bz 		__DONoAdjust 														; -1 position
	smi 	1
__DONoAdjust:
	shl 																		; multiply by 8 so index into Row
	shl	
	shl
	str 	r2 																	; save at R(X)

	glo 	re 																	; get door position
	adi 	15*8 																; put half way down
	sm 																			; subtract offset

	plo 	rf
	ldi	 	0FFh 																; put a solid bar there.
	str 	rf
	return
	br 		DoorOpen