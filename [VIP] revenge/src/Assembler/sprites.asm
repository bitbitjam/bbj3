; ************************************************************************************************************
; ************************************************************************************************************
;
;												Draw sprite graphic D
;
;	Uses RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

DrawSpriteGraphic:
	dec		r2 																	; save at R2
	str 	r2
	shl 																		; double the sprite number
	adi 	SpriteData & 255 													; add to sprite address, put in RF
	plo 	rf
	ldi 	SpriteData / 256
	adci 	0
	phi 	rf
	lda 	rf 																	; read address into RE.
	phi 	re
	lda 	rf
	plo 	re 

	lda 	re 																	; read the start drawing address
	plo 	rf 																	; put into RF.
	ldi 	buffer/256 															; make into screen address
	phi 	rf
	sex 	re 																	; RX is data

__DSGLoop:
	ldn 	re 																	; read mask.
	xri 	0FFh 																; if $FF then finished
	bz 		__DSGFinished
	ldn 	rf 																	; read screen
	and 																		; and with mask
	inc 	re
	or 																			; or with data
	str 	rf 																	; write out.
	inc 	re 																	; next down
	glo 	rf 																	 
	adi 	8
	plo 	rf
	br 		__DSGLoop

__DSGFinished:
	lda 	r2
	adi 	1
	return
	br 		DrawSpriteGraphic

; ************************************************************************************************************
;
;													Clear Screen
;
; ************************************************************************************************************

ClearScreen:
	lri 	rf,Screen
__DSGClear:
	ldi 	0
	str 	rf
	inc 	rf
	glo 	rf
	bnz 	__DSGClear
	return
