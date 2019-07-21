'''
Created on Jul 29, 2018

@author: Administrator
'''
import pygame
import sys
import math

def game1():
    pygame.init()
    size = (width, height) = (600, 400)
    size1 = None
    sizefull = pygame.display.list_modes()[0]
    speed = [-2, 1]
    bg = (255, 255, 255)
    clock = pygame.time.Clock()
    fulls = False
    screen = pygame.display.set_mode(size, pygame.RESIZABLE)
    pygame.display.set_caption('hello')
    pic = pygame.image.load('1.png')
    pic_l = pic
    pic_r = pygame.transform.flip(pic, True, False)
    pos = pic.get_rect()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            if event.type == pygame.VIDEORESIZE:
                size1 = event.size
                screen = pygame.display.set_mode(size1, pygame.RESIZABLE)            
                width,height = size1
                            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    pic = pic_l
                    speed = [-2, 0]
                if event.key == pygame.K_RIGHT:
                    pic = pic_r
                    speed = [2, 0]                
                if event.key == pygame.K_UP:
                    speed = [0, -2]
                if event.key == pygame.K_DOWN:
                    speed = [0, 2]
                if event.key == pygame.K_F12:
                    fulls = not fulls
                    if fulls:
                        screen = pygame.display.set_mode(sizefull, pygame.FULLSCREEN | pygame.HWSURFACE | pygame.RESIZABLE)
                        width,height = sizefull
                    else:
                        screen = pygame.display.set_mode(size, pygame.RESIZABLE)
                        width,height = size  
        pos = pos.move(speed)
        if pos.left < 0 or pos.right > width:
            pic = pygame.transform.flip(pic, True, False)
            speed[0] = -speed[0]
            
        if pos.top < 0 or pos.bottom > height:
            pic = pygame.transform.flip(pic, True, False)
            speed[1] = -speed[1]
        
        screen.fill(bg)
        screen.blit(pic, pos)
        pygame.display.flip()
        clock.tick(100)

def game2():
    pygame.init()
    size = (width, height) = (600, 400)
    screen = pygame.display.set_mode(size)
    pygame.display.set_caption('hello')  
    bg = (0, 0, 0)
    pos = 0;
    font = pygame.font.Font(None, 20)
    line_h = font.get_linesize()
    screen.fill(bg)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            screen.blit(font.render(str(event), True, (0,255,0)), (0, pos))
            pos += line_h
            
            if pos > height:
                pos = 0;
                screen.fill(bg)
        pygame.display.flip()

def cut():
    pygame.init()
    size = (width, height) = (800, 600)
    clock = pygame.time.Clock()
    bg = (255, 255, 255)
    screen = pygame.display.set_mode(size)
    pygame.display.set_caption('cut')
    pic = pygame.image.load('1.png')
    pos = pic.get_rect()
    pos.center = (width // 2, height // 2)
    drag = 0
    click = 0
    s_rect = pygame.Rect(0, 0, 0, 0)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    if click == 0 and drag == 0:
                        p_s = event.pos
                        click = 1
                    elif click == 2 and drag == 0:
                        cap = screen.subsurface(s_rect).copy()
                        cap_rect = cap.get_rect()
                        drag = 1
                    elif click == 2 and drag == 2:
                        click = 0
                        drag = 0
                
            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    if click == 1 and drag == 0:
                        p_t = event.pos
                        click = 2
                    if click == 2 and drag == 1:
                        drag = 2
        
        screen.fill(bg)
        screen.blit(pic, pos)
                
        if click:
            m_s = pygame.mouse.get_pos()
            if click == 1:
                p_t = m_s
            s_rect.left, s_rect.top = p_s
            s_rect.width, s_rect.height = p_t[0] - p_s[0], p_t[1] - p_s[1]
            pygame.draw.rect(screen, (0, 0, 0), s_rect, 1)
        if drag:
            if drag == 1:
                cap_rect.center = m_s
            screen.blit(cap, cap_rect)
        pygame.display.flip()
        clock.tick(30)

def game3():
    pygame.init()
    size = (width, height) = (1024, 683)
    clock = pygame.time.Clock()
    screen = pygame.display.set_mode(size)
    pygame.display.set_caption('turtle')
    turtle = pygame.image.load('1.png').convert_alpha()
    background = pygame.image.load('2.jpg').convert()
    pos = turtle.get_rect()
    pos.center = (width // 2, height // 2)
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
                
        screen.blit(background, (0,0))
        x = pos[0]
        y = pos[1]
        temp = pygame.Surface((turtle.get_width(), turtle.get_height())).convert()       
        temp.blit(screen, (-x, -y))
        temp.blit(turtle, (0, 0))
        temp.set_alpha(200)
        screen.blit(temp, pos)
        pygame.display.flip()
        clock.tick(30)

def game4():
    pygame.init()
    size = (width, height) = (800, 600)
    clock = pygame.time.Clock()
    white = (255, 255, 255)
    black = (0, 0, 0)
    green = (0, 255, 0)
    red = (255, 0, 0)
    blue = (0, 0, 255)
    screen = pygame.display.set_mode(size)
    pygame.display.set_caption('shape')
    points= [(200, 75), (300,25), (400, 75), (450, 25), (450, 125), (400, 75), (300, 125)]
    pos = (width // 2, height // 2)
    moving = False
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                moving = True
        if event.type == pygame.MOUSEBUTTONUP:
            if event.button == 1:
                moving = False 
        if moving:
            pos = pygame.mouse.get_pos()   
        
        screen.fill(white)
#         pygame.draw.rect(screen, black, (50, 50, 150, 50), 0)
#         pygame.draw.rect(screen, black, (250, 50, 150, 50), 1)
#         pygame.draw.rect(screen, black, (450, 50, 150, 50), 10)
#         pygame.draw.polygon(screen, green, points, 0)
#         pygame.draw.circle(screen, red, pos, 30, 1)
#         pygame.draw.circle(screen, blue, pos, 60, 1)
#         pygame.draw.circle(screen, green, pos, 120, 1)
#         pygame.draw.ellipse(screen, red, (50, 50, 200, 400), 1)
#         pygame.draw.arc(screen, green, (210, 210, 100, 200), 0, math.pi, 1)
        pygame.draw.line(screen, green, (0,100), (100, 100), 1)
        pygame.draw.line(screen, green, (100,100), (100, 200), 1)
        pygame.draw.aalines(screen, red, 1, points, 1)
        pygame.display.flip()
        clock.tick(10)        
            
if __name__ == '__main__':
    game4()
    
    
    
    
    
    
    
    
    
    