#!/usr/bin/env python
# coding=utf-8


num1 = ["hello", "world", "this", "is", "a", "joke"]
num2 = [x for x in range(0, 20, 3)]
num3 = num2 + num1

num3.insert(5, 123)
num3.insert(10, "456")
print(num3)

num4 = [x for x in num3 if isinstance(x, int)]
print(num4)

