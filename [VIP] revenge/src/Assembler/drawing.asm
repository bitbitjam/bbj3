; ************************************************************************************************************
; ************************************************************************************************************
;
;						 	Draw the Outline Frame (with no doors) - top half only.
;
;	Uses RC,RD,RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

RepaintDisplayOutline:
	ldi 	Buffer/256 															; rc points to display position.
	phi 	rc 																	; so does rd as we're going to clear it
	phi 	rd 																	; the top half of the screen
	ldi 	0
	plo 	rc
	plo 	rd
_RDClear:
	glo 	rc 																	; rc.0 is zero
	str 	rd 																	; fill display RAM with it.
	inc 	rd
	glo 	rd
	shl 																		; only do it half way as we copy
	bnf 	_RDClear 															; the bottom half.

; ************************************************************************************************************
;									    Come back here to reset the masks
; ************************************************************************************************************

_RDResetMasks:
	ldi 	0C0h 																; rf.0 is 11000000 (left write)
	plo 	rf
	ldi 	3 																	; rf.1 is 00000011 (right write)
	phi 	rf

; ************************************************************************************************************
;				Main repaint loop. rc points to the line position. rf.0 left mask rf.1 right mask
; ************************************************************************************************************

_RDLoop:
	ghi		rc 																	; copy rc.1 to rd.1 and re.1
	phi 	rd 																	
	phi 	re
	glo 	rc 																	; are there no solid blocks yet ?
	ani 	7
	bz 		_RDNoSolid

; ************************************************************************************************************
;					This draws solid blocks - fill in a whole byte at a time, on left and right
; ************************************************************************************************************

	glo 	rc 																	; rd.0 will point to left bit
	plo 	rd
	xri 	7																	; rd.1 will point to right bit
	plo 	re																	
	dec 	rd

_RDDrawByteBlocks:
	ldi 	0FFh 																; write solid block on left.
	str 	rd
	str 	re
	dec 	rd 																	; move left left and right right
	inc 	re
	glo 	re 																	; if right hasn't wrapped around
	ani 	7
	bnz 	_RDDrawByteBlocks
_RDNoSolid:

; ************************************************************************************************************
;						This writes out the current masks and goes to the next line.
; ************************************************************************************************************

	glo 	rc 																	; set rd and re to point to write
	plo 	rd
	xri 	7
	plo 	re

	glo 	rc 																	; point rc to the next line.
	adi 	8
	plo 	rc

	glo 	rf																	; write left mask
	str 	rd
	shr 																		; update the left mask.
	shr	
	ori 	0C0h
	plo 	rf

	ghi 	rf 																	; write right mask
	str 	re
	shl 																		; update the right mask.
	shl 
	ori 	3
	phi	 	rf

	bnf 	_RDLoop
	inc 	rc 																	; step out 1.
	glo 	rc 																	; if not half way down loop back.
	shlc
	bnf 	_RDResetMasks
	return

; ************************************************************************************************************
; ************************************************************************************************************
;
;									Copy top half to bottom half upside down
;
;	Uses RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

MirrorDisplay:	
	lri 	re,Buffer 															; re points to screen top
_MDLoop:
	glo 	re 																	; set up bottom pointer rf
	xri 	0F8h
	plo 	rf	
	ghi	 	re
	phi 	rf
	lda 	re 																	; copy data bumping rc
	str 	rf
	inc 	rf
	glo 	re
	shl 	
	bnf 	_MDLoop
	return


		