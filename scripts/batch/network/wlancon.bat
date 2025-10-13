Rem Attempts to connect to a Wireless Access Point.
:wlancon
	@echo OFF

	cls
	echo please wait ...

	:: Accept SSID from command line.
	set ssid %1
	
	:: Use NETSH to maniputale Wlan interface.
	netsh wlan disconnect
	netsh wlan connect %1%
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	:: Display script success.
	:noerror
	echo Connected successfully.
	EXIT /B

	:: Display script failure.
	:error
	echo Error in connecting.
	EXIT /B