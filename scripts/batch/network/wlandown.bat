Rem Attempts to disable the Wi-Fi interface.
:wlandown
	@echo OFF

	cls
	echo please wait ...

	:: Use NETSH to manipulate Wi-Fi interface.
	netsh interface set interface Wi-Fi disabled
	if not errorlevel 1 goto :noerror
	if errorlevel 1 goto :error

	:: Display script success.
	:noerror
	echo Disabled successfully.
	EXIT /B

	:: Display script failure.
	:error
	echo Error in disabling.
	EXIT /B