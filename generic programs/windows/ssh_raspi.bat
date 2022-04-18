@echo off

set username="pi"
set ip="192.168.137.10"
set password="doobeedo"

Title Raspberry Pi SSH
cd %~dp0 

@echo off

start wt -p "Command Prompt" plink -ssh %username%@%ip% -pw %password%

exit