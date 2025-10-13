Rem Shows state of running processes.
:procstate
    
    @echo off

    cls
    echo Retrieving process information ...

    :: Use WMIC to get Process characteristics
    wmic process get Name, ProcessID, WorkingSetSize, CommandLine /value