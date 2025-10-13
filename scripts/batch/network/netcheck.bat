Rem Checks if the device is connected to the Internet.
:netcheck
	@echo OFF

	cls
	echo please wait ...

	:: Use ping to test Internet connection.
	ping -n 1 www.google.com >nul

	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	:: Display script success.
	:noerror
	echo Connected.
	EXIT /B

	:: Display script failure.
	:error
	echo Not connected.
	EXIT /B