Rem Attempts to disconnect from a Wireless Access Point.
:wlandiscon
	@echo OFF

	cls
	echo please wait ...

	:: Use NETSH to maniputale Wlan interface.
	netsh wlan disconnect
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	:: Display script success.
	:noerror
	echo Disconnected successfully.
	EXIT /B

	:: Display script failure.
	:error
	echo Error in disconnecting.
	EXIT /B