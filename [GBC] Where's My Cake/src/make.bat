@echo off
set PROJECT=CAKE2016
set ARGS=-Wl-m -Wl-yp0x143=0x80 -Wl-yt1 -Wl-yo4
lcc -Wf-bo1 -c -o bank/bank1.o bank/bank1.c
lcc -Wf-bo2 -c -o bank/bank2.o bank/bank2.c
lcc -Wf-bo3 -c -o bank/bank3.o bank/bank3.c
lcc -c -o main.o main.c
lcc %ARGS% -o %PROJECT%.GBC main.o bank/bank1.o bank/bank2.o bank/bank3.o

del bank\*.o
del *.map
del main.o