#!/usr/bin/env python
# coding=utf-8

import urllib.request

#向指定URL发送request.获取response
response = urllib.request.urlopen("http://www.haizeix.com")
#获取内容
content = response.read().decode('utf-8')
fo = open("./haizei.html", 'w', encoding = 'utf-8')
print(content, file = fo)
fo.close()

#响应头信息
print(response.headers)
print(response)