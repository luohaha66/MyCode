'''
Created on Sep 14, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract
from abc import ABCMeta, abstractmethod


# abstract class of trip
class Trip(metaclass=ABCMeta):

    @abstractmethod
    def setTransport(self):
        pass
    
    @abstractmethod
    def day1(self):
        pass
    
    @abstractmethod
    def returnHome(self):
        pass
    
    def itinerary(self):
        self.setTransport()
        self.day1()
        self.returnHome()

        
# Tom's trip
class TomTrip(Trip):

    def setTransport(self):
        print('by foot')
        
    def day1(self):
        print('visit CHINA')
        
    def returnHome(self):
        print('by air')

        
# lucy's trip
class LucyTrip(Trip):

    def setTransport(self):
        print('by bike')
        
    def day1(self):
        print('visit USA')
        
    def returnHome(self):
        print('by train')

        
class TravelAgency:

    def arrange_trip(self):
        choice = input('where do you want to go for a trip, USA or CHINA?')
        if choice == 'USA':
            self.trip = LucyTrip()
            self.trip.itinerary()
            
        if choice == 'CHINA':
            self.trip = TomTrip()
            self.trip.itinerary()
        

if __name__ == '__main__':
    TravelAgency().arrange_trip()
