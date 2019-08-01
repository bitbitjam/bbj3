; ************************************************************************************************************
; ************************************************************************************************************
;
;											Get skill level and set up.
;
; ************************************************************************************************************
; ************************************************************************************************************

SkillLevel:
	call 	r5,ClearScreen
	lri 	rc,screen+27*8
	lri 	rd,__Logo
__SLLogo:
	lda 	rd
	str 	rc
	inc 	rc
	glo 	rc
	bnz 	__SLLogo

	lri 	r6,DrawCharacter 													; code to draw character
	lri 	rc,screen+8*12+3 													; draw position
	ldi 	5
	recall 	r6
	ldi 	10
	recall 	r6
	sex 	r2
__SLGet:
	call 	r5,ScanKeyboard														; get keyboard
	ani 	0Fh
	bz 		__SLGet 															; needs to be >0
	plo 	re
	smi 	10 																	; and <10
	bdf 	__SLGet

	lri 	rf,spawnSpeed
	glo 	re 																	; get skill level
	shl
	shl
	shl 																		; x 8
	sdi 	80 																	; 80-skill x 8
																				; 1 = 72 (3s) 9 = 8 (32s)
	str 	rf
	inc 	rf
	ldi 	080h 																; first one part way through.
	str 	rf
	return

__Logo:
	db 	000h,000h,002h,099h,076h,05Dh,0C9h,0B6h
	db 	000h,000h,007h,0D5h,025h,048h,055h,051h
	db 	000h,000h,002h,099h,026h,048h,05Dh,012h
	db 	000h,000h,007h,0D5h,025h,049h,055h,011h
	db 	000h,000h,002h,099h,026h,048h,095h,016h