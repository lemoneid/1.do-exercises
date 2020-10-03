#!/bin/bash
Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval `awk -v UserSum=0 'BEGIN{FS=":"} $3>999{UserSum+=1; printf("Users["UserSum"]=%s", $1)}' /etc/passwd`
echo "$UserSum ${Users[1]}"
