#!/bin/bash -x

comment="$1"
echo \"$comment\"
git add .; git commit -m "$comment"; git push origin master
expect "Enter passphrase for key '/home/had/hideyuki/.ssh/id_rsa': "
send "Pinkyslot123\r"
interact
