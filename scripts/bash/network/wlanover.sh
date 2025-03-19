function wlanover()
{
    sudo ifconfig $1 down
    sudo ifconfig $1 up
}

wlanover