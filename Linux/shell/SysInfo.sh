#!/bin/bash
Time=`date +"%Y-%m-%d__%H:%M:%S"`
eval `uname -a | awk '{printf("Hostname=%s; OS=%s; Kernel=%s", $2, $4, $3)}'`
eval `uptime -p | awk '{printf("D_time=%s; H_time=%s; M_time=%s", $2, $4, $6)}'`
eval `./DiskLog.sh | tail -n -1 | awk '{printf("DiskSum=%s; DiskPercent=%s", $4, $NF)}'`
eval `./MemLog.sh 1 | awk '{printf("MemSize=%s; MemUserdPercent=%s", $2, $4)}'`
#echo "${Time} ${Hostname} ${OS} ${Kernel} up_${D_time}_day,_${H_time}_hours,_${M_time}_minuters"
#echo "${DiskSum} ${DiskPercent} ${MemSize} ${MemUserdPercent}"
eval `./CpuLog.sh | awk -v CpuCount=0 '{printf("CpuTemp["NR"]=%s; CpuTemp_flag["NR"]=%s;", $6, $7)} END {printf("CpuCount=%s", NR)
}'`
ans="${Time} ${Hostname} ${OS} ${Kernel} up_${D_time}_day,_${H_time}_hours,_${M_time}_minutes"
ans=${ans}" ${DiskSum} ${DiskPercent} ${MemSize} ${MemUserdPercent}"
for ((i=1; i<CpuCount; i++)); do
    ans=${ans}" "${CpuTemp[$i]}
done

Disk_flag="warning"
Mem_flag="warning"
tmp_DiskPercent=${DiskPercent%%%*}
tmp_MemPercent=${MemUserdPercent%%.*}
#echo "$tmp_DiskPercent $tmp_MemPercent"

if [ ${tmp_DiskPercent} -lt 80 ] 
then Disk_flag="normal"
elif [ ${tmp_DiskPercent} -lt 90 ]
then Disk_flag="note"
else Disk_flag="warning"
fi

if [ ${tmp_MemPercent} -lt 70 ]
then Mem_flag="normal"
elif [ ${tmp_MemPercent} -lt 80 ]
then Mem_flag="note"
else Mem_flag="warning"
fi

ans=${ans}" "${Disk_flag}" "${Mem_flag}
for ((i=1; i<CpuCount; i++)); do
    ans=${ans}" "${CpuTemp_flag[$i]}
done
echo "${ans}"
