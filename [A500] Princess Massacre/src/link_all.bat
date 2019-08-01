@echo off
setlocal enableextensions enabledelayedexpansion

echo Linking
set cl=vc -notmpfile
for /R %%O in (%3*.o) do (
	set cl=!cl! "%%O"
)
set cl=%cl% -lamiga -o %~s1%2
call %cl%
