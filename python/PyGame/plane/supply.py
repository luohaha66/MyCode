'''
Created on Sep 15, 2018

@author: Administrator
'''

import pygame
import random

class BulletSupply(pygame.sprite.Sprite):
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)

        # load image
        self.image_list = []
        self.image_list.append(pygame.image.load("images/bullet1.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/bullet2.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/bullet3.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/bullet4.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/bullet5.png").convert_alpha())
        #speed
        self.speed = 5
        #alive
        self.alive = False
        self.width, self.height = bg_size[0], bg_size[1]
        
    def setImage(self):
        self.image = self.image_list[random.randint(0, 4)]
        self.rect = self.image.get_rect()
        
        #mask
        self.mask = pygame.mask.from_surface(self.image)
        return self.image
        
    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.alive = False

    def reset(self):
        self.alive = True
        self.rect.left, self.rect.bottom = \
                             random.randint(0, self.width - self.rect.width), -100
                 
class BombSupply(pygame.sprite.Sprite):
    def __init__(self, bg_size):
        pygame.sprite.Sprite.__init__(self)
        #load image
        self.image = pygame.image.load("images/bomb.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        self.rect.left, self.rect.bottom = \
                             random.randint(0, self.width - self.rect.width), -100
        #speed
        self.speed = 5
        self.alive = False
        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        if self.rect.top < self.height:
            self.rect.top += self.speed
        else:
            self.alive = False

    def reset(self):
        self.alive = True
        self.rect.left, self.rect.bottom = \
                             random.randint(0, self.width - self.rect.width), -100 
                                                                      
