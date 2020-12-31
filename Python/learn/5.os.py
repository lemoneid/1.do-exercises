#!/usr/bin/env python
# coding=utf-8

import os

path = '/home/worst/'
dirs = os.listdir(path)
'''
for file in dirs :
    print(file)
'''

path = './test/git/a/b'

if os.path.exists(path) == True :
    print(path, "is exit!")
else :
    os.makedirs(path)
    print("create {} success!".format(path))


from datetime import datetime

now = datetime.now()
print(now)
date1 = datetime(2020, 12, 26, 15, 40, 20)
print(date1)
#时间戳
print(now.timestamp())
date2 = datetime.strptime('2018-6-08 12:0:0', '%Y-%m-%d %H:%M:%S')
print(date2)

import random

print(random.randrange(0, 10))