; ************************************************************************************************************
; ************************************************************************************************************
;
;												Spawn new princesses.
;
; ************************************************************************************************************
; ************************************************************************************************************

SpawnPrincesses:
	dec 	r2 																	; make room on stack
	lri 	rf,spawnTimer														; spawning timer timed out ?
	ldn 	rf
	bnz 	__SPExit 															; exit if not.
	ldi 	60 																	; causes timer to operate at 1Hz
	str 	rf

	ldi 	spawnSpeed & 255 													; point RF to spawn speed
	plo 	rf
	ldn 	rf 																	; read it
	inc 	rf 																	; point RF to spawn counter
	sex 	rf
	add 
	str 	rf 																	; add to spawn counter and update
	bnf 	__SPExit 															; spawn on DF set.

__SPGetRandom:
	call 	r6,RandomNumber														; get random number, save in RD.0
	plo 	rd
	ani 	7
	bz 		__SPGetRandom 														; we want lower 3 bits to be 1-7
	smi 	1 																	; it's now 0-6
	str 	r2 																	; save lower 3 bits on TOS.
	sex 	r2 																	; X access it.
	glo 	rd 																	; get the random number
	ani 	40h 																; bit 6 defines horizontal or vertical.
	bz 		__SPVertical
;
;	A horizontal one.
;
	glo 	rd 																	; get bit 7
	ani 	80h
	bz 		__SPHNotBottom
	ldi 	0D0h
__SPHNotBottom:																	; D is 00 or D0 at this point.
	adi 	11h 																; D is now 11 or E1.
	add 																		; D now is 11 or E1 + (0-6) x 2
	add 	
	br 		__SPTrySpawn
;
;	A vertical one.
;
__SPVertical:
	ldn 	r2 																	; multiply 1-6 by 32
	shl
	shl
	shl
	shl
	shl
	str 	r2
	glo 	rd 																	; get bit 7
	ani 	80h
	bz 		__SPHNotRight
	ldi 	0Dh
__SPHNotRight:																	; D is now 00 or 0D
	adi 	11h 																; now 11 or 1E
	add 																		; add the 32 offset.
;
;	Try to spawn a princess.
;																	
__SPTrySpawn:	
	plo 	rf 																	; make map reference in RF
	ldi 	map/256 														
	phi 	rf
	ldn 	rf 																	; read it.
	bnz 	__SPSpawnFail 														; if non zero spawning has failed.
;
;	Check |dx| for player is > 4. This will cause a skew in spawning.
;
	lri 	re,player 															; get player position
	ldn 	re
	ani 	15 																	; get X
	str 	r2 																	; save on TOS
	glo 	rf 																	; get spawn position
	ani 	15 																	; spawn X
	sd  																		; playerX - spawnX
	bdf 	__SPAbs
	sdi 	0
__SPAbs:																		; |playerX - spawnX|
	ani 	0Ch 																; if |dx| < 4 then fail
	bz 		__SPSpawnFail 														; stops spawning too near.

	ldi 	01h 																; set to 1.
	str 	rf

	glo 	rf 																	; show spawns on LED.
	dec 	r2
	str 	r2
	sex 	r2
	out		4

	br 		__SPExit

__SPSpawnFail:	
	lri 	rf,spawnCount 														; set spawn counter to refire next time.
	ldi 	0FFh
	str 	rf
__SPExit:
	inc 	r2 																	; restore off stack.
	return

