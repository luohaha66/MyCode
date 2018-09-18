'''
Created on Aug 18, 2018

@author: Administrator
'''

import pygame
import sys
from pygame.constants import K_SPACE

def music():
    pygame.init()
    pygame.mixer.init()
    
    size = (width, height) = (300, 200)
    bg = (255, 255, 255)
    clock = pygame.time.Clock()
    screen = pygame.display.set_mode(size)
    pygame.display.set_caption('music')
    pause = False
    play = pygame.image.load('play.png').convert_alpha()
    stop = pygame.image.load('stop.png').convert_alpha()
    play_r = play.get_rect()
    play_r.left, play_r.top = (width - play_r.width) // 2, (height - play_r.height) // 2
    
    pygame.mixer.music.load('fade.ogg')
    pygame.mixer.music.set_volume(0.2)
    pygame.mixer.music.play()
    win_sound = pygame.mixer.Sound('winner.wav')
    win_sound.set_volume(0.2)
    loser_sound = pygame.mixer.Sound('loser.wav')
    loser_sound.set_volume(0.2)
    
    while True: 
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    win_sound.play()
                if event.button == 3:
                    loser_sound.play()
            if event.type == pygame.KEYDOWN:
                if event.key == K_SPACE:
                    pause = not pause
            
            screen.fill(bg)
            if pause:
                screen.blit(stop, play_r)
                pygame.mixer.music.pause()
            else:
                screen.blit(play, play_r)
                pygame.mixer.music.play()
            pygame.display.flip()
            clock.tick(30)

if __name__ == '__main__':
    music()
    