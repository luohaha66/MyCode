'''
Created on Jul 8, 2018

@author: Administrator
'''

import time as t

class Timer():
    #init
    def __init__(self):
        self.prompts = 'The timer is not running, please start the timer'
        self.unit = [' years ', ' months ', ' days ', ' hours ', ' minutes ', ' seconds ', ' milliseconds ']
        self.start = 0
        self.stop = 0
        self.timeCount= 0
    
    def __str__(self):
        if self.start == 0 or self.stop == 0:
            return self.prompts
        return 'The timer running ' + self.prompts
    
    __repr__ = __str__
    
    def __add__(self, other):
        self.prompt = ''
        if self.timeCount == 0 and other.timeCount == 0:
            return 'Timer running sum is 0 milliseconds (from 1970.1.1 00:00:00)'
        self.timeCount += other.timeCount
        return 'Timer running sum is ' + self.__timeForamt()
                
    #start timer
    def startTimer(self):
        self.start = t.time()
        self.prompts = "please stop the timer first"
        print('Timer start')
    
    #stop timer
    def stopTimer(self):
        if not self.start:
            self.prompts = 'please start the timer first'
            return
        self.stop = t.time()
        print('Timer stop')
        self.__timeCount()
        
    #time count
    def __timeCount(self):
        self.prompt = ''
        self.timeCount = int(round((self.stop - self.start) * 1000))
        self.prompts = self.__timeForamt()
        
    #format time
    def __timeForamt(self):
        timeCounts = self.timeCount
        timeList = [0, 0, 0, 0, 0, 0, 0]
        prompt = ''
        if timeCounts == 0:
            prompt = 'The timer has running 0 milliseconds(from 1970.1.1 00:00:00)'
            return prompt
        if timeCounts >= 31536000000:
            timeList[0] = int(timeCounts / 31536000000)
            timeCounts -= timeList[0] * 31536000000
        if timeCounts >= 2592000000:
            timeList[1] = int(timeCounts / 2592000000)
            timeCounts -= timeList[1] * 2592000000
        if timeCounts >= 86400000:
            timeList[2] = int(timeCounts / 86400000)
            timeCounts -= timeList[2] * 86400000
        if timeCounts >= 3600000:
            timeList[3] = int(timeCounts / 3600000)
            timeCounts -= timeList[3] * 3600000
        if timeCounts >= 60000:
            timeList[4] = int(timeCounts / 60000)
            timeCounts -= timeList[4] * 60000
        if timeCounts >= 1000:
            timeList[5] = int(timeCounts / 1000)
            timeCounts -= timeList[5] * 1000
        timeList[6] = int(timeCounts % 1000)
        for index in range(7):
            if timeList[index]:
                prompt += str(timeList[index]) + self.unit[index]
        prompt += '(from 1970.1.1 00:00:00)'
        return prompt
        
timer = Timer()
timer.startTimer()
t.sleep(1)
timer.stopTimer()
print(timer)
timer1 = Timer()
timer1.stopTimer()
print(timer1)