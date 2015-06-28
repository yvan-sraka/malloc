#!/usr/bin/env python2
import time

#seconds
TIME_LIMIT = 3
start = time.time()

class Integer(object):
    def __init__(self, value):
        self.value = value

    def getv(self):
        return self.value

x = 0
for i in range(1000):
    l = [Integer(range(10)[i % 10]) for i in range(1000)]
    x += sum(map(Integer.getv, l))

stop = time.time()
exec_time = stop - start
print("Exec time: {0}".format(exec_time))

if exec_time > TIME_LIMIT:
    print("Too slow!")
    exit(1)
print("You did it: New World record!")
