#!/bin/bash

Time=`date +"%Y-%m-%d__%H:%M:%S"`

eval `awk -F: -v tmp_idx=0 '{if ($3>999) {tmp_idx+=1; printf("Users["tmp_idx"]=%s;",$1)}} END {printf("UserCount=%d;", tmp_idx)}' /etc/passwd`
echo "${UserCount}"

ActiveUsers=`last -w | cut -d " " -f 1 | sed '/^$/d' | sed '/wtmp*/d'| uniq | awk -v tmp_idx=0 '{if(tmp_idx<4){ tmp_idx+=1; printf(",%s" , $1) }}' | cut -c 2-`

UserLogedIn=`w -h | awk '{printf(",%s_%s_%s", $1, $3, $2)}' | cut -c 2-`

##RootUser
eval $(awk -F: '{if($3==1000){printf("User_1000=%s", $1)}}' /etc/passwd)

UserWithRoot=${User_1000}
Users=`cat /etc/group | grep sudo | cut -d : -f 4 | tr ',' ' '`

for i in ${Users};do
    if [[ $i == ${User_1000} ]] ;then
        continue
    fi
    UserWithRoot="${UserWithRoot},$i"
done

if [[ -r /etc/sudoers ]] ;then
    for i in ${All[*]};do
        grep -q "^${i}" /etc/sudoers
        if [[ $? -eq 0 ]] ;then
            UserWithRoot="${UserWithRoot},$i"
        fi
    done
fi

echo "${Time} ${UserCount} [${ActiveUsers}] [${UserWithRoot}] [${UserLogedIn}]"
