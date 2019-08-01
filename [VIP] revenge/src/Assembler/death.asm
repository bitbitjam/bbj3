; ************************************************************************************************************
; ************************************************************************************************************
;
;													Death Check
;
; ************************************************************************************************************
; ************************************************************************************************************

DeathCheck:
	lri 	rf,player 															; get player position
	ldn 	rf
	plo 	rf 																	; read the map location
	ldi 	map/256 
	phi 	rf
	ldn 	rf 																	; read the map square
	bz 		__DCExit 															; if zero, exit, not dead

	lri 	r6,RandomNumber 													; erase screen randomly.
	ldi 	00Dh 																; do it roughly 13 x 256 times.
	phi 	r7
Die:
	lri 	re,screen+128 														; set up RE, handle problem that
	ldi 	0 																	; $80 is never produced by the simple
	str 	re 																	; RNG
	recall 	r6 	 																; pick random square
	plo 	re
	recall 	r6 																	; pick random mask
	sex 	r2
	str 	r2
	ldn 	re 																	; get screen, shift, mask, write
	shlc
	and
	str 	re
	dec 	r7 																	; dec counter, loop back if not done
	ghi 	r7
	bnz 	Die
	lri 	r5,DrawCharacter 													; code to draw character
	lri 	rc,screen+8*8+2 													; draw position
	lri 	rb,kills10  														; score
	ldn 	rb 														 			; get score high
	recall 	r5 																	; print it
	dec 	rb
	ldn 	rb 																	; get score low
	recall 	r5 																	; print it.
	ldi 	0
	recall	r5 																	; times 100 :)
	recall 	r5
__DCHalt: 																		; game over
	br 		__DCHalt
__DCExit:
	return
	