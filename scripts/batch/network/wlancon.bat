Rem Attempts to connect to a Wireless Access Point.
:wlancon
	@echo OFF

	cls
	echo please wait ...

	set ssid %1

	netsh wlan disconnect
	netsh wlan connect %1%
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is connected.
	:noerror
	echo Connected successfully.
	EXIT /B

	Rem Displays an error in connecting.
	:error
	echo Error in connecting.
	EXIT /B