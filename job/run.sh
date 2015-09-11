#!/bin/sh

#list1=`ls -1tr tmp/ | head -n 50`
#for file in $list1
for file in tmp/*
do
echo "bsub -q s $file"
bsub -o /dev/null -q s $file
done
