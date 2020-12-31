#!/usr/bin/env python
# coding=utf-8

class Student(object) : 
    def __init__(self, name, age) :
        self.name = name
        self.age = age
    
    def show(self) :
        print("%s : %d" %(self.name, self.age))

s1 = Student('jack', 123)
s2 = Student('bob', 122)
s1.show()
s2.show()

print("---------succeed---------")

class Animal(object) :
    def __init__(self, name) :
        self.name = name
    
    def run(self) :
        print("{} run ...".format(self.name))

    def say(self) :
        print("{} is a Animal, I can say!".format(self.name))


class Cat(Animal) :
    def __init__(self, name, color) :
        super().__init__(name)
        self.color = color

    def show(self) :
        print("name = {}, color = {}".format(self.name, self.color))

    def say(self) :
        print("{} is a Cat, miao~, miao~, miao~!".format(self.name))

class Dog(Animal) :
    def run(self) :
        print("{} run fase...".format(self.name))

    def say(self) :
        print("{} is a dog, wang~, wang~, wang~!".format(self.name))

def Animal_say(animal) :
    animal.say()

cat = Cat("kitty", "white")
cat.run()
cat.show()
dog = Dog("wangwu")
dog.run()

print("---------diff---------")

Animal_say(Animal('a'))
Animal_say(cat)
Animal_say(dog)
