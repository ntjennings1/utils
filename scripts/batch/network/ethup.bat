Rem Attempts to enable Ethernet interface.
:netcheck
	@echo OFF

	cls
	echo please wait ...

	netsh interface set interface Ethernet enabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is connected.
	:noerror
	echo Enabled successfully.
	EXIT /B

	Rem Displays the device is not connected
	:error
	echo Error in enabling.
	EXIT /B