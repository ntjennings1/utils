Rem Shows disk state.
:diskstate

    @echo off

    cls
    echo Retrieving disk information ...

    wmic OS get Name, Status, BootDevice, EncryptionLevel, SystemDirectory, SystemDevice, MUILanguages, RegisteredUser, OSArchitecture /value