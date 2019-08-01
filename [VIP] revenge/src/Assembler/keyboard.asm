; ************************************************************************************************************
; ************************************************************************************************************
;
;						Keyboard Scanner - returns Key_xxxx other values are ignored
;
;	Uses RE,RF
; ************************************************************************************************************
; ************************************************************************************************************

Key_Forward = 05h 																; keyboard allocation 
Key_Left = 04h 																	; these keys are chosen for a PC
Key_Right = 06h 																; keyboard emulation not a Elf
Key_Fire = 10h  									

ScanKeyboard:
	sex 	r2
	dec 	r2
	inp 	4
	inc 	r2
	ani 	0Fh																	; return value in RF.
	bn4 	__SKExit
	ldi 	Key_Fire
__SKExit:
	return

