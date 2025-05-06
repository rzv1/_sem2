#!bin/bash

users=`awk '{print $1}' who.fake | sort | uniq`

for user in $users; do
    process_count=`awk '$1 == "$user" {count++} END {print count}' ps.fake`
    echo "$user $process_count"
done
