@echo off

@REM set lib\x64 as working dir and run the executable
start /D %~dp0\..\lib\x64 %~dp0\GameServer_x64.exe