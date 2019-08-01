; ************************************************************************************************************
; ************************************************************************************************************
;
;								Repaint whole display. No registers guaranteed
;	
; ************************************************************************************************************
; ************************************************************************************************************

Repaint:
	call 	r5,RepaintDisplayOutline 											; clear screen and draw walls

	lri 	rc,ppVector-1 														; point to player (vector -1)
	ldn 	rc 																	; read player position
	inc 	rc
	str 	rc 																	; save in vector[0]
	inc 	rc 																	; set up vector to point to 1st element

	lri 	r5,DrawPlayerViewAtDepth 											; draw maze at given depth
	ldi 	0 																	; draw at each level
	recall 	r5
	bdf 	__RepaintExit 														; abandon draw on solid wall
	ldi 	1
	recall 	r5
	bdf 	__RepaintExit
	ldi 	2
	recall 	r5
	bdf 	__RepaintExit
	ldi 	3
	recall 	r5
__RepaintExit:

	ldi 	(ppVector & 255)													; fix up the vector pointer to [0]
	plo 	rc
	ldn 	rc 																	; reread the first player position
	dec 	rc 																	; we changed it so copy it from the vector
	str 	rc 																	; update actual player position.

	call 	r5,MirrorDisplay 													; mirror top of display to bottom

	lri 	rc,ppVector 														; point RC to the positional vector.
__RPFindPrincess:
	lda 	rc 																	; get the position to check
	plo 	rd 																	; make RD point to the map entry.
	ldi 	map/256
	phi 	rd 																	
	ldn 	rd 																	; read what's there.
	ani 	7Fh 																; drop bit 7
	bnz 	__RPFoundPrincess 													; if true, then found princess
	ldn 	rd 																	; reload and look at bit 7
	shl
	bdf 	__RPStatus 															; if found a wall don't look further
	glo 	rc 
	xri 	(ppVector+4) & 255
	bnz 	__RPFindPrincess 													; not done 4, try next square.
	br 		__RPStatus

__RPFoundPrincess:
	lri 	rd,DrawSpriteGraphic 												; RD to sprite drawer.
	glo 	rc 																	; calculate offset in vector
	smi 	(ppVector & 255)+1
	bz 		__RPPointBlank 														; at level zero you're dead anyway
	smi  	1
__RPPointBlank:
	shl 																		; x 2, 2 sprites per princess
	recall 	rd
	recall 	rd

__RPStatus:
	call 	r5,UpdateRadar 														; update the radar.
	call 	r5,UpdateCompass
	ldi 	Screen/256 															; not double buffered ?
	xri 	Buffer/256
	bz 		__RepaintNoCopy

	lri 	rf,Screen 															; copy buffer to screen.
	lri 	re,Buffer
	sex 	re
__RepaintCopy:
	ldxa
	str 	rf
	inc 	rf
	ldxa
	str 	rf
	inc 	rf
	glo 	rf
	bnz 	__RepaintCopy	
__RepaintNoCopy:
	return



