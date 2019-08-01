@echo off
echo "ESTA ES LA VERSION 1.10"
set Z88DK_PATH=c:\z88dk10
set PATH=%Z88DK_PATH%\bin;%PATH%
set Z80_OZFILES=%Z88DK_PATH%\Lib\
set ZCCCFG=%Z88DK_PATH%\Lib\Config\
echo ### COMPILANDO SCRIPT ###
rem cd ..\script
rem no olvides cambiar el 24 por el nº de pantallas
rem msc advtime.spt msc.h 40
rem copy *.h ..\dev
rem cd ..\dev
echo -------------------------------------------------------------------------------
echo ### REGENERANDO MAPA ###
rem cd ..\map
rem cambia ANCHO y ALTO por los valores de tu mapa:
rem ..\utils\mapcnv mapa.map 8 5 15 10 15
rem copy mapa.h ..\dev
rem cd ..\dev
echo -------------------------------------------------------------------------------
echo ### COMPILANDO GUEGO ###
zcc +zx -vn advtime.c -o advtime.bin -lndos -lsplib2 -zorg=24200
echo -------------------------------------------------------------------------------
echo ### CONSTRUYENDO CINTA ###
rem cambia LOADER por el nombre que quieres que salga en Program:
..\utils\bas2tap -a10 -sadvtime loader.bas loader.tap
..\utils\bin2tap -o screen.tap -a 16384 loading.bin
..\utils\bin2tap -o main.tap -a 24200 advtime.bin
copy /b loader.tap + screen.tap + main.tap advtime.tap
echo -------------------------------------------------------------------------------
echo ### LIMPIANDO ###
del loader.tap
del screen.tap
del main.tap
del advtime.bin
echo -------------------------------------------------------------------------------
echo ### DONE ###
pause