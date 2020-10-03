#!/bin/bash
if [[ $# != 1 ]]; then
    echo "Please enter only the last dynamic average (%)"
    exit 1
fi
Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval `free -m | head -n +2 | tail -n -1 | awk '{printf("Total=%s; Used=%s;", $2, $3);}'`

Left=$[ ${Total}-${Used} ]
UsedPercent=`echo "scale=1; ${Used}*100/${Total}" | bc`
Average=`echo "scale=1; 0.3*${1}+0.7*${UsedPercent}" | bc`

echo "$Time ${Total}M ${Left} ${UsedPercent}% ${Average}%"
