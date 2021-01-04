#!/usr/bin/env python
# coding=utf-8

import sys
sys.path.append('..')
import tensorflow as tf
print(tf.__version__)
import numpy as np
import input_data

mnist = input_data.read_data_sets('../MNIST_data/', one_hot = True)

def weight_variable(shape) :
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape) :
    initail = tf.constant(0.1, shape=shape)
    return tf.Variable(initail)

#tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME' or 'VALID')
#     权重每隔多少一次卷积    batch, x , y, 颜色channel
def conv2d(x, W) :
    return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME') 

def max_pooling_2x2(layer) :
    return tf.nn.max_pool(layer, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

x = tf.placeholder(tf.float32, [None, 784])
y_ = tf.placeholder(tf.float32, [None, 10])

W_conv1 = weight_variable([5, 5, 1, 16]) #RGB: Channel = 3
b_conv1 = bias_variable([16])

W_conv2 = weight_variable([5, 5, 1, 32]) #RGB: Channel = 3
b_conv2 = bias_variable([32])

x_image = tf.reshape(x, [-1, 28, 28, 1])

h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1)
h_pool1 = max_pooling_2x2(h_conv1)


h_conv2 = tf.nn.relu(conv2d(h_conv1, W_conv2) + b_conv2)
h_pool2 = max_pooling_2x2(h_conv2)

h_pool2_flat = tf.reshape(h_pool2, [-1, 7 * 7 * 32])

w_fc1 = weight_variable([7 * 7 * 32, 256])
b_fc1 = bias_variable([256])


w_fc2 = weight_variable([256, 10])
b_fc2 = bias_variable([10])

h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, w_fc1) + b_fc1)
h_fc2 = tf.nn.relu(tf.matmul(h_fc1, w_fc2) + b_fc2)
y = tf.nn.softmax(h_fc2)

correct_prediction = tf.equal(tf.argmax(y, 1),tf.argmax(y_, 1) )
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
#分类问题
#tf.log(y) 突然模型崩溃，loss变为NaN，程序依然运行
#tf.log(~0) 下溢，溢出 + 0.00001
cross_entropy = -tf.reduce_mean(tf.reduce_sum(y_ * tf.log(y + 0.00001), reduction_indices = [1]))
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)


#训练程序
training_iteration = 10000
batch_size = 50
display_step = 100

tf.summary.scalar('loss', cross_entropy)
tf.summary.scalar('accuracy', accuracy)
merged = tf.summary.merge_all()

with tf.Session() as sess :
    writer = tf.summary.FileWriter('./cnn/', sess.graph)
    sess.run(tf.initialize_all_variables())
    for iteration in range(training_iteration) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        summary, _, current_accuracy = sess.run([merged,train_step, accuracy], feed_dict = {x : batch_xs, y_ : batch_ys})
        writer.add_summary(summary, iteration)
        if iteration % display_step == 0 :
            print('Iteration: %5d | Accuracy: %.6f' %(iteration + 1, current_accuracy))
    print('Test accuracy: %.6f' %(sess.run(accuracy, feed_dict={x : mnist.test.images, y_ : mnist.test.labels})))
    writer.close()