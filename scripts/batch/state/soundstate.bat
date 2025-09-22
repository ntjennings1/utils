Rem Shows sound device state(s).
:soundstate

    @echo off

    cls
    echo Retrieving sound device information ...

    wmic sounddev get Name, Status, DeviceID, CreationClassName, Manufacturer /value