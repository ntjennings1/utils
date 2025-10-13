Rem Attempts to enable the Ethernet interface.
:ethup
	@echo OFF

	cls
	echo please wait ...
	
	:: Use NETSH to manipulate ETHERNET interface.
	netsh interface set interface Ethernet enabled
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