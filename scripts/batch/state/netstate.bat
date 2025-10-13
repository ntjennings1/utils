Rem Shows network adapter state(s)
:netstate

    @echo off

    cls
    echo Retrieving network adapter information ...

    :: Use WMIC to get Network adapter characteristics.
    wmic nic get Name, AdapterType, Description, GUID, Index, MACAddress, Manufacturer, NetConnectionID, NetConnectionStatus, ServiceName /value