#!/bin/bash

# Updates the machine
#
# @return null
function update(){
    sudo apt-get update -y
}

# Runs the update function
update