Rem Shows network adapter state(s)
:netstate

    @echo off

    cls
    echo Retrieving network adapter information ...

    wmic nic get Name, AdapterType, Description, GUID, Index, MACAddress, Manufacturer, NetConnectionID, NetConnectionStatus, ServiceName /value