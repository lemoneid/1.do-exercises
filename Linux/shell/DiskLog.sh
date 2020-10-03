#!/bin/bash

Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval `df -m | tail -n +2 | awk '{printf("PartName["NR"]=%s;PartSum["NR"]=%d;PartLeft["NR"]=%d;PartPercent["NR"]=%s;" , $6, $2, $4, $5)}'`

DiskSum=0
DiskLeft=0
DiskPercnt=0

for (( i = 1; i <= ${#PartName[@]}; ++i )); do
    echo "${Time} 1 ${PartName[$i]} ${PartSum[$i]} ${PartLeft[$i]} ${PartPercent[$i]}"
    DiskSum=$[ ${DiskSum}+${PartSum[$i]} ]
    DiskLeft=$[ ${DiskLeft}+${PartLeft[$i]} ]
done
DiskPercnt=`echo "(${DiskSum}-${DiskLeft})*100/${DiskSum}" | bc `
echo "${Time} 0 disk ${DiskSum} ${DiskLeft} ${DiskPercnt}%"
