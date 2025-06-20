#!/bin/bash

# Turns the machine off
#
# @return null
function off(){
    sudo shutdown now
}

# Runs the off function
off