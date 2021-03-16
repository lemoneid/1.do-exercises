#!/usr/bin/env python
# coding=utf-8
import numpy as np
import matplotlib.pyplot as plt
plt.figure(1)
x = np.linspace(0, 7, 600)
y1 =  [10**z for z in x]
#nineM = reduce(lambda a,b : a * b, xrange(1, 10))
nineM = 1
for (z in range(1, 10)) nineM = z * nineM
y2 = [nineM * z for z in x]
plt.figure(1)
plt.title('f(n) vs g(n)')
p1 = plt.plot(x, y1, label = "$f(n)=10^n$")
p2 = plt.plot(x, y2, label = "$g(n)=9!*n$")
plt.xlabel('n digit')
plt.ylabel('num value')
plt.legend()
plt.show()
