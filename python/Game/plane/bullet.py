'''
Created on Sep 9, 2018

@author: Administrator
'''

import pygame

class Bullet1(pygame.sprite.Sprite):
    
    def __init__(self, position):
        # sprite init
        pygame.sprite.Sprite.__init__(self)
        
        # load image
        self.image = pygame.image.load("images/bullet1.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = position
        
        # speed
        self.speed = 12
        
        # alive
        self.alive = True
        
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image)
        
    # move action
    def move(self):
        self.rect.top -= self.speed
        
        if self.rect.top < 0:
            self.active = False
    
    def setImage(self, image):
        self.image = image
        self.rect = self.image.get_rect()
        self.mask = pygame.mask.from_surface(self.image)
        

    # reset
    def reset(self, position):
        self.rect.left, self.rect.top = position
        self.alive = True