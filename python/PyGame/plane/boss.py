'''
Created on Sep 15, 2018

@author: Administrator
'''

import pygame
import random

class Boss(pygame.sprite.Sprite):
    
    def __init__(self, image, blood, bg_size):
        # sprite init
        pygame.sprite.Sprite.__init__(self)
        
        # load image
        self.image = pygame.image.load(image).convert_alpha()
        self.rect = self.image.get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        
        # alive
        self.alive = True
        
        # destroy image
        self.destroy_images = pygame.image.load("images/bomb_1.png").convert_alpha()
        
        # destroy index
        self.destroy_index = 0
        
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image)
        
        # speed
        self.speed = 5
        self.left = True
        
        # blood volume
        self.blood = blood
        self.blood1 = blood
        
        # pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), -5000
        
    # reset
    def reset(self, blood):
        # reinit pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), -5000       
        # set alive
        self.alive = True
        self.blood = blood
        
    # move action
    def move(self):
        if self.rect.bottom < self.height and (self.rect.bottom < self.rect.height + 50):
            self.rect.bottom += self.speed
            if self.rect.bottom > -50:
                self.speed = 2
        else:
            if self.rect.left > 0 and self.left:
                self.rect.left -= self.speed
            else:
                self.left = False
                self.rect.left += self.speed
                if self.rect.left > self.width - self.rect.width:
                    self.left = True
            
            