; ************************************************************************************************************
; ************************************************************************************************************
;
;												1802 Generic Routines
;
; ************************************************************************************************************
; ************************************************************************************************************

	cpu 	1802

r0 = 0 																			; register names
r1 = 1
r2 = 2
r3 = 3
r4 = 4
r5 = 5
r6 = 6
r7 = 7
r8 = 8
r9 = 9 						
ra = 10
rb = 11 																		; stops us using RB accidentally
rc = 12
rd = 13
re = 14
rf = 15

lri Macro 	reg,address 														; load constant into 16 bit reg
	ldi 	(address)/256
	phi 	reg
	ldi 	(address)&255
	plo 	reg
	endm

call Macro 	reg,address 														; call routine via mark.
	lri 	reg,address
	recall 	reg
	endm

recall Macro reg 																; recall (re-entrant macro)
	mark
	sep 	reg
	dec 	r2
	endm

return Macro 																	; return from routine
	sex 	r2
	inc 	r2
	ret
	endm

