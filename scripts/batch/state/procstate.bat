Rem Shows state of running processes.
:procstate
    
    @echo off

    cls
    echo Retrieving process information ...

    wmic process get Name, ProcessID, WorkingSetSize, CommandLine /value