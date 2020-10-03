#!/bin/bash

for (( i = 1; i < 3; i++ )); do
    eval `cat /proc/stat | head -n +1 | awk -v tmp_total=0 -v tmp_idle=0 '{for(i=2; i<=NF; i++){tmp_total+=$i;}; tmp_idle=$5} END {printf("Total[$i]=%d; Idle[$i]=%d", tmp_total,tmp_idle)}'`
    sleep 0.5s
done
echo "${Total[*]} // ${#Total[@]} ${Idle[*]}"


