'''
Created on Aug 5, 2018

@author: Administrator
'''

import pygame
import sys
import math
from pygame.locals import *
from random import *

class Ball(pygame.sprite.Sprite):
    def __init__(self, image, green_image, position, speed, bg_size, target):
        pygame.sprite.Sprite.__init__(self)
        
        self.image = pygame.image.load(image).convert_alpha()
        self.green_image = pygame.image.load(green_image).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = position
        self.speed = speed
        self.control = False
        self.width, self.height = bg_size[0], bg_size[1]
        self.radius = self.rect.width / 2
        self.target = target
    
    def move(self):
        self.rect = self.rect.move(self.speed)
        
        if self.rect.right < 0:
            self.rect.left = self.width

        elif self.rect.left > self.width:
            self.rect.right = 0

        elif self.rect.bottom < 0:
            self.rect.top = self.height

        elif self.rect.top > self.height:
            self.rect.bottom = 0
    
    def check(self, motion):
        if self.target < motion < self.target + 5:
            return True
        else:
            return False
        
class Glass():
    def __init__(self, image, m_image, size):
        self.image = pygame.image.load(image).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = (size[0] - self.rect.width) // 2,\
                                        (size[1] - self.rect.height)
        self.m_image = pygame.image.load(m_image).convert_alpha()
        self.m_rect = self.m_image.get_rect()
        self.m_rect.left, self.m_rect.top = self.rect.left, self.rect.top
        pygame.mouse.set_visible(False)
        
def collide_check(item, item_list):
    ball = []
    for each in item_list:
        distance = math.sqrt(\
                            math.pow(item.rect.center[0] - each.rect.center[0], 2) + \
                            math.pow(item.rect.center[1] - each.rect.center[1], 2))
        if distance <= (item.rect.width + each.rect.width) / 2:
            ball.append(each)
    return ball        
        
        
def main():
    pygame.init()
    
    ball_image = "gray_ball.png"
    green_ball = "green_ball.png"
    bg_image = "background.png"
    glass_image = 'glass.png'
    mouse_image = 'hand.png'
    
    running = True
    bg_size = width, height = 1024, 681
    screen = pygame.display.set_mode(bg_size)
    pygame.display.set_caption("ball")
    background = pygame.image.load(bg_image).convert_alpha()
    
    #add music
    pygame.mixer.music.load('fade.ogg')
    pygame.mixer.music.set_volume(0.2)
    pygame.mixer.music.play()
    win_sound = pygame.mixer.Sound('winner.wav')
    win_sound.set_volume(0.2)
    loser_sound = pygame.mixer.Sound('loser.wav')
    loser_sound.set_volume(0.2)
    laugh_sound = pygame.mixer.Sound('laugh.wav')
    laugh_sound.set_volume(0.2)
    hole_sound = pygame.mixer.Sound('hole.wav')
    hole_sound.set_volume(0.2)
    
    #music over event
    GAMEOVER = USEREVENT
    pygame.mixer.music.set_endevent(GAMEOVER)
    
    #create balls
    balls = []
    group = pygame.sprite.Group()
    for i in range(5):
        position = randint(0, width - 100), randint(0, height - 100)
        speed = [randint(-10, 10), randint(-10, 10)]
        ball = Ball(ball_image, green_ball, position, speed, bg_size, 5 * (i + 1))
        while pygame.sprite.spritecollide(ball, group, False, pygame.sprite.collide_circle):
            ball.rect.left, ball.rect.top = randint(0, width - 100), randint(0, height - 100)
        balls.append(ball)
        group.add(ball)
    
    #glass object
    glass = Glass(glass_image, mouse_image, bg_size)
    clock = pygame.time.Clock()  
    
    #create motion used for record mouse event
    motion = 0
    MYTIMER = USEREVENT + 1
    pygame.time.set_timer(MYTIMER, 1000)
    
    #set repeat event
    pygame.key.set_repeat(100, 100)
    
    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == GAMEOVER:
                loser_sound.play()
                pygame.time.delay(2000)
                laugh_sound.play()
                pygame.time.delay(2000)
                running = False
            elif event.type == MYTIMER:
                if motion:
                    for each in group:
                        if each.check(motion):
                            each.speed = [0, 0]
                            each.control = True
                    motion = 0
            elif event.type == MOUSEMOTION:
                motion += 1
            elif event.type == KEYDOWN:
                if event.key == K_w:
                    for each in group:
                        if each.control:
                            each.speed[1] -= 1
                if event.key == K_s:
                    for each in group:
                        if each.control:
                            each.speed[1] += 1
                if event.key == K_a:
                    for each in group:
                        if each.control:
                            each.speed[0] -= 1
                if event.key == K_d:
                    for each in group:
                        if each.control:
                            each.speed[0] += 1
                            
                    
        screen.blit(background, (0, 0))
        screen.blit(glass.image, glass.rect)
        
        glass.m_rect.left, glass.m_rect.top = pygame.mouse.get_pos()
        if glass.m_rect.left < glass.rect.left:
            glass.m_rect.left = glass.rect.left
        if glass.m_rect.left > glass.rect.right - glass.m_rect.width:
            glass.m_rect.left = glass.rect.right - glass.m_rect.width
        if glass.m_rect.top < glass.rect.top:
            glass.m_rect.top = glass.rect.top
        if glass.m_rect.top > glass.rect.bottom - glass.m_rect.height:
            glass.m_rect.top = glass.rect.bottom - glass.m_rect.height
        screen.blit(glass.m_image, glass.m_rect)
        
        for each in balls:
            each.move()
            if each.control:
                screen.blit(each.green_image, each.rect)
            else:
                screen.blit(each.image, each.rect)
        
        for each in group:
            group.remove(each)
            if pygame.sprite.spritecollide(each, group, False, pygame.sprite.collide_circle):
                each.speed[0] = -each.speed[0]
                each.speed[1] = -each.speed[1]
                each.control = False
            group.add(each) 
                       
        pygame.display.flip()
        clock.tick(30)
     
if __name__ == '__main__':
    main()







