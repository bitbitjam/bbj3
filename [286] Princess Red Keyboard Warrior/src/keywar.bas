'Princess Red Keyboard Warrior (c) 2016 demiO2
'This game is shareware.  Please feel free to distribute.
'You can also modify the code if you wish, however it may break it. :)
'This may be an example of very sloppy programming, but I am an amateur
'and this is my first graphical game for Qbasic, so don't judge.
'Just enjoy.!!!!  There are some Easter Eggs. Pressing O and P
'in the overworld will play around with the palette and colors.
'Enjoy.
'If you like it tell me on my youTube Channel: MontieMongoose
'
'
'
'


CLS
difficulty = 1
SCREEN 1
DIM SHARED erased(16)
DIM word$(30)
DIM SHARED sprred1(16)
DIM SHARED sprred2(16)
DIM SHARED sprdragon(16)
DIM SHARED sprtree1(16)
DIM SHARED sprtree2(16)
DIM SHARED sprmountain(16)
DIM SHARED sprredbrick(16)
DIM SHARED sprcastleleft(16)
DIM SHARED sprcastleright(16)
DIM SHARED sprcastledoor(16)
DIM SHARED sprcastlewall(16)
DIM SHARED sprswordleft(16)
DIM SHARED sprshield(16)
DIM SHARED sprwolf(16)
DIM SHARED sprgoblinright(16)
DIM SHARED sprgoblinleft(16)
DIM SHARED sprswordright(16)
DIM SHARED sprskull(16)
DIM SHARED sprhut(16)
DIM SHARED sprwater(16)
DIM SHARED sprapple(16)
DIM SHARED sprknight(16)
DIM SHARED sprking1(16)
DIM SHARED sprking2(16)
DIM SHARED sprheart(16)
DIM SHARED sprgrass(16)
DIM SHARED sprhills(16)
DIM SHARED sprsand(16)
DIM SHARED sprmushroom(16)
DIM SHARED sprflower(16)
DIM SHARED sprmermah1(16)
DIM SHARED sprmermah2(16)
DIM SHARED sprdiamond(16)
DIM SHARED sprkey(16)
DIM SHARED sprlock(16)
DIM SHARED map1(15, 12)
DIM SHARED map2(15, 12)
DIM SHARED map3(15, 12)
DIM SHARED map4(15, 12)
DIM SHARED map5(15, 12)
DIM SHARED map6(15, 12)
DIM SHARED map7(15, 12)
DIM SHARED map8(15, 12)
DIM SHARED map9(15, 12)
DIM SHARED map10(15, 12)
DIM SHARED map11(15, 12)
TYPE playertype
    x AS INTEGER
    y AS INTEGER
    health AS INTEGER
    attack AS INTEGER
    defense AS INTEGER
    tx AS INTEGER
    ty AS INTEGER
    nx AS INTEGER
    ny AS INTEGER
END TYPE
DIM you AS playertype
you.x = 80
you.y = 80
you.tx = 6
you.ty = 6

difficulty = 1
LOCATE 10, 16: PRINT "LOADING....."




GOSUB subgetpic
GET (1, 1)-(16, 16), sprred1
GOSUB subgetpic
GET (1, 1)-(16, 16), sprred2
GOSUB subgetpic
GET (1, 1)-(16, 16), sprdragon
GOSUB subgetpic
GET (1, 1)-(16, 16), sprtree1
GOSUB subgetpic
GET (1, 1)-(16, 16), sprtree2
GOSUB subgetpic
GET (1, 1)-(16, 16), sprmountain
GOSUB subgetpic
GET (1, 1)-(16, 16), sprredbrick
GOSUB subgetpic
GET (1, 1)-(16, 16), sprcastleleft
GOSUB subgetpic
GET (1, 1)-(16, 16), sprcastleright
GOSUB subgetpic
GET (1, 1)-(16, 16), sprcastledoor
GOSUB subgetpic
GET (1, 1)-(16, 16), sprcastlewall
GOSUB subgetpic
GET (1, 1)-(16, 16), sprswordleft
GOSUB subgetpic
GET (1, 1)-(16, 16), sprshield
GOSUB subgetpic
GET (1, 1)-(16, 16), sprwolf
GOSUB subgetpic
GET (1, 1)-(16, 16), sprgoblinright
GOSUB subgetpic
GET (1, 1)-(16, 16), sprgoblinleft
GOSUB subgetpic
GET (1, 1)-(16, 16), sprswordright
GOSUB subgetpic
GET (1, 1)-(16, 16), sprskull
GOSUB subgetpic
GET (1, 1)-(16, 16), sprhut
GOSUB subgetpic
GET (1, 1)-(16, 16), sprwater
GOSUB subgetpic
GET (1, 1)-(16, 16), sprapple
GOSUB subgetpic
GET (1, 1)-(16, 16), sprknight
GOSUB subgetpic
GET (1, 1)-(16, 16), sprking1
GOSUB subgetpic
GET (1, 1)-(16, 16), sprking2
GOSUB subgetpic
GET (1, 1)-(16, 16), sprheart
GOSUB subgetpic
GET (1, 1)-(16, 16), sprgrass
GOSUB subgetpic
GET (1, 1)-(16, 16), sprhills
GOSUB subgetpic
GET (1, 1)-(16, 16), sprsand
GOSUB subgetpic
GET (1, 1)-(16, 16), sprmushroom
GOSUB subgetpic
GET (1, 1)-(16, 16), sprflower
GOSUB subgetpic
GET (1, 1)-(16, 16), sprmermah1
GOSUB subgetpic
GET (1, 1)-(16, 16), sprmermah2
GOSUB subgetpic
GET (1, 1)-(16, 16), sprdiamond
GOSUB subgetpic
GET (1, 1)-(16, 16), sprkey
GOSUB subgetpic
GET (1, 1)-(16, 16), sprlock

CLS
GET (1, 1)-(16, 16), erased
'GOSUB getmap
'FOR x = 1 TO 15
'    FOR y = 1 TO 12
'    READ a$
'map1$(x, y) = a$
'    NEXT y
'NEXT x

' GOTO final
RANDOMIZE TIMER
begin:
Apple = 0
flower = 0
mushroom = 0
diamond = 0
key1 = 0
lock1 = 0
alive = 1
wordspeed = .2
SCREEN 1
room = 1
finalmatch = 0
CLS
anitimer = TIMER
'PUT (100, 100), sprred1
redframe = 0
'DO
' LOCATE 1, 1: PRINT TIMER - anitimer
' IF TIMER - anitimer > .2 THEN
'     redframe = redframe + 1
'     anitimer = TIMER
'     IF redframe = 2 THEN redframe = 0
''      IF redframe = 1 THEN PUT (100, 100), sprred2
'      IF redframe = 1 THEN PUT (100, 100), sprred1
'   END IF

'
'
'LOOP UNTIL INKEY$ <> ""
GOSUB intro

play1:
you.health = 100
CLS
GOSUB getmap
'CLS
'FOR xa = 1 TO 12
'    FOR ya = 1 TO 15
'        LOCATE xa, ya:
'        IF map1(ya, xa) = 99 THEN PRINT "&"
'        IF map1(ya, xa) = 12 THEN PRINT "M"
'        IF map1(ya, xa) = 15 THEN PRINT "C"
'
'    NEXT
'NEXT

'DO
a$ = INKEY$
IF a$ = "+" THEN
    room = room + 1
    IF room = 12 THEN room = 1
    CLS
    GOSUB getmap
END IF

IF a$ = "q" THEN alive = 0
'LOOP WHILE alive = 1
playy:
anitimer = TIMER
DO
    movex = 0
    movey = 0
    kbd$ = INKEY$ 'Get Key
    IF kbd$ <> "" THEN
        fight = INT(RND * 100)
        IF fight < difficulty THEN GOSUB kombat
    END IF
    IF kbd$ <> "" THEN
        SELECT CASE kbd$ 'Select what button you hit
            CASE IS = "O"
                p2 = p2 + 1
                IF p2 > 15 THEN p2 = 0
                COLOR p2, palswap

            CASE IS = "P"
                palswap = palswap + 1
                IF palswap = 5 THEN palswap = 0
                COLOR p2, palswap
            CASE CHR$(0) + "H"
                'PRINT "Up"
                movey = -1
            CASE CHR$(0) + "P"

                movey = 1 ' PRINT "Down"
            CASE CHR$(0) + "K"
                movex = -1
                ' PRINT "Left"
            CASE CHR$(0) + "M"
                movex = 1
                'PRINT "Right"
            CASE CHR$(13)
                'PRINT "You hit Enter"
            CASE CHR$(27)
                END
        END SELECT

    END IF
    IF movex <> 0 THEN GOSUB checkmove
    IF movey <> 0 THEN GOSUB checkmove

    IF TIMER - anitimer > .2 THEN
        redframe = redframe + 1
        anitimer = TIMER
        IF redframe = 2 THEN redframe = 0
        IF redframe = 1 THEN PUT (you.x, you.y), sprred2
        IF redframe = 1 THEN PUT (you.x, you.y), sprred1
    END IF


LOOP

kombat:
FOR x = 1 TO 100 STEP 10
    SOUND 200 - (x), 1
    SOUND 48, .25
NEXT x

CLS
timera = TIMER
redframe = 0
RANDOMIZE TIMER
enemy = INT(RND * 4)
IF finalmatch = 1 THEN enemy = 5
SELECT CASE enemy
    CASE 1
        PUT (200, 10), sprwolf
        LOCATE 5, 30: PRINT "Dire Wolf"
    CASE 2
        PUT (200, 10), sprdragon
        LOCATE 5, 25: PRINT "Pygmy Dragon"
    CASE 5
        PUT (200, 10), sprmermah1
        LOCATE 5, 30: PRINT "MERMAH"
    CASE ELSE
        PUT (200, 10), sprgoblinleft
        LOCATE 5, 30: PRINT "Goblin"
END SELECT
LOCATE 10, 12: PRINT "ENTERING THE KEYBOARD KOMBAT ZONE!"
LOCATE 12, 10: PRINT "PRESS (SPACEBAR) TO CONTINUE"
anitimer = TIMER
PUT (10, 10), sprred2, PSET
DO
    ' LOCATE 1, 1: PRINT TIMER - anitimer
    IF TIMER - anitimer > (.2 - (difficulty * .001)) THEN
        redframe = redframe + 1
        anitimer = TIMER
        IF redframe = 2 THEN redframe = 0
        IF redframe = 1 THEN PUT (10, 10), sprred2, PSET
        IF redframe = 1 THEN PUT (10, 10), sprred1, PSET
    END IF

LOOP UNTIL INKEY$ = " "
LOCATE 10, 12: PRINT "                                  "
LOCATE 12, 10: PRINT "                            "


LOCATE 8, 2: PRINT "Health", you.health
RANDOMIZE TIMER
rando = INT(RND * 29) + 1
IF finalmatch = 1 THEN rando = 30
SELECT CASE rando
    CASE 1
        RESTORE lblwords1
    CASE 2
        RESTORE lblwords2
    CASE 3
        RESTORE lblwords3
    CASE 4
        RESTORE lblwords4
    CASE 5
        RESTORE lblwords5
    CASE 6
        RESTORE lblwords6
    CASE 7
        RESTORE lblwords7
    CASE 8
        RESTORE lblwords8
    CASE 9
        RESTORE lblwords9
    CASE 10
        RESTORE lblwords10
    CASE 11
        RESTORE lblwords11
    CASE 12
        RESTORE lblwords12
    CASE 13
        RESTORE lblwords13
    CASE 14
        RESTORE lblwords14
    CASE 15
        RESTORE lblwords15
    CASE 16
        RESTORE lblwords16
    CASE 17
        RESTORE lblwords17
    CASE 18
        RESTORE lblwords18
    CASE 19
        RESTORE lblwords19
    CASE 20
        RESTORE lblwords20
    CASE 21
        RESTORE lblwords21
    CASE 22
        RESTORE lblwords22
    CASE 23
        RESTORE lblwords23
    CASE 24
        RESTORE lblwords24
    CASE 25
        RESTORE lblwords25
    CASE 26
        RESTORE lblwords26
    CASE 27
        RESTORE lblwords27
    CASE 28
        RESTORE lblwords28
    CASE 30
        RESTORE lblwords30
    CASE ELSE
        RESTORE lblwords2

END SELECT

READ i%
FOR x = 1 TO i%
    READ a$
    word$(x) = a$
NEXT
wordno = 1
a$ = word$(wordno)
runtimer = TIMER
wordy = 40 - LEN(a$)
wordno = 1
wordpos = 1



'LINE (100, 100)-(120, 120), 1, BF
gameone:
DO
    ' LOCATE 1, 1: PRINT TIMER - runtimer


    IF TIMER - runtimer > wordspeed THEN
        wordy = wordy - 1
        runtimer = TIMER
        FOR lx = 1 TO LEN(a$)
            IF wordy + lx < 1 THEN GOTO death
            LOCATE 10, wordy + lx
            'IF wordpos > lx THEN COLOR 2 ELSE COLOR 3
            PRINT MID$(a$, lx)
        NEXT lx
        LOCATE 10, wordy + LEN(a$) + 1: PRINT " "
    END IF
    keybd$ = INKEY$

    LOCATE 2, 1: PRINT MID$(a$, wordpos, 1)
    'LOCATE 11, wordy - 1: PRINT " Û "
    IF keybd$ <> "" THEN
        IF keybd$ <> MID$(a$, wordpos, 1) THEN
            SOUND 50, 1
            SOUND 100, 1
            SOUND 50, .5

            you.health = you.health - 10
            LOCATE 8, 2: PRINT "Health", you.health
            IF you.health < 1 THEN GOTO die
            ' 50, 2
        END IF
    END IF
    IF keybd$ = MID$(a$, wordpos, 1) THEN
        wordpos = wordpos + 1
        ' 100, 2

    END IF
    IF wordpos > LEN(a$) THEN
        FOR ofset = 1 TO LEN(a$)
            LOCATE 10, wordy + ofset: PRINT " "
        NEXT ofset
        wordno = wordno + 1

        IF wordno >= i% + 1 THEN
            IF finalmatch = 1 THEN GOTO final
        END IF
        IF wordno >= i% + 1 THEN

            PUT (200, 10), sprskull, PSET
            SOUND 200, 1: SOUND 300, 1: SOUND 250, .5: SOUND 47, 1
            LOCATE 10, 2: PRINT "KEYBOARD KARNAGE KOMPLETED!"
            DO: LOOP WHILE INKEY$ = ""
            GOTO play1
        END IF
        a$ = word$(wordno)
        wordpos = 1
        wordy = 40 - LEN(a$)

    END IF
LOOP
nextword:
RANDOMIZE TIMER
rando = INT(RND * 29) + 1
IF finalmatch = 1 THEN rando = 30
SELECT CASE rando
    CASE 1
        RESTORE lblwords1
    CASE 2
        RESTORE lblwords2
    CASE 3
        RESTORE lblwords3
    CASE 4
        RESTORE lblwords4
    CASE 5
        RESTORE lblwords5
    CASE 6
        RESTORE lblwords6
    CASE 7
        RESTORE lblwords7
    CASE 8
        RESTORE lblwords8
    CASE 9
        RESTORE lblwords9
    CASE 10
        RESTORE lblwords10
    CASE 11
        RESTORE lblwords11
    CASE 12
        RESTORE lblwords12
    CASE 13
        RESTORE lblwords13
    CASE 14
        RESTORE lblwords14
    CASE 15
        RESTORE lblwords15
    CASE 16
        RESTORE lblwords16
    CASE 17
        RESTORE lblwords17
    CASE 18
        RESTORE lblwords18
    CASE 19
        RESTORE lblwords19
    CASE 20
        RESTORE lblwords20
    CASE 21
        RESTORE lblwords21
    CASE 22
        RESTORE lblwords22
    CASE 23
        RESTORE lblwords23
    CASE 24
        RESTORE lblwords24
    CASE 25
        RESTORE lblwords25
    CASE 26
        RESTORE lblwords26
    CASE 27
        RESTORE lblwords27
    CASE 28
        RESTORE lblwords28
    CASE 30
        RESTORE lblwords30
    CASE ELSE
        RESTORE lblwords2

END SELECT

READ i%
FOR x = 1 TO i%
    READ a$
    word$(x) = a$
NEXT

wordno = 1
a$ = word$(wordno)
runtimer = TIMER
wordy = 40 - LEN(a$) - 1
wordno = 1
wordpos = 1
GOTO gameone

death:
SOUND 50, 1
SOUND 100, 1
SOUND 50, .5
you.health = you.health - 10
LOCATE 8, 2: PRINT "Health", you.health
FOR ofset = 1 TO LEN(a$)
    '    LOCATE 10, wordy + ofset: PRINT " "
    LOCATE 10, 1: PRINT "                        "
NEXT ofset
IF you.health < 1 THEN GOTO die
GOTO nextword
END

RETURN


checkmove:
IF you.ty + movex = 0 THEN
    you.ty = 14
    you.x = 208
    room = room - 1
    CLS
    GOSUB getmap
END IF

IF you.ty + movex = 15 THEN
    you.ty = 1
    you.x = 1
    room = room + 1
    CLS
    GOSUB getmap
END IF
IF you.tx + movey = 0 THEN
    you.tx = 11
    room = room - 2
    you.y = 160
    CLS
    GOSUB getmap
END IF

IF you.tx + movey = 12 THEN
    you.tx = 1
    room = room + 2
    you.y = 1
    CLS
    IF room > 11 THEN room = 9
    GOSUB getmap
END IF



B = map1(you.ty + movex, you.tx + movey)
IF B = 24 THEN
    LOCATE 1, 1: PRINT "HURRY UP AND FINISH YOUR QUEST!"
    SLEEP
    CLS
    GOSUB getmap
END IF
'LOCATE 3, 30: PRINT you.tx
'LOCATE 4, 30: PRINT you.ty
'LOCATE 2, 30: PRINT B
IF B = 25 THEN GOTO justp
IF B = 27 THEN GOTO justp
IF B = 23 THEN
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5

    Apple = 1
END IF
IF B = 28 THEN
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5
    mushroom = 1
END IF
IF B = 29 THEN
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5

    flower = 1
END IF
IF B = 30 THEN
    diamond = 1
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5

END IF
IF B = 31 THEN
    PUT (272, 168), sprkey, PSET
    key1 = 1
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5

    B = 99
END IF
IF B = 32 THEN
    SOUND 200, 1
    SOUND 300, .5
    SOUND 400, 1.5

    IF key1 = 1 THEN B = 99
END IF
IF B = 33 THEN
    IF diamond = 0 THEN
        SOUND 55, 1
        SOUND 67, 1
        LOCATE 1, 1: PRINT "I'll let you pass for a diamond"
    END IF
    IF diamond = 1 THEN B = 99
END IF

IF B = 16 THEN
    IF room = 9 THEN
        room = 11
        CLS
        GOSUB getmap
    END IF
    IF room = 1 THEN
        IF mushroom + flower + Apple = 3 THEN GOTO endboss
    END IF

END IF
IF flower = 1 THEN PUT (256, 184), sprflower, PSET
IF Apple = 1 THEN PUT (272, 184), sprapple, PSET
IF mushroom = 1 THEN PUT (288, 184), sprmushroom, PSET
IF diamond = 1 THEN PUT (256, 168), sprdiamond, PSET
IF key1 = 1 THEN PUT (272, 168), sprkey, PSET


IF B <> 99 THEN RETURN
justp:

you.tx = you.tx + movey
you.ty = you.ty + movex
'PUT (you.x, you.y), sprred1, XOR
PUT (you.x, you.y), erased, PSET
IF B = 27 THEN PUT (you.x, you.y), sprsand, PSET
IF B = 25 THEN PUT (you.x, you.y), sprgrass, PSET
you.x = you.x + (movex * 16)
you.y = you.y + (movey * 16)
PUT (you.x, you.y), sprred1, PSET

RETURN



END
getmap:
SELECT CASE room
    CASE IS = 1
        RESTORE lblroom1
    CASE IS = 2
        RESTORE lblroom2
    CASE IS = 3
        RESTORE lblroom3
    CASE IS = 4
        RESTORE lblroom4
    CASE IS = 5
        RESTORE lblroom5
    CASE IS = 6
        RESTORE lblroom6
    CASE IS = 7
        RESTORE lblroom7
    CASE IS = 8
        RESTORE lblroom8
    CASE IS = 9
        RESTORE lblroom9
    CASE IS = 10
        RESTORE lblroom10
    CASE IS = 11
        RESTORE lblroom11

END SELECT
FOR y = 1 TO 12
    FOR x = 1 TO 15
        READ i%
        map1(x, y) = i%
        x1 = (x - 1) * 16
        y1 = (y - 1) * 16
        SELECT CASE i%
            CASE IS = 10
                PUT (x1, y1), sprtree1, PSET
            CASE IS = 11
                PUT (x1, y1), sprtree2, PSET
            CASE IS = 12
                PUT (x1, y1), sprmountain, PSET
            CASE IS = 13
                PUT (x1, y1), sprredbrick, PSET
            CASE IS = 14
                PUT (x1, y1), sprcastleleft, PSET
            CASE IS = 15
                PUT (x1, y1), sprcastleright, PSET
            CASE IS = 16
                PUT (x1, y1), sprcastledoor, PSET
            CASE IS = 17
                PUT (x1, y1), sprcastlewall, PSET
            CASE IS = 18
                PUT (x1, y1), sprswordleft, PSET
            CASE IS = 19
                PUT (x1, y1), sprshield, PSET
            CASE IS = 20
                PUT (x1, y1), sprswordright, PSET
            CASE IS = 21
                PUT (x1, y1), sprhut, PSET
            CASE IS = 22
                PUT (x1, y1), sprwater, PSET
            CASE IS = 23
                PUT (x1, y1), sprapple, PSET
            CASE IS = 24
                PUT (x1, y1), sprknight, PSET
            CASE IS = 25
                PUT (x1, y1), sprgrass, PSET
            CASE IS = 26
                PUT (x1, y1), sprhills, PSET
            CASE IS = 27
                PUT (x1, y1), sprsand, PSET
            CASE IS = 28
                IF mushroom = 0 THEN PUT (x1, y1), sprmushroom, PSET
            CASE IS = 29
                IF flower = 0 THEN PUT (x1, y1), sprflower, PSET
            CASE IS = 30
                IF diamond = 0 THEN PUT (x1, y1), sprdiamond, PSET
            CASE IS = 31
                IF key1 = 0 THEN PUT (x1, y1), sprkey, PSET
            CASE IS = 32
                IF lock1 = 0 THEN PUT (x1, y1), sprlock, PSET
            CASE IS = 33
                IF goblin = 0 THEN PUT (x1, y1), sprgoblinright, PSET


        END SELECT
    NEXT x
NEXT y
FOR y = 1 TO 176 STEP 16
    FOR x = 240 TO 304 STEP 16
        PUT (x, y), sprredbrick, PSET
    NEXT x
NEXT y
IF flower = 1 THEN PUT (256, 184), sprflower, PSET
IF Apple = 1 THEN PUT (272, 184), sprapple, PSET
IF mushroom = 1 THEN PUT (288, 184), sprmushroom, PSET
IF diamond = 1 THEN PUT (256, 168), sprdiamond, PSET
IF key1 = 1 THEN PUT (272, 168), sprkey, PSET

PUT (you.x, you.y), sprred1, PSET

RETURN



subgetpic:

FOR y = 1 TO 16
    FOR x = 1 TO 16
        READ i%
        PSET (x, y), i%

    NEXT x
NEXT y

RETURN

die:

CLS
FOR x = 1 TO 304 STEP 16
    PUT (x, 10), sprskull, PSET
NEXT x
 PLAY "<<<F4D4G2D1MLL4 FD MN G2 D1>>>"
 LOCATE 9, 2: PRINT "GAME OVER"
LOCATE 10, 2: PRINT "YOU HAVE DIED"
LOCATE 11, 2: INPUT "WOULD YOU LIKE TO TRY again?", a$
IF a$ = "Y" THEN GOTO begin
IF a$ = "y" THEN GOTO begin
GOTO ender
END



endboss:

finalmatch = 1
CLS

LOCATE 10, 2: PRINT "Mermah takes the ingredients and"
LOCATE 11, 2: PRINT "makes a potion. And suprisingly he "
LOCATE 12, 2: PRINT "downs the potion, and laughs."
LOCATE 13, 2: PRINT "Bwa ha ha ha ha!!!!!"
anitimer = TIMER
redframe = 0
'PUT (10, 10), sprred2, PSET
antimer = TIMER
finalmatch = 1

DO
    'LOCATE 1, 1: PRINT TIMER - anitimer
    IF TIMER - anitimer > .2 THEN
        redframe = redframe + 1
        anitimer = TIMER
        IF redframe = 2 THEN redframe = 0
        IF redframe = 0 THEN PUT (10, 10), sprred2, PSET
        IF redframe = 1 THEN PUT (10, 10), sprred1, PSET
        IF redframe = 0 THEN PUT (100, 10), sprmermah2, PSET
        IF redframe = 1 THEN PUT (100, 10), sprmermah1, PSET

    END IF
LOOP WHILE INKEY$ = ""
LOCATE 10, 2: PRINT "Now I will become stronger than "
LOCATE 11, 2: PRINT "ever! I will be king!!!!           "
LOCATE 12, 2: PRINT "NO YOU WON'T I WILL DEFEAT YOU"
LOCATE 13, 2: PRINT "We shall see!!!!!!!"
DO
LOOP WHILE INKEY$ = ""
you.health = 100
CLS
finalmatch = 1
GOSUB kombat
final:

CLS
'Print 1234567890123456789012345678901234567890
PRINT "You realize that this Mermah was an"
PRINT "imposter.  The real Mermah was tied"
PRINT "up in the cellar."
PRINT "The real Mermah creates a new potion"
PRINT "and the King is healed."
PRINT "(SPACE) to continue."
PLAY "MB <<L8 D. L16 C L4 < B > D G L8 B B L4 B A P4"
PLAY "ML L8 D. L16 C MN < L8 ML B > D MN"
 PLAY "ML L8 G B MN > L4 D  ML L8 C < B MN L4 A P4 P4"
 PLAY "ML L8 D. L16 C MN < L4 B > D G L8 B B"
 PLAY "L4 B A P4"
 PLAY "ML L8 D. L16 C MN < ML L8 B > G MN ML L8 E A MN L4 G F#"
PLAY "L2 F# L4 G"
PLAY "P1>>"

DO: LOOP WHILE INKEY$ <> " "
CLS
LOCATE 11, 15

PRINT "YOUR WINNER!!"
LOCATE 12, 15
PRINT "YOURE AWESOM!!"
LOCATE 10, 15: PRINT "CONGRATURATIONS!"

anitimer = TIMER
totaltimer = TIMER
newlooper:
DO
    IF TIMER - anitimer > .25 THEN
    COLOR INT(RND * 15), INT(RND * 15)
    anitimer = TIMER
END IF

LOOP WHILE INKEY$ <> " "
IF TIMER - totaltimer < 5 THEN GOTO newlooper:
CLS
ender:
COLOR 1, 1
PRINT "THANK YOU FOR PLAYING THE SHAREWARE GAME"
PRINT "IF YOU ARE INTERESTED IN PLAYING MORE"
PRINT "PLEASE VISIT MY youTube CHANNEL"
PRINT "MONTIEMONGOOSE"
PRINT "AND LEAVE A LIKE AND A COMMENT!"
PRINT "I HOPE YOU ENJOYED IT!"
PRINT "WINNERS DON'T DO DRUGS!"
END

intro:
PLAY "MB <<L8 D. L16 C L4 < B > D G L8 B B L4 B A P4"
PLAY "ML L8 D. L16 C MN < L8 ML B > D MN"
 PLAY "ML L8 G B MN > L4 D  ML L8 C < B MN L4 A P4 P4"
 PLAY "ML L8 D. L16 C MN < L4 B > D G L8 B B"
 PLAY "L4 B A P4"
 PLAY "ML L8 D. L16 C MN < ML L8 B > G MN ML L8 E A MN L4 G F#"
PLAY "L2 F# L4 G"
PLAY "P1>>"

'PLAY "MBT120<<e8e8f8g8g8f8e8d8c8c8d8e8e8d12d4"
'PLAY "e8e8f8g8g8f8e8d8c8c8d8e8d8c12c4>>"
'PLAY "d8d8e8c8d8e12f12e8c8d8e12f12e8d8c8d8p8"
'PLAY "e8e8f8g8g8f8e8d8c8c8d8e8d8c12c4"



anitimer = TIMER
LOCATE 10, 2:
PRINT "PRINCESS RED KEYBOARD KARNAGE WARRIOR"
LOCATE 11, 5: PRINT "(C) 2016 demiO2"
LOCATE 14, 5: PRINT "Press (spacebar) to continue)"
'SLEEP
anitimer = TIMER
DO: LOOP WHILE INKEY$ <> " "
CLS
PRINT "A long time ago, in the far away kingdom"
PRINT "of Typlandia, everyone practiced their"
PRINT "typing skills. Especially, Princess Red."
GOSUB aniintro
CLS
PRINT "Her father the king became ill and      "
PRINT "requested that she find a cure to heal"
PRINT "him."
GOSUB aniintro
CLS
PRINT "She went to Mermah, the king's advisor"
PRINT "and he informed her the cure could be"
PRINT "made by gathering three ingredients..."
PRINT "A Mushroom, a flower, and an apple"
PRINT "and bringing them back to the castle"

FOR x = 1 TO 288 STEP 8
PUT (x, 139), sprredbrick, PSET
PUT (x, 66), sprredbrick, PSET

NEXT x

DO
    'LOCATE 1, 1: PRINT TIMER - anitimer
    IF TIMER - anitimer > .2 THEN
        redframe = redframe + 1
        anitimer = TIMER
        IF redframe = 2 THEN redframe = 0
        IF redframe = 0 THEN PUT (10, 100), sprred2, PSET
        IF redframe = 1 THEN PUT (10, 100), sprred1, PSET
        IF redframe = 0 THEN PUT (100, 100), sprmermah2, PSET
        IF redframe = 1 THEN PUT (100, 100), sprmermah1, PSET

    END IF
LOOP WHILE INKEY$ = ""
CLS
LOCATE 5, 10: INPUT "Difficulty level (1-20)", difficulty
IF difficulty < 1 THEN difficulty = 1
IF difficulty > 20 THEN difficulty = 20

SOUND 0, 0
RETURN
aniintro:
anitimer = TIMER
redframe = 1
PUT (100, 82), sprknight, PSET
PUT (100, 118), sprknight, PSET
FOR x = 1 TO 288 STEP 8
PUT (x, 139), sprredbrick, PSET
PUT (x, 66), sprredbrick, PSET

NEXT x

DO
    'LOCATE 1, 1: PRINT TIMER - anitimer
    IF TIMER - anitimer > .2 THEN
        redframe = redframe + 1
        anitimer = TIMER
        IF redframe = 2 THEN redframe = 0
        IF redframe = 0 THEN PUT (10, 100), sprred2, PSET
        IF redframe = 1 THEN PUT (10, 100), sprred1, PSET
        IF redframe = 0 THEN PUT (100, 100), sprking2, PSET
        IF redframe = 1 THEN PUT (100, 100), sprking1, PSET

    END IF
LOOP WHILE INKEY$ = ""


RETURN



lblRED1: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,2,2,2,3,3,3,3,3,3,3,3,0,0
DATA 0,0,1,1,1,3,3,0,1,3,3,3,0,1,0,0
DATA 0,0,2,2,3,3,3,0,1,3,3,3,0,1,3,0
DATA 0,2,2,2,3,3,3,3,3,3,3,3,3,3,3,0
DATA 2,2,2,2,3,3,3,3,3,0,0,0,3,3,0,0
DATA 2,2,0,0,0,0,3,3,3,3,3,3,3,0,0,0
DATA 2,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,2,3,3,2,1,1,1,1,1,2,2,3,3
DATA 0,0,0,0,3,3,2,2,2,2,2,2,0,0,3,3
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0
DATA 0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0
lblRED2: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,2,2,2,3,3,3,3,3,3,3,3,0,0
DATA 0,0,1,1,1,3,3,0,1,3,3,3,0,1,0,0
DATA 0,0,2,2,3,3,3,0,1,3,3,3,0,1,3,0
DATA 0,2,2,2,3,3,3,3,3,3,3,3,3,3,3,0
DATA 0,2,2,2,3,3,3,3,3,0,0,0,3,3,0,0
DATA 0,2,2,2,0,0,3,3,3,3,3,3,3,0,0,0
DATA 0,0,2,0,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,3,3,2,2,1,1,1,1,1,2,3,3,0
DATA 0,0,0,3,3,2,2,2,2,2,2,2,0,3,3,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0
DATA 0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0
lblDRAGON: ',,,,,,,,,,,,,,,
DATA 0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
DATA 0,0,1,1,3,1,1,0,0,0,0,2,0,0,0,0
DATA 0,1,1,3,0,3,1,1,0,0,0,1,2,0,0,0
DATA 1,1,1,1,3,1,1,1,0,0,0,0,1,2,0,0
DATA 1,2,2,2,1,1,2,1,1,0,0,0,1,1,2,0
DATA 2,1,1,1,1,1,2,1,1,0,0,0,0,1,1,2
DATA 0,0,1,1,1,1,2,1,1,0,0,0,0,0,1,2
DATA 0,0,0,0,0,1,2,1,1,0,0,0,0,0,1,2
DATA 0,0,0,0,1,2,2,1,1,0,0,0,0,1,1,2
DATA 0,0,0,1,2,2,2,1,1,1,0,0,0,1,1,2
DATA 0,0,0,2,2,2,1,1,1,1,0,0,1,1,1,2
DATA 0,0,2,2,2,2,2,1,3,3,1,1,1,1,1,2
DATA 0,0,2,2,2,2,2,3,1,1,3,1,1,1,2,2
DATA 0,0,0,2,2,2,2,3,1,1,3,1,1,1,2,0
DATA 0,0,0,0,2,2,2,2,3,2,1,2,2,2,2,0
DATA 0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0
lblTREE1: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,3,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,3,0,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,3,0,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,3,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0
DATA 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,1,1,1,2,2,2,1,1,1,1,0,0,0
DATA 0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0
lbltree2: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0
DATA 0,1,0,1,0,1,2,2,1,0,1,0,1,0,1,0
lblMountain: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,2,2,3,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,1,2,2,3,0,0,0,0,0
DATA 0,0,0,0,0,2,2,2,2,2,2,3,0,0,0,0
DATA 0,0,0,0,2,1,2,2,2,2,2,2,3,0,0,0
DATA 0,0,0,2,2,2,2,2,2,1,2,2,3,0,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,3,0,0
DATA 0,2,2,1,2,2,2,2,1,2,2,2,2,2,3,0
DATA 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3
DATA 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
lblredbrick: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
DATA 2,2,2,2,0,2,2,2,2,2,2,2,0,2,2,2
lblleftcaste: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
lblrightcastle: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
lblcastledoor: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,0,2,0,3,3,3,3,3,3
DATA 3,3,3,3,3,3,0,2,2,2,0,3,3,3,3,3
DATA 3,3,3,3,3,0,2,2,2,2,2,0,3,3,3,3
DATA 0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0
DATA 3,3,3,3,0,2,2,2,2,2,2,2,0,3,3,3
DATA 3,3,3,3,0,2,2,2,2,2,2,2,0,3,3,3
DATA 3,3,3,3,0,2,2,2,2,2,1,2,0,3,3,3
DATA 0,0,0,0,0,2,2,2,2,2,1,2,0,0,0,0
DATA 3,3,3,3,0,2,2,2,2,2,2,2,0,3,3,3
DATA 3,3,3,3,0,2,2,2,2,2,2,2,0,3,3,3
DATA 3,3,3,3,0,2,2,2,2,2,2,2,0,3,3,3
lblwhitebrick: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,0,3,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,0,3,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,0,3,3,3,3,3,3,3,3,0,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 3,3,3,3,3,3,3,3,0,3,3,3,3,3,3,3
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
DATA 3,3,3,3,0,3,3,3,3,3,3,3,0,3,3,3
lblleftsword: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0
DATA 0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,1,2,0,0,0,0,0
DATA 0,0,0,0,0,0,0,1,1,2,2,2,0,0,0,0
DATA 0,0,0,0,0,0,0,1,0,0,2,2,2,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblshield: ',,,,,,,,,,,,,,,,
DATA 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,1,1,3,3,3,1,1,3,1,1,1,0,0
DATA 0,0,1,1,1,2,3,2,1,1,1,3,1,1,0,0
DATA 0,0,1,1,1,3,3,3,1,1,1,3,1,1,0,0
DATA 0,0,1,1,1,1,3,3,3,1,1,3,1,1,0,0
DATA 0,0,1,1,1,1,1,3,3,1,1,3,1,1,0,0
DATA 0,0,1,1,1,1,1,3,3,1,3,3,1,1,0,0
DATA 0,0,1,1,1,1,1,3,3,3,3,1,1,1,0,0
DATA 0,0,0,1,1,1,1,1,3,3,1,1,1,0,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblwolf: ',,,,,,,,,,,,,,,
DATA 0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0
DATA 0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0
DATA 0,0,1,2,1,2,1,0,0,0,0,0,0,0,0,0
DATA 0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
DATA 0,3,0,3,0,1,1,1,0,0,0,0,0,0,0,0
DATA 0,0,3,0,3,1,1,1,0,0,0,0,1,1,0,0
DATA 0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0
DATA 0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1
DATA 0,0,0,0,1,1,3,1,1,1,1,0,0,0,1,1
DATA 0,0,0,0,1,3,1,1,1,1,1,0,0,0,1,1
DATA 0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,1
DATA 0,0,0,1,0,1,1,1,1,1,1,1,1,0,1,1
DATA 0,0,0,0,0,1,3,3,1,1,3,3,1,1,1,1
DATA 0,0,0,0,0,0,1,1,3,1,1,1,3,1,1,0
DATA 0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0
DATA 0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0
lblrightgob: ',,,,,,,,,,,,,,,
DATA 0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,0,0,0,0,3,0
DATA 0,0,1,1,1,1,0,1,0,1,0,0,0,0,3,0
DATA 0,0,1,1,1,1,0,1,0,1,1,0,0,3,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,0,0,3,0,0
DATA 0,0,1,1,1,1,2,2,2,1,1,0,0,3,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,0,0,3,0,0
DATA 0,0,0,1,1,1,3,3,0,0,0,0,0,3,0,0
DATA 0,0,0,1,3,3,3,1,3,0,0,0,3,0,0,0
DATA 0,0,0,3,3,3,3,3,3,2,0,0,3,0,0,0
DATA 0,0,0,1,1,1,1,1,2,2,2,3,0,0,0,0
DATA 0,0,0,3,1,3,3,3,2,2,2,3,0,0,0,0
DATA 0,0,0,3,3,3,1,1,1,3,0,0,0,0,0,0
DATA 0,0,0,1,1,0,0,3,3,3,0,0,0,0,0,0
DATA 0,0,0,3,1,3,0,0,1,1,1,0,0,0,0,0
DATA 0,0,0,1,1,1,0,0,1,3,3,3,0,0,0,0
lblleftgob: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0
DATA 0,3,0,0,0,0,1,1,1,1,1,1,1,1,0,0
DATA 0,3,0,0,0,0,1,0,1,0,1,1,1,1,0,0
DATA 0,0,3,0,0,1,1,0,1,0,1,1,1,1,0,0
DATA 0,0,3,0,0,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,3,0,0,1,1,2,2,2,1,1,1,1,0,0
DATA 0,0,3,0,0,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,3,0,0,0,0,0,3,3,1,1,1,0,0,0
DATA 0,0,0,3,0,0,0,3,1,3,3,3,1,0,0,0
DATA 0,0,0,3,0,0,2,3,3,3,3,3,3,0,0,0
DATA 0,0,0,0,3,2,2,2,1,1,1,1,1,0,0,0
DATA 0,0,0,0,3,2,2,2,3,3,3,1,3,0,0,0
DATA 0,0,0,0,0,0,3,1,1,1,3,3,3,0,0,0
DATA 0,0,0,0,0,0,3,3,3,0,0,1,1,0,0,0
DATA 0,0,0,0,0,1,1,1,0,0,3,1,3,0,0,0
DATA 0,0,0,0,3,3,3,1,0,0,1,1,1,0,0,0
lblrightsword: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0
DATA 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0
DATA 0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0
DATA 0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0
DATA 0,0,0,0,2,2,2,1,1,0,0,0,0,0,0,0
DATA 0,0,0,2,2,2,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblskull: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0
DATA 0,0,0,0,3,0,0,3,0,0,3,0,0,0,0,0
DATA 0,0,0,0,3,0,0,3,0,0,3,0,0,0,0,0
DATA 0,0,0,0,3,0,0,3,0,0,3,0,0,0,0,0
DATA 0,0,0,0,0,3,3,0,3,3,0,0,0,0,0,0
DATA 0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0
DATA 0,3,0,0,0,0,0,0,0,0,0,0,0,3,0,0
DATA 0,0,3,0,0,0,3,3,3,0,0,0,3,0,0,0
DATA 0,3,0,3,0,0,0,0,0,0,0,3,0,3,0,0
DATA 0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0
DATA 0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0
DATA 0,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0
DATA 0,3,3,0,0,0,0,0,0,0,0,0,3,3,0,0
DATA 0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblhut: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0
DATA 0,0,0,0,3,1,1,1,1,1,3,0,0,0,0,0
DATA 0,0,0,3,1,1,1,1,1,1,1,3,0,0,0,0
DATA 0,0,3,1,1,1,1,1,1,1,1,1,3,0,0,0
DATA 0,3,1,1,1,1,1,1,1,1,1,1,1,3,0,0
DATA 3,0,2,2,2,2,2,2,2,2,2,2,2,0,3,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,2,0,2,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,0,0,0,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,0,0,0,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,0,0,0,2,2,2,2,0,0,0
DATA 0,0,2,2,2,2,0,0,0,2,2,2,2,0,0,0
lblwater: ',,,,,,,,,,,,,,,
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,3,1,1,1,3,1,1,1,3,1,1,1,3,1,3
DATA 3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1
DATA 1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 3,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1
DATA 1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3
DATA 1,1,3,1,1,1,3,1,1,1,3,1,1,1,3,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
DATA 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
lblapple: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,2,2,0,1,0,2,2,2,0,0,0
DATA 0,0,0,0,2,2,2,2,1,2,2,2,2,2,0,0
DATA 0,0,0,2,2,2,2,2,1,2,2,2,2,2,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,3,3,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,3,3,3,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,3,3,3,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,3,3,3,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,3,3,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0
DATA 0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblsoldier: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0
DATA 0,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0
DATA 0,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0
DATA 0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0
DATA 0,0,0,0,1,1,3,0,0,0,3,1,1,0,1,0
DATA 0,0,0,0,0,3,3,3,3,3,3,3,0,0,1,0
DATA 0,0,0,0,0,0,1,3,3,3,1,0,0,0,1,0
DATA 0,2,2,2,2,2,1,1,1,1,1,1,0,1,1,1
DATA 0,2,2,2,2,2,1,1,1,1,1,1,1,3,2,0
DATA 0,2,2,2,2,2,3,3,3,3,3,1,1,3,2,0
DATA 0,2,2,2,2,2,1,1,1,1,1,0,0,0,0,0
DATA 0,2,2,2,2,2,1,1,1,1,1,0,0,0,0,0
DATA 0,0,2,2,2,0,1,1,0,1,1,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0
lblking1: ',,,,,,,,,,,,,,,
DATA 0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0
DATA 0,0,0,0,3,3,3,0,0,3,3,3,0,0,3,0
DATA 0,0,0,0,3,3,3,0,0,3,3,3,0,0,3,0
DATA 0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0
DATA 0,0,0,0,3,3,3,3,3,0,0,0,3,3,0,0
DATA 0,0,0,0,0,0,3,3,3,3,3,3,3,0,0,0
DATA 0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,2,3,3,2,1,1,1,1,1,2,2,3,3
DATA 0,0,0,0,3,3,2,2,2,2,2,2,0,0,3,3
DATA 0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0
DATA 0,0,0,0,2,2,2,2,0,2,2,2,0,0,0,0
DATA 0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0
lblking2: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,0,3,3,3,0,0,3,3,3,0,0,3,0,0
DATA 0,0,0,3,3,3,0,0,3,3,3,0,0,3,0,0
DATA 0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,0
DATA 0,0,0,3,3,3,3,3,0,0,0,3,3,0,0,0
DATA 0,0,0,0,0,3,3,3,3,3,3,3,0,0,0,0
DATA 0,0,0,0,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,2,2,2,2,1,1,1,1,1,2,3,3,0
DATA 0,0,0,2,3,3,2,2,2,2,2,2,0,3,3,0
DATA 0,0,0,0,3,3,2,2,2,2,2,2,0,0,0,0
DATA 0,0,0,0,2,2,2,2,0,2,2,2,0,0,0,0
DATA 0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0
lblheart: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,2,2,2,0,0,0,0,0,2,2,2,0,0,0
DATA 0,2,2,2,2,2,0,0,0,2,2,3,2,2,0,0
DATA 2,2,2,2,2,2,2,0,2,2,2,2,3,2,2,0
DATA 2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,0
DATA 2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,0
DATA 0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0
DATA 0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0
DATA 0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0
DATA 0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblgrass: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0
DATA 0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0
DATA 0,1,0,1,0,0,0,0,0,1,0,3,0,1,0,0
DATA 0,1,0,0,1,0,0,0,0,1,0,3,0,1,0,0
DATA 0,1,0,0,1,0,3,0,0,0,1,3,0,1,0,0
DATA 0,0,1,0,1,0,3,0,0,0,1,0,3,1,0,0
DATA 0,0,1,0,1,3,0,0,0,1,0,0,3,1,0,0
DATA 0,0,1,0,1,3,0,0,0,1,0,0,3,1,0,0
DATA 0,0,1,1,3,1,0,0,0,1,0,3,0,1,0,0
DATA 0,0,1,1,3,1,0,0,0,1,0,3,0,1,0,0
DATA 0,0,0,1,3,0,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,1,3,0,0,0,0,0,1,1,1,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblhills: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0
DATA 0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,0
DATA 0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0
DATA 0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0
DATA 0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0
DATA 0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0
DATA 0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblsand: ',,,,,,,,,,,,,,,
DATA 3,3,0,3,3,3,0,3,3,0,3,3,3,3,3,3
DATA 3,1,3,3,3,2,3,3,3,3,3,3,3,2,3,0
DATA 3,3,3,3,3,3,3,3,1,0,3,3,3,3,3,3
DATA 3,3,0,3,3,3,2,3,3,3,3,3,0,3,1,3
DATA 3,0,3,3,3,1,3,3,3,3,1,3,3,3,3,3
DATA 3,2,3,3,0,3,3,3,0,3,3,0,3,3,0,3
DATA 3,3,3,3,0,3,3,2,3,2,3,3,3,3,3,2
DATA 3,3,0,3,3,3,3,3,3,1,3,0,3,0,3,3
DATA 3,3,3,3,1,3,0,3,0,3,3,3,3,1,3,0
DATA 3,3,3,3,3,3,3,3,3,3,3,1,3,3,3,3
DATA 3,2,0,3,0,2,3,3,3,3,0,3,0,3,3,3
DATA 3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,0
DATA 3,1,3,3,3,1,3,3,3,3,3,3,3,1,3,3
DATA 3,3,3,0,3,3,3,3,3,3,2,3,0,3,3,3
DATA 3,0,3,3,3,0,3,0,3,3,3,1,3,3,3,0
DATA 3,3,3,2,3,3,3,3,3,3,3,3,3,3,0,3
lblmushroom: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,2,3,1,3,3,3,1,3,3,3,3,1,3,2,0
DATA 0,2,3,3,3,3,3,3,3,3,1,3,3,3,2,0
DATA 0,2,1,3,1,3,1,3,1,3,3,3,3,1,2,0
DATA 0,2,3,3,3,3,3,3,3,3,1,3,3,3,2,0
DATA 0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,2,3,3,3,3,2,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblflower: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,0,2,0,2,0,0,0,0,0
DATA 0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0
DATA 0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblmermah1: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0
DATA 0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,1,0,0,0,2,2,2,2,0,0,0,1,0,0
DATA 0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0
DATA 0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0
lblmermah2: ',,,,,,,,,,,,,,,
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0
DATA 0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0
DATA 0,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0
DATA 0,0,1,0,0,0,2,2,2,2,0,0,0,1,0,0
DATA 0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0
DATA 0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0
DATA 0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0
lblDiamond:
DATA 0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0
DATA 0,0,3,3,3,1,1,1,1,1,3,3,3,0,0,0
DATA 0,3,1,1,1,1,1,1,1,1,1,1,1,3,0,0
DATA 3,1,3,1,1,1,1,1,1,1,1,1,3,1,3,0
DATA 3,1,1,3,3,3,3,3,3,3,3,3,1,1,3,0
DATA 3,1,1,1,3,1,1,1,1,1,3,1,1,1,3,0
DATA 0,3,1,3,1,1,1,1,1,1,1,3,1,3,0,0
DATA 0,0,3,1,1,1,1,1,1,1,1,1,3,0,0,0
DATA 0,0,3,1,1,1,1,1,1,1,1,1,3,0,0,0
DATA 0,0,0,3,1,1,1,1,1,1,1,3,0,0,0,0
DATA 0,0,0,3,1,1,1,1,1,1,1,3,0,0,0,0
DATA 0,0,0,0,3,1,1,1,1,1,3,0,0,0,0,0
DATA 0,0,0,0,3,1,1,1,1,1,3,0,0,0,0,0
DATA 0,0,0,0,0,3,1,1,1,3,0,0,0,0,0,0
DATA 0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblKey:
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0
DATA 0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0
DATA 0,2,2,0,0,0,2,2,2,2,2,2,2,2,2,0
DATA 0,2,2,0,0,0,2,2,2,2,2,2,2,2,2,0
DATA 0,2,2,0,0,0,2,2,0,0,2,0,2,0,2,0
DATA 0,2,2,2,2,2,2,2,0,0,2,0,2,0,2,0
DATA 0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lblLock:
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
DATA 0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,0,1,3,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,0,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,0,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,0,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,0,1,1,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,0,0,0,1,1,1,1,0,0
DATA 0,0,1,3,1,1,1,1,1,1,1,1,1,1,0,0
DATA 0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0
DATA 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

'room1,,,,,,,,,,,,,,,,
lblroom1:
DATA 12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,14,99,99,99,14,99,99,99,99,99,99,99,99,99
DATA 12,17,17,16,17,17,99,99,10,99,99,99,10,99,99
DATA 12,99,24,99,24,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,10,99,99,99,99,99,99,10,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,27,27,27,27,27,99,99,99,99,99,99
'room2
lblroom2:
DATA 12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,12,12,12,12,12
DATA 99,99,99,99,99,99,99,10,99,99,99,99,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,12,12,12
DATA 99,99,10,99,99,99,99,99,99,99,99,99,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,12,12,12,12
DATA 99,99,99,99,21,99,21,99,99,99,99,12,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,12,12
DATA 99,99,99,99,21,99,21,99,99,99,99,99,99,12,12
DATA 99,99,10,99,99,99,99,99,10,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
'room3
lblroom3:
DATA 12,99,27,27,27,27,27,27,27,27,27,27,99,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,99,27,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,27,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,27,99,99
DATA 12,99,27,27,10,27,27,27,27,27,27,27,27,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,27,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,99,99,99
DATA 12,99,27,27,27,27,27,27,27,10,27,27,27,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,99,99,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,99,27,99
DATA 12,99,27,27,27,27,27,27,27,27,27,27,27,99,99
DATA 12,99,27,99,99,99,99,99,27,99,27,99,99,27,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
'room4
lblroom4:
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,10,99,99,99,99,12
DATA 99,99,99,99,22,99,99,99,99,99,99,99,99,12,12
DATA 99,99,22,22,22,22,99,99,99,99,99,99,99,12,12
DATA 99,99,99,22,22,22,22,99,99,99,99,99,99,99,12
DATA 99,99,99,22,22,22,22,22,99,99,99,99,12,99,12
DATA 99,99,99,99,99,22,22,99,99,99,99,99,12,30,12
DATA 99,99,99,99,99,99,99,99,99,99,10,99,12,12,12
DATA 99,10,99,99,99,99,99,99,99,99,99,12,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,12,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,12,12,12
'room5
lblroom5:
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,99,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,99,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,99,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
lblroom6: 'room6
DATA 99,99,99,99,99,99,99,99,99,99,99,99,12,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,12,12
DATA 99,99,99,99,99,25,99,99,99,99,99,99,99,12,12
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,25,99,99,99,99,99,99,99,99,12
DATA 99,99,25,99,99,99,99,99,99,99,99,99,99,99,12
DATA 99,99,99,99,99,99,99,99,99,25,99,99,99,99,10
DATA 99,99,99,25,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,25,99,99,99,99,99,99,23,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,10,10,10
lblroom7: 'room7
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,31,33,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,99,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,22,99,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,22,22,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,22,22,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,22,22,99,99,99,99,99,99,99,99,99
DATA 22,22,22,22,22,22,22,99,99,99,99,99,99,99,99
lblroom8: 'room8
DATA 99,99,99,99,99,99,99,99,99,99,99,99,10,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,25,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,25,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,10,10,11
DATA 99,99,99,99,99,99,99,99,99,99,99,99,10,10,11
DATA 99,99,27,99,99,99,99,99,99,99,99,99,11,10,10
DATA 99,99,99,99,99,99,99,99,99,99,25,99,99,10,11
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,25,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
lblroom9: 'room9
DATA 12,99,99,99,22,22,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,22,22,99,99,99,99,99,99,99,99,99
DATA 12,99,99,22,22,22,99,99,99,99,99,99,99,99,99
DATA 12,99,99,22,22,22,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,22,22,99,99,99,99,99,99,99,99,99
DATA 12,99,99,99,22,22,99,99,99,99,99,99,99,99,99
DATA 12,14,16,15,22,22,22,22,22,99,99,99,99,99,99
DATA 12,99,99,99,99,99,22,22,22,99,99,99,99,99,99
DATA 12,99,99,99,99,99,99,99,22,22,99,99,99,99,99
DATA 12,12,99,99,99,99,99,99,32,99,99,99,99,99,99
DATA 12,12,11,11,10,10,10,11,10,10,11,10,11,11,11
DATA 11,11,11,11,10,10,10,10,10,10,11,10,10,10,10
DATA 12,11,11,10,10,10,10,10,11,10,10,10,10,10,10
lblroom10: 'room10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,99,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,29,99,99,10,10
DATA 99,99,99,99,99,99,99,99,99,99,99,99,99,10,10
DATA 99,99,99,99,99,10,10,99,99,99,99,99,99,99,10
DATA 11,11,11,10,10,10,10,10,10,10,11,11,11,11,10
DATA 99,11,11,10,10,10,10,10,10,10,10,10,10,10,10
DATA 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
lblroom11: '11
DATA 13,13,13,13,13,13,13,13,13,13,13,13,13,13,13
DATA 13,99,99,99,99,99,99,99,99,99,99,99,99,99,13
DATA 13,99,13,13,13,13,99,13,99,13,13,99,13,13,13
DATA 13,99,13,99,99,99,99,13,99,13,99,99,99,28,13
DATA 13,99,13,99,99,99,99,13,99,13,99,99,99,99,13
DATA 13,99,13,99,99,13,99,13,99,13,99,99,99,99,13
DATA 13,99,13,99,99,13,99,13,99,13,99,99,99,99,13
DATA 13,99,13,99,99,13,99,13,99,13,99,99,99,99,13
DATA 13,99,13,13,13,13,99,13,99,13,13,13,13,99,13
DATA 13,99,99,99,99,13,99,13,99,13,99,99,99,99,13
DATA 13,99,99,99,99,13,99,13,99,13,99,99,99,99,13
DATA 13,13,13,13,13,13,13,13,99,13,13,13,13,13,13
DATA 13,99,99,99,99,99,99,13,99,13,99,99,99,99,13
DATA 13,13,13,13,13,13,13,13,99,13,13,13,13,13,13

lblwords1:
DATA 14,Princess,Red,lived,in,the,kingdom,of,Typlandia,where,everyone,practiced,their,typing,skills.
lblwords2:
DATA 20,She,defeated,her,enemies,by,using,her,typing,skills,every,correct,letter,made,her,enemies,weak,but,mistakes,hurt,her.,
lblwords3:
DATA 29,Once,upon,a,time,there,was,a,kingdom,In,the,kingdom,lived,a,king,and,his,daughter.,Red,was,her,name.,She,was,an,expert,in,the,typing,arts.
lblwords4:
DATA 23,The,king,became,ill,he,needed,a,magic,potion,to,cure,his,disease,but,nobody,had,the,correct,ingredients,to,make,the,potion.
lblwords5:
DATA 25,The,kings,advisor,Mermah,told,Red,to,get,the,necessary,ingredients,to,save,her,father,these,ingredients,included,an,apple,a,mushroom,and,a,flower.
lblwords6:
DATA 15,once,the,ingredients,were,gathered,Mermah,could,put,together,the,recipe,for,the,magic,potion.
lblwords7:
DATA 9,The,quick,brown,fox,jumped,over,the,lazy,dog.
lblwords8:
DATA 9,The,rain,in,Spain,falls,mainly,on,the,plain!
lblwords9:
DATA 9,Suzie,sells,sea,shells,down,by,the,sea,shore.
lblwords10:
DATA 7,Waltz,nymph,for,quick,jigs,vex,Bud.
lblwords11:
DATA 7,Sphinx,of,black,quartz,judge,my,vow.
lblwords12:
DATA 6,Quick,zephyrs,blame,vexing,daft,Jim.
lblwords13:
DATA 6,How,quickly,daft,jumping,zebras,vex.
lblwords14:
DATA 6,The,five,boxing,wizards,jump,quickly.
lblwords15:
DATA 7,Jackdaws,love,my,big,sphinx,of,quartz.
lblwords16:
DATA 8,Jinxed,wizards,pluck,ivy,from,the,big,quilt.
lblwords17:
DATA 7,Heavy,boxes,perform,quick,waltzes,and,jigs.
lblwords18:
DATA 5,Amazingly,few,discotheques,provide,jukeboxes.
lblwords19:
DATA 10,Sixty,zippers,were,quickly,picked,from,the,woven,jute,bag.
lblwords20:
DATA 8,Crazy,Fredericka,bought,many,very,exquisite,opal,jewels.
lblwords21:
DATA 8,How,razorback-jumping,frogs,can,level,six,piqued,gymnasts!
lblwords22:
DATA 10,We,promptly,judged,antique,ivory,buckles,for,the,next,prize.
lblwords23:
DATA 9,Whenever,the,black,fox,jumped,the,squirrel,gazed,suspiciously.
lblwords24:
DATA 14,A,quart,jar,of,oil,mixed,with,zinc,oxide,makes,a,very,bright,paint.
lblwords25:
DATA 12,The,job,requires,extra,pluck,and,zeal,from,every,young,wage,earner.
lblwords26:
DATA 15,A,mad,boxer,shot,a,quick,gloved,jab,to,the,jaw,of,his,dizzy,opponent.
lblwords27:
DATA 10,Jaded,zombies,acted,quaintly,but,kept,driving,their,oxen,forward.
lblwords28:
DATA 20,Jellylike,above,the,high,wire,six,quaking,pachyderms,kept,the,climax,of,the,extravaganza,in,a,dazzling,state,of,flux.
lblwords29:
DATA 20,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No,No
lblwords30:
DATA 30,MeRmAh,you,liTTle,weasel,YOU,havE,bEtRayed,my,FATher,for,the,last,time,I,shall,defeat,you,with,my,typing,SKILLS!,#,$,%,#,&,*,KAblam!,BOOM!,HaDoUkEn!

