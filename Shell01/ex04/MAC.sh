ifconfig | grep 'ether' | grep -v 'autoselect' | awk '{print $2}'
