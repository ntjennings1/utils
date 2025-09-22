Rem Shows cpu state.
:cpustate

    @echo off

    cls
    echo Retrieving cpu information ...

    wmic cpu get Name, SystemName, LoadPercentage, ThreadCount, NumberOfCores, NumberOfEnabledCore, NumberOfLogicalProcessors, Status, CpuStatus, CurrentClockSpeed, MaxClockSpeed, ProcessorId /value