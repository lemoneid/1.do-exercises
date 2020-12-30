#!/usr/bin/env python
# coding=utf-8

import tensorflow as tf
import numpy as np

tf.app.flags.DEFINE_integer("a", 0, "p1 is blabalblab")
tf.app.flags.DEFINE_integer("b", 0, "p1 is blabalblab")

FLAGS = tf.app.flags.FLAGS

def test1():
    a = tf.placeholder(tf.float32, shape = [1])
    b = tf.placeholder(tf.float32, shape = [1])

    add_op = a + b
    sub_op = a - b
    
    sess = tf.Session()
    
    for i in range(4):
        for j in range(4):
            c = sess.run([add_op, sub_op, a, b], feed_dict = {a : [i], b : [j]})
            print(c)

def test2():
    a = tf.placeholder(tf.float32, shape = [2, 3])
    b = tf.placeholder(tf.float32, shape = [3, 4])
    
    mul_op = tf.matmul(a, b)
    re_op = tf.reshape(mul_op, shape = [8])

    sess = tf.Session()
    
    matrix_a = np.random.uniform(0, 1, a.shape)
    matrix_b = np.random.uniform(0, 1, b.shape)
    print(matrix_a)
    print(matrix_b)
    
    c, d = sess.run([mul_op, re_op], feed_dict = {a : matrix_a, b : matrix_b})
    print(c)
    print(d)

def add(a_val, b_val):
    a = tf.placeholder(tf.float32, shape = [])
    b = tf.placeholder(tf.float32, shape = [])
    add_op = a + b
    with tf.Session() as sess:
        ret = sess.run(add_op, feed_dict = {a : a_val, b : b_val})
        print(a_val, "+", b_val, "=", ret)

def main(args):
    print("args : ", args)
    add(FLAGS.a, FLAGS.b)

if __name__ == "__main__":
    tf.app.run()