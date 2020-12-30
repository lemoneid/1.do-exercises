#!/usr/bin/env python
# coding=utf-8

file = open("./input", "w", encoding = "utf-8")
file.write("hello world")
file.write("\n")
file.writelines(['write', 'line'])
file.close()

file = open("./input", "r+")
print("filename:", file.name)
str = "\nwww.aliyun.com"  
file.seek(0, 2)
lines = file.write(str)

print(lines)
file.seek(0)

for index in range(3) :
    line = next(file)
    print("file line : %d-%s" % (index, line))

file.close()
with open("./input", "r+", encoding="utf-8") as file :
    print("%s" %(file.read()))