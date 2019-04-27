"""
Given an array nums of n integers and an integer target, find three integers in nums such that the sum
is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""

import threading
import time


class C:
    lock = threading.Condition()
    a = 0
    b = 10


class A(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        while True:
            if C.b > 0:
                print('A', C.a)
                C.a += 1
                C.b -= 1
                with C.lock:
                    C.lock.notify_all()
                time.sleep(1)
            else:
                time.sleep(1)


class B(threading.Thread):
    def __init__(self):
        super().__init__()
        self.a = 0

    def run(self):
        while True:
            if C.b > 0:
                with C.lock:
                    C.lock.wait()
            print('B', C.a)
            C.a += 1
            time.sleep(0.5)


A().start()
B().start()
