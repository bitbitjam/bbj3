0 PRINT CHR$(147): PRINT "{light blue}     copying rom to ram please wait"
1 POKE 53280,0
2 REM GOSUB 50000: REM Define Item ID
4 REM "Character Set"
5 POKE 56,48
6 POKE 56334,PEEK(56334) AND 254 
7 POKE 1, PEEK(1) AND 251 
8 FOR I = 0 TO 511:POKE I+12288,PEEK(I+53248):NEXT 
9 POKE 1, PEEK(1) OR 4 
10 POKE 56334,PEEK(56334) OR 1 
11 PRINT "         applying character set"
12 GOSUB 10000
14 PW = 0
15 BI = 30
16 REM PRINT "---"
17 MV=8: SW = 0: REM MV = Move amount, SW = Sword Power
18 XLB = 20
19 XRB = 240
20 YLB = 58
21 YRB = 120
22 REM FOR I = 12288+35*8 TO 12288+(35*8)+7: READ J: POKE I, J: PRINT J: NEXT I
32 MC = 3: REM "How many Characters are Modified"
90 POKE 53272,(PEEK(53272) AND 240) + 12
95 GOSUB 15000: REM Scrolling Text Effect
98 PRINT CHR$(147)
99 AC = 35: LS$ = "102,102,255,102,255,102,102,0": GOSUB 40000
120 PRINT CHR$(147): REM clear the screen
130 PRINT ""
140 PRINT "  @@@@@@@@@@@@@@@"
150 PRINT " @@@@@@@@@@@@@@@@@"
160 PRINT " @@ @@@@@@@@@@@ @@"
170 PRINT " @@@           @@@       CBILKK DAGERS"
180 PRINT " @@@  @     @  @@@       shubshub 2016"
190 PRINT " @@@  @     @  @@@        #bitbitjam3"
200 PRINT " @@@           @@@        hit any key"
210 PRINT " @@@           @@@"
220 PRINT " @@@    @@     @@@"
230 PRINT " @@@           @@@"
240 PRINT "  @ @@@@@@@@@@@ @"
250 PRINT "     @       @      @"
260 PRINT "     @       @     @"
270 PRINT "     @       @    @@"
280 PRINT "     @      @@@@@@@@"
290 PRINT "     @       @    @"
300 PRINT "     @       @   @"
310 PRINT "     @       @"
320 PRINT "     @       @"
330 PRINT "     @       @"
340 PRINT "      @@@@@@@"
350 PRINT "       @   @"
360 PRINT "       @   @"
380 POKE 198,0: WAIT 198, 1
385 LS$ = "000,102,255,255,255,255,153,000"
388 AC = 35
389 GOSUB 40000
390 REM "How to play"
400 PRINT CHR$(147): REM Screen Clear
410 PRINT "play as a ghost pepper"
420 PRINT "get to the heart of the person"
430 PRINT "don't touch walls otherwise"
440 PRINT "you will activate to early and die"
450 PRINT "the goal is to cause so much red hot carnage"
460 PRINT ""
470 PRINT "don't move to quickly"
480 PRINT "otherwise it will lag"
500 PRINT "my jam games are never that great"
1000 POKE 198,0: WAIT 198, 1
1100 REM "Sprite Init"
1108 PRINT CHR$(147)
1109 GOSUB 35000
1110 poke 2040,13
1115 GOSUB 45000: REM Draw World first Part
1120 for i=0 to 62:read a:poke 832+i,a:next i
1130 poke 53287,2 : REM sprite 0 color
1140 poke 53269,1 : REM Sprite Enable Register
1150 poke 53248,0+8*19 : REM Sprite 0 X Position Lower Byte
1160 poke 53249,58 :REM Sprite 0 Y position
1170 poke 53264,0 :REM Sprite 0 X position High byte, only last bit used
2500 REM "Movement Code, 8000 = Up, 9000 = Down, 10000 = Left, 11000 = Right"
2510 IP$="": GET IP$: IF IP$="" THEN 2510
2530 REM PRINT "x: " PEEK(53248) "y: " PEEK(53249): REM "Print X, Y"
2540 IF IP$="w" THEN GOSUB 8000
2550 IF IP$="s" THEN GOSUB 8500
2560 IF IP$="a" THEN GOSUB 8750
2570 IF IP$="d" THEN GOSUB 9000
2574 GOSUB 30000
2577 GOSUB 9500
2580 GOTO 2510
8000 REM "Moving Up"
8010 REM PRINT "up"
8019 IF PEEK(53249) <= YLB THEN RETURN
8028 IF PEEK(53249) > YLB THEN POKE 53249, PEEK(53249)-MV
8029 REM IF PEEK(53279) = 1 THEN POKE 53249, PEEK(53249)+MV
8038 RETURN
8500 REM "Moving Down"
8504 REM PRINT "down"
8505 GOSUB 50000
8506 IF PEEK(53249) >= YRB THEN RETURN
8508 IF PEEK(53249) < YRB THEN POKE 53249, PEEK(53249)+MV
8509 REM IF PEEK(53279) = 1 THEN POKE 53249, PEEK(53249)-MV
8510 RETURN
8750 REM "Moving Left"
8751 IF PEEK(53248) <= XLB THEN RETURN
8752 IF PEEK(53248) > XLB THEN POKE53248, PEEK(53248)-MV 
8753 REM IF PEEK(53279) = 1 THEN POKE 53248, PEEK(53248)+MV
8754 REM PRINT "left"
8755 RETURN
9000 REM "Moving Right"
9001 IF PEEK(53248) >= XRB THEN RETURN
9002 IF PEEK(53248) < XRB THEN POKE 53248, PEEK(53248)+MV
9003 REM IF PEEK(53279) = 1 THEN POKE 53248, PEEK(53248)-MV
9004 REM PRINT "right"
9005 RETURN
9500 REM "Collided Sprite 0 with Sprite 1"
9501 IF PEEK(53278)=3 THEN POKE 53269, 1: PRINT "ding!"
9502 RETURN
9999 REM Character Sheets and Other Crap - This stuff is only for the Title Screen
10000 DATA 255,255,255,255,255,255,255,255 : REM CHARACTER 00
10010 DATA 000,000,000,000,000,000,000,000 : REM CHARACTER 45
10015 DATA 225,003,006,199,006,006,230,000 : REM CHARACTER 65
10020 DATA 198,102,006,007,006,102,198,000 : REM CHARACTER 66
10030 DATA 003,006,006,006,006,006,003,000 : REM CHARACTER 67
10035 DATA 007,006,006,007,006,006,007,000 : REM CHARACTER 68
10037 DATA 231,134,134,135,134,134,135,000 : REM CHARACTER 69
10040 DATA 135,193,097,225,097,097,097,000 : REM CHARACTER 71
10050 DATA 097,097,097,225,097,097,097,000 : REM CHARACTER 73
10060 DATA 003,003,003,003,003,227,227,000 : REM CHARACTER 75
10070 DATA 131,131,131,131,131,131,131,000 : REM CHARACTER 76
10075 DATA 231,006,006,199,007,006,230,000 : REM CHARACTER 82
10078 DATA 192,096,096,192,128,192,096,000 : REM CHARACTER 83

10080 FOR I = 12288 TO 12288 + 7: READ J: POKE I,J: NEXT I: REM "Read @"
10090 FOR I = 12288+45*8 TO 12288+(45*8)+7: READ J: POKE I, J: NEXT I: REM "Read -"
10095 FOR I = 12288+65*8 TO 12288+(65*8)+7: READ J: POKE I, J: NEXT I
10100 FOR I = 12288+66*8 TO 12288+(66*8)+7: READ J: POKE I, J: NEXT I: REM "Read C"
10110 FOR I = 12288+67*8 TO 12288+(67*8)+7: READ J: POKE I, J: NEXT I: REM "Read H"
10115 FOR I = 12288+68*8 TO 12288+(68*8)+7: READ J: POKE I, J: NEXT I
10118 FOR I = 12288+69*8 TO 12288+(69*8)+7: READ J: POKE I, J: NEXT I
10120 FOR I = 12288+71*8 TO 12288+(71*8)+7: READ J: POKE I, J: NEXT I: REM "Read I"
10130 FOR I = 12288+73*8 TO 12288+(73*8)+7: READ J: POKE I, J: NEXT I: REM "Read L"
10140 FOR I = 12288+75*8 TO 12288+(75*8)+7: READ J: POKE I, J: NEXT I: REM "Read G"
10150 FOR I = 12288+76*8 TO 12288+(76*8)+7: READ J: POKE I, J: NEXT I: REM "Read K"
10160 FOR I = 12288+82*8 TO 12288+(82*8)+7: READ J: POKE I, J: NEXT I
10170 FOR I = 12288+83*8 TO 12288+(83*8)+7: READ J: POKE I, J: NEXT I
10400 RETURN
10500 REM Character Sheet End
11000 REM Sprite Sheets
11005 REM Sprite 0
11010 DATA 0,0,0
11020 DATA 0,0,0
11030 DATA 0,0,0
11040 DATA 0,0,0
11050 DATA 0,0,0
11060 DATA 0,1,0
11070 DATA 0,1,0
11080 DATA 0,1,0
11090 DATA 0,2,0
11100 DATA 0,7,0
11110 DATA 0,15,0
11120 DATA 0,15,0
11130 DATA 0,31,0
11140 DATA 0,62,0
11150 DATA 0,60,0
11160 DATA 0,120,0
11170 DATA 0,0,0
11180 DATA 0,0,0
11190 DATA 0,0,0
11200 DATA 0,0,0
11210 DATA 0,0,0
15000 REM Cool Thing
16010 AC = 33
16020 LS$ = "000 000 000 000 000 000 000 000" : REM CHARACTER 33
16022 POKE 53280,1
16025 GOSUB 40015
16030 AC = 35
16035 GOSUB 40000
16040 AC = 36
16045 GOSUB 40000
16050 AC = 37
16055 GOSUB 40000
16060 AC = 38
16062 POKE 53280,2
16065 GOSUB 40000
16070 AC = 42
16075 GOSUB 40000
16080 AC = 43
16082 POKE 53280,3
16085 GOSUB 40000
16090 AC = 44
16095 GOSUB 40000
16100 AC = 47
16102 POKE 53280,4
16105 GOSUB 40000
16110 AC = 58
16115 GOSUB 40000
16120 AC = 60
16122 POKE 53280,5
16125 GOSUB 40000
16130 AC = 61
16140 GOSUB 40000
16150 PRINT CHR$(147)
16160 PRINT ""
19819 PRINT ""
19829 PRINT "  ************************************"
19839 PRINT "  *::::::::::::::::::::::::::::::::::*"
19849 PRINT "  *:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&:*"
19859 PRINT "  *:&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&:*"
19869 PRINT "  *:&%############################%&:*"
19879 PRINT "  *:&%#$$$$$$$$$$$$$$$$$$$$$$$$$$#%&:*"
19889 PRINT "  *:&%#$!!!!!!!!!!!!!!!!!!!!!!!!$#%&:*"
19899 PRINT "  *:&%#$!//////////////////////!$#%&:*"
19909 PRINT "  *:&%#$!/,,,,,,,,,,,,,,,,,,,,/!$#%&:*"
19919 PRINT "  *:&%#$!/,magic man shubshub,/!$#%&:*"
19929 PRINT "  *:&%#$!/,  bitbitjam 2016  ,/!$#%&:*"
19939 PRINT "  *:&%#$!/,,,,,,,,,,,,,,,,,,,,/!$#%&:*"
19949 PRINT "  *:&%#$!//////////////////////!$#%&:*"
19959 PRINT "  *:&%#$!!!!!!!!!!!!!!!!!!!!!!!!$#%&:*"
19969 PRINT "  *:&%#$$$$$$$$$$$$$$$$$$$$$$$$$$#%&:*"
19979 PRINT "  *:&%############################%&:*"
19989 PRINT "  *:&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&:*"
19999 PRINT "  *:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&:*"
20009 PRINT "  *::::::::::::::::::::::::::::::::::*"
20019 PRINT "  ************************************"
20029 PRINT ""
21010 AC = 33
21020 LS$ = "255 255 255 255 255 255 255 255" : REM CHARACTER 33
21025 GOSUB 40015
21030 AC = 35
21035 GOSUB 40000
21040 AC = 36
21045 GOSUB 40000
21050 AC = 37
21055 GOSUB 40000
21060 AC = 38
21065 GOSUB 40000
21070 AC = 42
21075 GOSUB 40000
21080 AC = 43
21085 GOSUB 40000
21090 AC = 44
21095 GOSUB 40000
21100 AC = 47
21105 GOSUB 40000
21110 AC = 58
21115 GOSUB 40000
21120 AC = 60
21125 GOSUB 40000
21130 AC = 61
21140 GOSUB 40000
21145 FOR I = 0 TO 500: NEXT I
21150 RETURN
30000 REM "Specific Char Collision"
30005 X = PEEK(53248): REM X of Sprite 0
30008 Y = PEEK(53249): REM Y of Sprite 0
30010 CX = INT(((X - 24)+8) / 8): REM X to Column
30020 CY = INT(((Y - 50)+8) / 8): REM Y to Row
30025 OS = CX + (CY * 40): REM CX and CY to Offset
30030 CC = PEEK(1024+OS): REM Collided Character
30032 IF CC=0 THEN PRINT "ded you touched a " CHR$(CC+64): GOTO 60000
30035 IF CC=17 THEN LS$ = "000 000 000 000 000 000 000": SW = 1: GOSUB 40000
30038 IF CC=35 THEN IF SW=0 THEN PRINT "you ded": GOTO 60000
30039 IF CC=35 THEN IF SW=1 THEN SW=0
30040 IF CC=51 THEN PRINT "you touched a " CHR$(CC+64)
30050 IF CC=52 THEN PRINT "you touched a " CHR$(CC+64)
30060 RETURN
35000 REM Jump here to Redefine a Char Set, AC = The Character Index
35002 AC = 0
35005 LS$ = "255 255 255 255 255 255 255 255": REM Character Num Thing
35010 GOSUB 40000
35020 AC = 17
35030 LS$ = "024,060,060,060,126,126,024,024": REM Q
35040 GOSUB 40000
35050 RETURN
40000 REM Alternate Char Set
40015 LP = 1: REM Character Pointer for LS
40020 FOR Z = 12288+(AC*8) TO 12288+(AC*8)+7:
40025 SR$= MID$(LS$,LP,3): NM = VAL(SR$): LP = LP + 4: POKE Z, NM: NEXT Z
40060 RETURN
45000 REM Draw first world
45010 FOR K=0 TO 25: PRINT "              @          @": NEXT K
45020 RETURN
50000 REM World Gen Thing
50010 N = INT(RND(1)*40)
50015 IF N=13 THENPRINT "              @####  ####@": IF PW > 0 THEN PW = PW-1: RETURN
50025 IF N=14 THENPRINT "              @##  ######@": IF PW > 0 THEN PW = PW-1: RETURN
50035 IF N=15 THENPRINT "              @  ########@": IF PW > 0 THEN PW = PW-1: RETURN
50045 IF N=16 THENPRINT "              @#######  #@": IF PW > 0 THEN PW = PW-1: RETURN
50116 IF BI > 0 THEN BI = BI - 1
50117 IF BI = 0 THEN YRB = YRB + 8: BI = 30
50118 IF YRB > 193 THEN GOTO 55000
50119 IF PW = 1 THEN LS$ = "024,060,060,060,126,126,024,024": GOSUB 40000
50120 IF PW > 0 THEN PW = PW-1: PRINT "              @          @": RETURN
50150 IF N=3 THEN PRINT "              @q         @": PW = 25: RETURN
50160 IF N=4 THEN PRINT "              @ q        @": PW = 25: RETURN
50170 IF N=5 THEN PRINT "              @  q       @": PW = 25: RETURN
50172 IF N=6 THEN PRINT "              @   q      @": PW = 25: RETURN
50174 IF N=7 THEN PRINT "              @    q     @": PW = 25: RETURN
50177 IF N=8 THEN PRINT "              @     q    @": PW = 25: RETURN
50178 IF N=9 THEN PRINT "              @      q   @": PW = 25: RETURN
50179 IF N=10 THENPRINT "              @       q  @": PW = 25: RETURN
50189 IF N=11 THENPRINT "              @        q @": PW = 25: RETURN
50199 IF N=12 THENPRINT "              @         q@": PW = 25: RETURN
50209 PRINT "              @          @"
50219 RETURN
55000 PRINT CHR$(147)
55005 LS$ = "024 024 024 024 000 000 024 000"
55008 AC = 33
55009 GOSUB 40000
55010 PRINT "you managed to survive long enough"
55020 PRINT "and traverse this persons body"
55030 PRINT "far enough to cause enough pain"
55040 PRINT "and carnage with your red hot chilli"
55050 PRINT ""
55060 PRINT "         congratulation !!"
55070 WAIT 1, 32, 32
60000 PRINT CHR$(147)
60010 poke 53269,0
60020 LS$ ="102,102,255,102,255,102,102,0"
60030 AC = 35
60040 GOSUB 40000
61000 PRINT "{white}#bitbitjam3"
61010 PRINT ""
61020 PRINT ""
61030 PRINT ""
61040 PRINT ""
61050 PRINT ""
61060 PRINT ""
61070 PRINT ""
61080 PRINT ""
61090 PRINT ""
61100 PRINT "               game  over"
61110 PRINT ""
61120 PRINT ""
61130 PRINT ""
61140 PRINT ""
61150 PRINT ""
61160 PRINT ""
61170 PRINT ""
61180 PRINT ""
61190 PRINT "                 anykey"
61200 PRINT ""
61240 PRINT "                           shubshub 2016"
61250 POKE 198,0: WAIT 198, 1
61255 CLR
61260 RUN      



