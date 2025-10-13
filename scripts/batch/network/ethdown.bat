Rem Attempts to disable the Ethernet interface.
:ethdown
	@echo OFF

	cls
	echo please wait ...

	:: Use NETSH to manipulate ETHERNET interface.
	netsh interface set interface Ethernet disabled
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