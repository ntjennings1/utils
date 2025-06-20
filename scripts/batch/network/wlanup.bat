Rem Attempts to enable the Wi-Fi interface.
:wlanup
	@echo OFF

	cls
	echo please wait ...

	netsh interface set interface Wi-Fi enabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	Rem Displays the device is enabled.
	:noerror
	echo Enabled successfully.
	EXIT /B

	Rem Displays an error in enabling.
	:error
	echo Error in enabling.
	EXIT /B