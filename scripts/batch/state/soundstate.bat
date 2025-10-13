Rem Shows sound device state(s).
:soundstate

    @echo off

    cls
    echo Retrieving sound device information ...

    :: Use WMIC to get Sound device characteristics
    wmic sounddev get Name, Status, DeviceID, CreationClassName, Manufacturer /value