#!/usr/bin/env python
# coding=utf-8

import tensorflow as tf 
import numpy as np

z = tf.add(3, 4)
print(z)
sess = tf.Session()
print(sess)
result  = sess.run(z)
print(result)
sess.close()


a = tf.constant(3)
b = tf.constant(4)
c = tf.constant(5)
#z = a + b 运算符重载
z = tf.add(a, b)
z = tf.add(z, c)

with tf.Session() as sess :
    writer = tf.summary.FileWriter('./graph', sess.graph)
    print(sess.run(z))


print(z)


