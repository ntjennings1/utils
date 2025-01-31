Rem Attempts to disable Wi-Fi interface.
:netcheck
	@echo OFF

	cls
	echo please wait ...

	netsh interface set interface Wi-Fi disabled
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