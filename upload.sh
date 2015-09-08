#!/bin/bash 

comment="$1"
git add .; 
git commit -m "$comment"; 
git push origin master
expect "Enter passphrase for key '/home/had/hideyuki/.ssh/id_rsa': "
send XXXX
interact
