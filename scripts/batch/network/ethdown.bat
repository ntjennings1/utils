Rem Attempts to disable the Ethernet interface.
:ethdown
	@echo OFF

	cls
	echo please wait ...

	netsh interface set interface Ethernet disabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is disabled.
	:noerror
	echo Disabled successfully.
	EXIT /B

	Rem Displays an error in disabling.
	:error
	echo Error in disabling.
	EXIT /B