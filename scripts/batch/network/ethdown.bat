Rem Attempts to disable Ethernet interface.
:netcheck
	@echo OFF

	cls
	echo please wait ...

	netsh interface set interface Ethernet disabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is connected.
	:noerror
	echo Disabled successfully.
	EXIT /B

	Rem Displays the device is not connected
	:error
	echo Error in disabling.
	EXIT /B