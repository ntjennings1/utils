Rem Attempts to enable the Wi-Fi interface.
:wlanup
	@echo OFF

	cls
	echo please wait ...

	:: Use NETSH to manipulate Wi-Fi interface.
	netsh interface set interface Wi-Fi enabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	:: Display script success.
	:noerror
	echo Enabled successfully.
	EXIT /B

	:: Display script failure.
	:error
	echo Error in enabling.
	EXIT /B