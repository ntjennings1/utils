Rem Checks if the device is connected to the Internet.
:netcheck
	@echo OFF

	cls
	echo please wait ...

	ping -n 1 www.google.com >nul

	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is connected.
	:noerror
	echo Connected.
	EXIT /B

	Rem Displays the device is not connected.
	:error
	echo Not connected.
	EXIT /B