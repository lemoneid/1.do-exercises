#!/usr/bin/env python
# coding=utf-8

import tensorflow as tf
print(tf.__version__)
import numpy as np
import matplotlib.pyplot as plt
#%pylab inline

def plot_points(x, y, title_name) :
    """
        Function
        Input : x : , y : ...
        Output : ...
    """
    plt.title(title_name)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.scatter(x, y)
    plt.show()

def plot_Line(w, b, title_name) :
    plt.title(title_name)
    plt.xlabel('x')
    plt.ylabel('y')
    x = np.linspace(0.0, 2.0, num=100)
    y = w * x + b
    plt.plot(x, y)
    plt.show()

train_X = np.array([30.0, 40.0, 60.0, 80.0, 100.0, 120.0, 140.0])
train_Y = np.array([320.0, 360.0, 400.0, 455.0, 490.0, 560.0, 580.0])

#成本函数往0上走,规划
train_X /= 100.0
train_Y /= 100.0

plot_points(train_X, train_Y, "Training Points")

x = tf.placeholder(tf.float32, None)
y = tf.placeholder(tf.float32, None)
w = tf.Variable(np.random.randn(), name = "weight")
b = tf.Variable(np.random.randn(), name = "bias")
y_pred = tf.add(tf.multiply(w, x), b)
print(w)
print(b)
print(y_pred)

#归一化
n_samples = train_X.shape[0]
cost = tf.reduce_sum(tf.pow((y_pred - y), 2)) / n_samples

#优化器
learning_rate = 0.01
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

training_epoch = 1000
disply_step = 50

with tf.Session() as sess :
    sess.run(tf.initialize_all_variables())
    for epoch in range(training_epoch) :
        for (x_train, y_train) in zip(train_X, train_Y) :
            _, loss, current_W, current_B = sess.run([optimizer, cost, w, b], feed_dict = {x : x_train, y : y_train})
        if epoch % disply_step == 0 :
            print('Iteration: %04d | Loss: %.6f | W: %.6f | b: %.6f' 
            %(epoch + 1, loss, current_W, current_B))
            plot_Line(current_W, current_B, 'Model Parameter')
        print('Training loss: %.6f | W: %.6f | b:%.6f ' % (loss, sess.run(w), sess.run(b)))