@echo off
python convert.py >graphics.inc
copy /Y graphics.inc ..\..\Assembler

