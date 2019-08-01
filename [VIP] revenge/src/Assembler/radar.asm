; ************************************************************************************************************
; ************************************************************************************************************
;
;													Radar Code
;
; ************************************************************************************************************
; ************************************************************************************************************

; ************************************************************************************************************
; ************************************************************************************************************
;
;							Calculate minimum distance of nearest princess
;
; ************************************************************************************************************
; ************************************************************************************************************

UpdateRadar:
	dec 	r2 																	; make a spot on the stack
	sex 	r2

	lri 	rf,player 															; read player position into RF.1
	ldn 	rf
	phi 	rf
	ldi 	12 																	; best distance in RF.0
	plo 	rf
	lri 	re,map 																; RE points to map.
__RALoop:
	ldn 	re 																	; read and advance
	ani 	7Fh 																; is there a princess here
	bz 		__RANext 															; no, go to next

	glo 	re 																	; get princess X
	ani 	0Fh
	str 	r2
	ghi 	rf 																	; subtract player X
	ani 	0Fh
	sd
	bdf 	__RANotMinusX  														; calculate |dx|
	sdi 	0
__RANotMinusX:
	phi 	rd 																	; save in RD

	glo 	re 																	; get princess Y
	shr
	shr
	shr
	shr
	str 	r2
	ghi 	rf 																	; subtract princess Y
	shr
	shr
	shr
	shr
	sd 
	bdf 	__RANotMinusY 														; calculate |dy|
	sdi 	0
__RANotMinusY:
	str 	r2 																	; calculate |dx|+|dy|
	ghi 	rd
	add 	
	str 	r2
	glo 	rf 																	; calculate best so far - sum
	sm 
	bnf   	__RANext 															; not best to date
	ldn 	r2																	; get sum back
	plo 	rf 																	; its the new best score.
__RANext:
	inc 	re 																	; next square
	glo		re 																	; go back if not done all princesses.
	bnz 	__RALoop

	;	now RF.0 is the distance from the nearest princess, maximum of 10.

	glo 	rf 																	; get RF (0-10)
	sdi 	12 																	; this is the number of half bars to draw.
	plo 	rf

	lri 	re,buffer+8+1

__RADrawMarker: 																; do in blocks of 8.
	glo 	rf
	ani 	0FEh
	bz 		__RAEndSolid
	dec 	rf
	dec 	rf
	ldi 	0AAh
	str 	re
	inc 	re
	br 		__RADrawMarker

__RAEndSolid:
	glo 	rf
	bz 		__RAExit
	ldi 	0A0h
	str 	re

__RAExit:
	inc 	r2 																	; dump work byte from stack.
	return

	