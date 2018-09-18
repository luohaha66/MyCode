'''
Created on Sep 9, 2018

@author: Administrator
'''

import pygame


class MyPlane(pygame.sprite.Sprite):

    def __init__(self, bg_size):
        # Sprite init
        pygame.sprite.Sprite.__init__(self)
        
        self.width, self.height = bg_size[0], bg_size[1]
        
        # destroy image
        self.destroy_images = pygame.image.load("images/bomb_1.png").convert_alpha()
                 
        # destory
        self.destroy_index = 0
    
    def setImage(self, image, speed):
        # load image
        self.image = pygame.image.load(image).convert_alpha()
        self.rect = self.image.get_rect()

        # pos
        self.rect.left, self.rect.top = \
                                         (self.width - self.rect.width) // 2, \
                                         self.height - self.rect.height + 35
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image)
        
        # alive
        self.alive = True
        
        # speed
        self.speed = speed
        
    # move action
    def moveUp(self):
        if self.rect.top > 0:
            self.rect.top -= self.speed
        else:
            self.rect.top = 0
    
    def moveDown(self):
        if self.rect.bottom < self.height:
            self.rect.bottom += self.speed
        else:
            self.rect.bottom = self.height

    def moveLeft(self):
        if self.rect.left > 0:
            self.rect.left -= self.speed
        else:
            self.rect.left = 0

    def moveRight(self):
        if self.rect.right < self.width:
            self.rect.right += self.speed
        else:
            self.rect.right = self.width
    
    # reset
    def reset(self):
        # alive
        self.alive = True
                 
        # pos
        self.rect.left, self.rect.top = \
                                         (self.width - self.rect.width) // 2, \
                                         self.height - self.rect.height + 35
           
