..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o ishallbequeen.o ishallbequeen.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo1 -Wf-ba1 -c -o rombank1.o rombank1.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo2 -Wf-ba2 -c -o rombank2.o rombank2.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo3 -Wf-ba3 -c -o rombank3.o rombank3.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo4 -Wf-ba4 -c -o rombank4.o rombank4.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo5 -Wf-ba5 -c -o rombank5.o rombank5.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo6 -Wf-ba6 -c -o rombank6.o rombank6.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf-bo7 -Wf-ba7 -c -o rombank7.o rombank7.c
..\bin\lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wl-yt2 -Wl-yo8 -Wl-ya1 -yp0x143=0x80 -yp0x146=0x03 -yp0x14B=0x33 -o ishallbequeen.gb ishallbequeen.o rombank1.o rombank2.o rombank3.o rombank4.o rombank5.o rombank6.o rombank7.o
pause