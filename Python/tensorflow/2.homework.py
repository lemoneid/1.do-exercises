#!/usr/bin/env python
# coding=utf-8

import tensorflow as tf
print(tf.__version__)
import numpy as np

tf.reset_default_graph()

x1 = tf.placeholder(tf.float32, None)
x2 = tf.placeholder(tf.float32, None)
z = tf.add(x1, x2)
w = tf.multiply(x1, x2)
print(x1)
print(x2)
print(z)
print(w)
with tf.Session() as sess :
    writer = tf.summary.FileWriter('./graphs', sess.graph)
    print(sess.run([z, w], feed_dict = {x1 : np.array([1.0, 2.0]), x2 : np.array([3.0, 4.0])}))
    writer.close()