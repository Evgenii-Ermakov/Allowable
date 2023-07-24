@echo off

set NAME=vs17_64
echo creating %name% dir...

if not exist %name%.build md %name%.build
cd /D %name%.build

setlocal
@set params=

cmake -G "Visual Studio 17 2022" %params% ../

cd ..