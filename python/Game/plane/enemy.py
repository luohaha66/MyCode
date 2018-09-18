'''
Created on Sep 9, 2018

@author: Administrator
'''

import pygame
import random

# small enemy
class SmallEnemy(pygame.sprite.Sprite):
    
    def __init__(self, bg_size):
        # sprite init
        pygame.sprite.Sprite.__init__(self)
        
        # load image
        self.image_list = []
        self.image_list.append(pygame.image.load("images/ep_1.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_2.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_3.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_4.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_5.png").convert_alpha())
        self.image_number = random.randint(0, 4)
        self.rect = self.image_list[0].get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        
        # alive
        self.alive = True
        
        # destroy image
        self.destroy_images = pygame.image.load("images/bomb_0.png").convert_alpha()
        
        # destroy index
        self.destroy_index = 0
        
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image_list[self.image_number])
        
        # speed
        self.speed = 2
        
        # pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-5 * self.height, 0)
    
    # reset
    def reset(self):
        # reinit pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-5 * self.height, 0)       
        # set alive
        self.alive = True
        
    # move action
    def move(self):
        if self.rect.bottom < self.height:
            self.rect.bottom += self.speed
        else:
            self.reset()
        
# mid enemy            
class MidEnemy(pygame.sprite.Sprite):
    
    # blood
    blood = 5
    
    def __init__(self, bg_size):
        # sprite init
        pygame.sprite.Sprite.__init__(self)
        
        # load image
        self.image_list = []
        self.image_list.append(pygame.image.load("images/ep_6.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_7.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_8.png").convert_alpha())
        self.image_number = random.randint(0, 2)
        self.rect = self.image_list[0].get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        
        # alive
        self.alive = True
        
        # destroy image
        self.destroy_images = pygame.image.load("images/bomb_0.png").convert_alpha()
        
        # destroy index
        self.destroy_index = 0
        
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image_list[self.image_number])
        
        # speed
        self.speed = 1
        
        # blood volume
        self.blood = MidEnemy.blood
        
        # pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-10 * self.height, -self.height)
        
    
    # reset
    def reset(self):
        # reinit pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-10 * self.height, -self.height)       
        # set alive
        self.alive = True
        self.blood = MidEnemy.blood
        
    # move action
    def move(self):
        if self.rect.bottom < self.height:
            self.rect.bottom += self.speed
        else:
            self.reset()    
        
# big enemy            
class BigEnemy(pygame.sprite.Sprite):
    
    # blood
    blood = 10
    
    def __init__(self, bg_size):
        # sprite init
        pygame.sprite.Sprite.__init__(self)
        
        # load image
        self.image_list = []
        self.image_list.append(pygame.image.load("images/ep_9.png").convert_alpha())
        self.image_list.append(pygame.image.load("images/ep_10.png").convert_alpha())
        self.image_number = random.randint(0, 1)
        self.rect = self.image_list[0].get_rect()
        self.width, self.height = bg_size[0], bg_size[1]
        
        # alive
        self.alive = True
        
        # destroy image
        self.destroy_images = pygame.image.load("images/bomb_0.png").convert_alpha()
        
        # destroy index
        self.destroy_index = 0
        
        # mask used for collision detection
        self.mask = pygame.mask.from_surface(self.image_list[self.image_number])
        
        # speed
        self.speed = 1
        
        # blood volume
        self.blood = BigEnemy.blood
        
        # pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-15 * self.height, -5 * -self.height)  
    
    # reset
    def reset(self):
        # reinit pos
        self.rect.left, self.rect.top = \
                                        random.randint(0, self.width - self.rect.width), \
                                        random.randint(-15 * self.height, -5 * -self.height)
        # set alive
        self.alive = True
        self.blood = BigEnemy.blood       
     
    # move action
    def move(self):
        if self.rect.bottom < self.height:
            self.rect.bottom += self.speed
        else:
            self.reset()          
        
        
        