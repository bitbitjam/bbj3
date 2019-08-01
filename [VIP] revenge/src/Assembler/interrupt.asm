; ************************************************************************************************************
; ************************************************************************************************************
;
;											1861 Display Routine
;
; ************************************************************************************************************
; ************************************************************************************************************

Return:
	ldxa 																		; restore DF
	shl 
	ldxa 																		; restore D
	ret 																		; restore X,P
Interrupt:
	dec 	r2 																	; [2/2] save return XP on stack 
	sav 																		; [2/4]
	dec 	r2 																	; [2/6] save D on stack
	str 	r2																	; [2/8]
	ldi 	screen/256 															; [2/10] set up R0.1
	phi 	r0 																	; [2/12]
	ldi 	0 																	; [2/14] set up R0.0
	plo 	r0
	nop 																		; pad out cycles till rendering
	nop
	nop
Refresh:
	glo 	r0 																	; do four scan lines for each row
	sex 	r2

	sex 	r2
	dec 	r0
	plo 	r0

	sex 	r2
	dec 	r0
	plo 	r0

	sex 	r2
	dec 	r0
	plo 	r0

	bn1 	Refresh 															; in emulator we never loop back

	dec 	r2 																	; save DF.
	shrc 	
	str 	r2

	lri 	r0,timers 															; point R0 to the timers.
__IRQTimerLoop:
	lda 	r0 																	; read timer value and advance
	bz 		__IRQNextTimer	 													; if zero do next ?
	dec 	r0 																	; if not, decrement the counter.
	smi 	1
	str 	r0
	inc 	r0
__IRQNextTimer:
	glo 	r0 																	; do all the tiners
	bnz 	__IRQTimerLoop
	br 		Return