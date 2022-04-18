#!/bin/bash
# Scripted By Jesvi Jonathan
# Requires SCRCPY Installed & Set In System Environmental Variables

Title Headless Connect (By Jesvi Jonathan)
cd %~dp0 


set mode="1"
# change mode to 1 to get menu or 0 to auto connect 

# or 

set var=%~n0
echo %var%
# add a 0 at the end of this file's name for auto mode, else leave it anything other than 0 to bypass 

set ip="192.168.0.109"
# IP of target device, (Home IP recommended)


@echo off
cls

if %var:~-1%==0 goto :case-3
if %mode%=="0" goto :case-3

:start
echo.
echo Healess Connect v0.1
echo. 
echo 1. USB / ADB 
echo 2. Wireless / TCP/IP
echo 3. Auto Mode
echo 4. Exit
echo. 
choice /c 1234 /m "Please choose an option"

goto :case-%errorlevel%
:case-1
echo -Stopping ADB Services..
adb kill-server
echo -Scanning Attached  Devices..
adb devices
echo -Starting Connection..
scrcpy || echo Retrying.. & goto :case-1
pause
goto :case-4

:case-2
echo -Stopping ADB Services..
adb kill-server
echo -Scanning Devices Over IP (%ip%)..
adb devices
echo -Starting Connection..
scrcpy --tcpip=%ip% -b 1M -m 1024 || echo Retrying.. & goto :case-2
pause
goto :case-4

:case-3

if %mode%=="0" echo Headless Connect (Auto Mode)
if %var:~-1%==0 echo Headless Connect (Auto Mode 0-End-File-Name)
echo.
echo.
echo -Close The Main (*This) Terminal To Quit..
echo -Stopping ADB Services..
adb kill-server
echo -Scanning Devices..
echo.
adb devices
echo.
echo -Connecting To Attached Devices.. & scrcpy || echo. & echo -Connecting To Device Over IP (%ip%).. & scrcpy --tcpip=%ip% -b 1M -m 1024 || echo Retrying.. & goto :case-3
goto :start

:case-4
echo.
echo By Jesvi Jonathan, Cheers !
sleep 1
exit

exit 1