#!/usr/bin/env python
# coding=utf-8
import sys
sys.path.append('..')
import tensorflow as tf
print(tf.__version__)
import input_data
import numpy as np
import matplotlib.pyplot as plt

mnist = input_data.read_data_sets('../MNIST_data/', one_hot = True)

def imshow(img) :
    plt.imshow(np.reshape(img, [28, 28]))
    plt.show()

for index in range(10) :
    print(mnist.train.images[index].shape)
    print(mnist.train.labels[index])
    #/print(np.nonzero(mnist.train.labels[index][0]))
    imshow(mnist.train.images[index])

def weight_variabel(shape) :
    initial = tf.truncated_normal(shape, stddev = 0.1)
    return tf.Variable(initial)

def bias_variable(shape) :
    initial = tf.constant(0.1, shape = shape)
    return tf.Variable(initial)

tf.placeholder(tf.float32, [None, 784])
W_fc1 = weight_variabel([784, 200])
b_fc1 = weight_variabel([200])
W_fc2 = weight_variabel([200, 200])
b_fc2 = weight_variabel([200])
W_out = weight_variabel([200, 10])
b_out = weight_variabel([10])

hidden_1 = tf.nn.relu(tf.matmul(x, W_fc1) + b_fc1)
hidden_2 = tf.nn.relu(tf.matmul(hidden_1, W_fc2) + b_fc2)
#归一化
y = tf.nn.softmax(tf.matmul(hidden_2, W_out) + b_out)
