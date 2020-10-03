#!/bin/bash
Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval `cat /proc/loadavg | awk '{printf("Load1=%s; Load2=%s; Load3=%s", $1, $2, $3)}'`
#echo "$Time $Load1 $Load2 $Load3"

for (( i = 1; i < 3; i++ )); do
    eval `cat /proc/stat | head -n +1 | awk -v tmp_total=0 -v tmp_idle=0 '{for(i=2; i<=NF; i++){tmp_total+=$i;}; tmp_idle=$5} END {printf("Total[$i]=%d; Idle[$i]=%d", tmp_total,tmp_idle)}'`
    sleep 0.5s
done

#echo "${Total[*]} // ${#Total[@]} ${Idle[*]}"

ans_total=$[ ${Total[2]}-${Total[1]} ]
ans_idle=$[ ${Idle[2]}-${Idle[1]} ]
#echo "ans_total = $ans_total; ans_idle = $ans_idle"

PercntCpu=`echo "scale=2; (${ans_total}-${ans_idle}) * 100 /${ans_total} " | bc`
#echo "PercntCpu = $PercntCpu"

CountCPu=`ls /sys/class/thermal/ | grep 'thermal_zone'| wc -l`
#echo "$PercntCpu $CountCPu"

function getFlag {
    if [ $1 -lt 50 ] 
    then
        echo "normal"
    elif [ $1 -lt 70 ]
    then 
        echo "note"
    else 
        echo "warning"
    fi
}

readonly path="/sys/class/thermal/thermal_zone"
for ((i=0; i<CountCPu; i++)); do
    tmp_path=$path"$i/temp"
    #echo "$tmp_path"
    eval `cat $tmp_path | awk '{printf("Temp[$i]=%s", $1)}'`
    tmp_Temp=`echo "scale=0; ${Temp[$i]}/1000 " | bc`
    #echo "${tmp_Temp}"
    CpuTemp[$i]=`echo "scale=2; ${Temp[$i]}/1000 " | bc`
    CpuTemp_flag[$i]=$( getFlag $tmp_Temp )
done

for ((i=0; i<CountCPu; i++)); do
    echo "$Time $Load1 $Load2 $Load3 $PercntCpu ${CpuTemp[$i]}°C ${CpuTemp_flag[$i]}"
done

: << EOF
当两个时间点的间隔较短时，就可以把这个计算结果看作是CPU的即时利用率。

CPU的即时利用率的计算公式：

CPU在t1到t2时间段总的使用时间 = ( user2+ nice2+ system2+ idle2+ iowait2+ irq2+ softirq2) - ( user1+ nice1+ system1+ idle1+ iowait1+ irq1+ softirq1)

CPU在t1到t2时间段空闲使用时间 = (idle2 - idle1)

CPU在t1到t2时间段即时利用率 =  1 - CPU空闲使用时间 / CPU总的使用时间
EOF
