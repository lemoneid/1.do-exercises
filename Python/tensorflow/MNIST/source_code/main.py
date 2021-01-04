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
    #imshow(mnist.train.images[index])

def weight_variabel(shape) :
    initial = tf.truncated_normal(shape, stddev = 0.1)
    return tf.Variable(initial)

def bias_variable(shape) :
    initial = tf.constant(0.1, shape = shape)
    return tf.Variable(initial)

x = tf.placeholder(tf.float32, [None, 784])
W_fc1 = weight_variabel([784, 200])
b_fc1 = weight_variabel([200])
W_fc2 = weight_variabel([200, 200])
b_fc2 = weight_variabel([200])
W_out = weight_variabel([200, 10])
b_out = weight_variabel([10])

hidden_1 = tf.nn.relu(tf.matmul(x, W_fc1) + b_fc1)
hidden_2 = tf.nn.relu(tf.matmul(hidden_1, W_fc2) + b_fc2)
#0.5) #tf.nn.dropout()

#归一化
y = tf.nn.softmax(tf.matmul(hidden_2, W_out) + b_out)

y_ = tf.placeholder(tf.float32, [None, 10])
correct_prediction = tf.equal(tf.argmax(y, 1),tf.argmax(y_, 1) )
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
#分类问题
#tf.log(y) 突然模型崩溃，loss变为NaN，程序依然运行
#tf.log(~0) 下溢，溢出 + 0.00001
cross_entropy = -tf.reduce_mean(tf.reduce_sum(y_ * tf.log(y + 0.00001), reduction_indices = [1]))
train_step = tf.train.GradientDescentOptimizer(0.05).minimize(cross_entropy)


#训练程序
training_iteration = 10000
batch_size = 100
display_step = 50

tf.summary.scalar('loss', cross_entropy)
tf.summary.scalar('accuracy', accuracy)
merged = tf.summary.merge_all()

with tf.Session() as sess :
    writer = tf.summary.FileWriter('./neural_network/', sess.graph)
    sess.run(tf.initialize_all_variables())
    for iteration in range(training_iteration) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        _, current_accuracy, summary = sess.run([train_step, accuracy, merged], feed_dict = {x : batch_xs, y_ : batch_ys})
        writer.add_summary(summary, iteration)
        if iteration % display_step == 0 :
            print('Iteration: %5d | Accuracy: %.6f' %(iteration + 1, current_accuracy))
    print('Test accuracy: %.6f' %(sess.run(accuracy, feed_dict={x : mnist.test.images, y_ : mnist.test.labels})))
    writer.close()