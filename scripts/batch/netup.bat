Rem Attempts to enable Wi-Fi interface.
:netcheck
	@echo OFF

	cls
	echo please wait ...

    netsh interface set interface Wi-Fi enabled
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