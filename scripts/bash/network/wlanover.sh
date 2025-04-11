#!/bin/bash

# Restarts a wireless interface
#
# @param $1 : The name of the wireless interface
function wlanover()
{
    sudo ifconfig $1 down
    sudo ifconfig $1 up
}

# Runs the wlanover function
wlanover