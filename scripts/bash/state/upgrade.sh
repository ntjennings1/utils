#!/bin/bash

# Upgrades the machine
#
# @return null
function upgrade(){
    sudo apt-get upgrade -y
}

# Runs the upgrade function
upgrade