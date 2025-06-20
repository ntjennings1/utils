Rem Attempts to disconnect from a Wireless Access Point.
:wlandiscon
	@echo OFF

	cls
	echo please wait ...

	netsh wlan disconnect
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is connected.
	:noerror
	echo Disconnected successfully.
	EXIT /B

	Rem Displays an error in disconnecting.
	:error
	echo Error in disconnecting.
	EXIT /B