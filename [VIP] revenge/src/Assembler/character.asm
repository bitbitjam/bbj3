; ************************************************************************************************************
; ************************************************************************************************************
;
;										Plot character D at RC
;
;	uses RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

DrawCharacter:
	sex		r2 																	; save character
	dec 	r2
	str 	r2
	shl 																		; x 8
	shl
	shl
	adi 	(FontData & 255) 													; add to font data
	plo 	rf
	ldi 	(FontData / 256)
	adci 	0
	phi 	rf
	ldi 	8 																	; counter in RE.0
	plo 	re
__DCCopy:
	lda 	rf 																	; copy pixel data
	str 	rc
	glo	 	rc 																	; next line down.
	adi 	8
	plo 	rc
	dec 	re 																	; do 8 times
	glo 	re
	bnz		__DCCopy
	glo 	rc 																	; fix up RC to point to next ch.
	smi 	63
	plo 	rc
	ldxa 																		; restore
	return
	br 		DrawCharacter
