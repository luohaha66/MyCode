'''
Created on Sep 8, 2018

@author: Administrator
'''

import pygame
import traceback
import sys
import random
from plane import myplane
from plane import enemy
from plane import bullet
from plane import supply
from plane import boss


def add_small_enemies(group1, group2, num, win_size):
    for i in range(num):
        e1 = enemy.SmallEnemy(win_size)
        group1.add(e1)
        group2.add(e1)

        
def add_mid_enemies(group1, group2, num, win_size):
    for i in range(num):
        e1 = enemy.MidEnemy(win_size)
        group1.add(e1)
        group2.add(e1)


def add_big_enemies(group1, group2, num, win_size):
    for i in range(num):
        e1 = enemy.BigEnemy(win_size)
        group1.add(e1)
        group2.add(e1)


def add_speed(target, speed):
    for each in target:
        each.speed += speed

    
def plane_run():
    # pygame init
    pygame.init()
    pygame.mixer.init()
    
    # window size
    win_size = width, height = 682, 1024
    
    # set widow
    screen = pygame.display.set_mode(win_size)
    
    # set window title
    pygame.display.set_caption("Thunderbolt")
    
    # background pic
    back_ground = pygame.image.load("images/background.jpg").convert()
    
    # win pic
    cong_image = pygame.image.load("images/cong.png").convert_alpha()
    cong_rect = cong_image.get_rect()
    cong_rect.left, cong_rect.top = width // 2 - cong_rect.width // 2, height // 2 - cong_rect.height // 2
    win_image = pygame.image.load("images/win.png").convert_alpha()
    win_rect = win_image.get_rect()
    win_rect.left, win_rect.top = width // 2 - win_rect.width // 2, height // 2 - win_rect.height // 2 + 100
    
    # lose pic
    lose_image = pygame.image.load("images/cong.png").convert_alpha()
    lose_rect = lose_image.get_rect()
    lose_rect.left, lose_rect.top = width // 2 - lose_rect.width // 2, height // 2 - lose_rect.height // 2
    
    # music init
    pygame.mixer.music.load("sound/game_music.ogg")
    pygame.mixer.music.set_volume(0.2)
    bullet_sound = pygame.mixer.Sound("sound/bullet.wav")
    bullet_sound.set_volume(0.5)
    bomb_sound = pygame.mixer.Sound("sound/use_bomb.wav")
    bomb_sound.set_volume(0.5)
    supply_sound = pygame.mixer.Sound("sound/supply.wav")
    supply_sound.set_volume(0.5)
    get_bomb_sound = pygame.mixer.Sound("sound/get_bomb.wav")
    get_bomb_sound.set_volume(0.5)
    get_bullet_sound = pygame.mixer.Sound("sound/get_bullet.wav")
    get_bullet_sound.set_volume(0.5)
    upgrade_sound = pygame.mixer.Sound("sound/upgrade.wav")
    upgrade_sound.set_volume(0.5)
    enemy3_fly_sound = pygame.mixer.Sound("sound/enemy3_flying.wav")
    enemy3_fly_sound.set_volume(0.5)
    boss_sound = pygame.mixer.Sound("sound/boss_bg.wav")
    boss_sound.set_volume(0.5)
    enemy1_down_sound = pygame.mixer.Sound("sound/enemy1_down.wav")
    enemy1_down_sound.set_volume(0.5)
    enemy2_down_sound = pygame.mixer.Sound("sound/enemy2_down.wav")
    enemy2_down_sound.set_volume(0.5)
    enemy3_down_sound = pygame.mixer.Sound("sound/enemy3_down.wav")
    enemy3_down_sound.set_volume(0.5)
    me_down_sound = pygame.mixer.Sound("sound/me_down.wav")
    me_down_sound.set_volume(0.5)
     
    # play background music
    pygame.mixer.music.play(-1)
    
    # game fps
    clock = pygame.time.Clock()
    
    # create my plane
    me = myplane.MyPlane(win_size)
    me.setImage('images/my_1.png', 5)
    
    # create bullet1
    bullet1 = []
    bullet1_index = 0
    BULLET1_NUM = 6
    for i in range(BULLET1_NUM):
        bullet1.append(bullet.Bullet1(me.rect.midtop))
    
    # create enemy plane group
    enemies = pygame.sprite.Group()
    
    # boss image
    boss_list = ['images/boss1.png', 'images/boss2.png', 'images/boss3.png', 'images/boss4.png']
    boss_enemies = pygame.sprite.Group()
    
    # boss_stage
    boss_stage = False
    boss1 = False
    boss2 = False
    boss3 = False
    boss4 = False
    
    # create small enemies
    small_enemies = pygame.sprite.Group()
    add_small_enemies(small_enemies, enemies, 15, win_size)
    
    # create mid enemies
    mid_enemies = pygame.sprite.Group()
    add_mid_enemies(mid_enemies, enemies, 10, win_size)

    # create big enemies
    big_enemies = pygame.sprite.Group()
    add_big_enemies(big_enemies, enemies, 2, win_size)
    
    # small delay
    delay = 100
    
    # color
    BLACK = (0, 0, 0)
    GREEN = (0, 255, 0)
    RED = (255, 0, 0)
    WHITE = (255, 255, 255)
    
    # score
    score = 0
    score_font = pygame.font.Font("font/font.ttf", 36)
    
    # pause flag
    paused = False
    pause_nor_image = pygame.image.load("images/pause_nor.png").convert_alpha()
    pause_press_image = pygame.image.load("images/pause_pressed.png").convert_alpha()
    resume_nor_image = pygame.image.load("images/resume_nor.png").convert_alpha()
    resume_press_image = pygame.image.load("images/resume_pressed.png").convert_alpha()
    paused_rect = pause_nor_image.get_rect()
    paused_rect.left, paused_rect.top = width - paused_rect.width - 10, 10
    paused_image = pause_nor_image
    
    again_image = pygame.image.load("images/again.png").convert_alpha()
    over_image = pygame.image.load("images/over.png").convert_alpha()
    again_rect = again_image.get_rect()
    again_rect.left, again_rect.top = width // 2 - again_rect.width // 2, height // 2 - again_rect.height // 2
    over_rect = over_image.get_rect()
    over_rect.left, over_rect.top = width // 2 - again_rect.width // 2, height // 2 - again_rect.height // 2 + 100
    
    # level
    level = 1
    
    # bomb of full screen
    bomb_image = pygame.image.load("images/bomb.png").convert_alpha()
    bomb_rect = bomb_image.get_rect()
    bomb_font = pygame.font.Font("font/font.ttf", 48)
    bomb_num = 3
    
    # supply, refreshes every 30 seconds
    bullet_supply = supply.BulletSupply(win_size)
    bomb_supply = supply.BombSupply(win_size)
    SUPPLY_TIME = pygame.USEREVENT
    pygame.time.set_timer(SUPPLY_TIME, 10 * 1000)
    
    # run
    running = True
    while running:
        # all event
        for event in pygame.event.get():
            # quit event
            if event.type == pygame.QUIT:
                sys.exit()
            # mouse event    
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1 and paused_rect.collidepoint(event.pos):
                    paused = not paused
                if paused and again_rect.collidepoint(event.pos):
                    # reset all
                    me.reset()
                    for each in enemies:
                        each.reset()
                    for each in bullet1:
                        each.reset(me.rect.midtop)
                    pygame.time.set_timer(SUPPLY_TIME, 0)
                    paused = not paused
                if paused and over_rect.collidepoint(event.pos):
                    sys.exit()
            # mouse however
            elif event.type == pygame.MOUSEMOTION:
                if paused_rect.collidepoint(event.pos):
                    if paused:
                        paused_image = resume_press_image
                    else:
                        paused_image = pause_press_image
                else:
                    if paused:
                        paused_image = resume_nor_image
                    else:
                        paused_image = pause_nor_image
            # key event
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    if bomb_num:
                        bomb_num -= 1
                        bomb_sound.play()
                        for each in enemies:
                            if each.rect.bottom > 0:
                                each.alive = False
            # user event
            elif event.type == SUPPLY_TIME:
                supply_sound.play()
                if random.choice([True, False]):
                    bomb_supply.reset()
                else:
                    image = bullet_supply.setImage()
                    bullet_supply.reset()
                                            
        # draw background
        screen.blit(back_ground, (0, 0))
        
        # according to score, add level
        if level == 1 and score > 1000:
            # create boss1
            boss_1 = boss.Boss(boss_list[0], 50, win_size)
            enemies.add(boss_1)
            boss_enemies.add(boss_1)
            boss_stage = True
            boss1 = True
            level = 2
            upgrade_sound.play()
            # add plane
            add_small_enemies(small_enemies, enemies, 3, win_size)
            add_mid_enemies(mid_enemies, enemies, 2, win_size)
            add_big_enemies(big_enemies, enemies, 1, win_size)
            # add small plane speed
            add_speed(small_enemies, 1)
        elif level == 2 and score > 90000:
            boss_stage = True
            boss2 = True
            level = 3
            upgrade_sound.play()
            # add plane
            add_small_enemies(small_enemies, enemies, 5, win_size)
            add_mid_enemies(mid_enemies, enemies, 3, win_size)
            add_big_enemies(big_enemies, enemies, 2, win_size)
            # add small plane speed
            add_speed(small_enemies, 1)
            add_speed(mid_enemies, 1)
        elif level == 3 and score > 150000:
            boss_stage = True
            boss3 = True
            level = 4
            upgrade_sound.play()
            # add plane
            add_small_enemies(small_enemies, enemies, 6, win_size)
            add_mid_enemies(mid_enemies, enemies, 4, win_size)
            add_big_enemies(big_enemies, enemies, 3, win_size)
            # add small plane speed
            add_speed(small_enemies, 1)
            add_speed(mid_enemies, 1)
            add_speed(big_enemies, 1)
        elif level == 4 and score > 300000:
            boss_stage = True
            boss4 = True
        
        if not paused:   
            # key module
            key_pressed = pygame.key.get_pressed()
            if key_pressed[pygame.K_UP]:
                me.moveUp()
            if key_pressed[pygame.K_DOWN]:
                me.moveDown()
            if key_pressed[pygame.K_LEFT]:
                me.moveLeft()
            if key_pressed[pygame.K_RIGHT]:
                me.moveRight()
            
            # get bomb supply
            if bomb_supply.alive:
                bomb_supply.move()
                screen.blit(bomb_supply.image, bomb_supply.rect)
                if pygame.sprite.collide_mask(bomb_supply, me):
                    get_bomb_sound.play()
                    if bomb_num < 5:
                        bomb_num += 1
                    bomb_supply.alive = False
                    
            # get bullet supply
            if bullet_supply.alive:
                bullet_supply.move()
                screen.blit(image, bullet_supply.rect)
                if pygame.sprite.collide_mask(bullet_supply, me):
                    get_bullet_sound.play()
                    for each in bullet1:
                        each.setImage(image)
                    bullet_supply.alive = False
            
            # fire bullet
            if not (delay % 10):
                bullet1[bullet1_index].reset((me.rect.centerx - bullet1[bullet1_index].rect.width // 2, \
                                              me.rect.top - bullet1[bullet1_index].rect.height + 40))
                bullet1_index = (bullet1_index + 1) % BULLET1_NUM
                
            # collision detection for bullet1
            for b in bullet1:
                if b.alive:
                    b.move()
                    screen.blit(b.image, b.rect)
                    # hit enemies
                    enemy_hit = pygame.sprite.spritecollide(b, enemies, False, pygame.sprite.collide_mask)
                    if enemy_hit:
                        b.alive = False
                        for e in enemy_hit:
                            # big or mid enemy plane
                            if e in mid_enemies or e in big_enemies or e in boss_enemies:
                                e.blood -= 1
                                if e.blood == 0:
                                    e.alive = False
                            else:
                                e.alive = False
            
            if not boss_stage:
                # draw big enemies
                for each in big_enemies:
                    # alive
                    if each.alive:
                        each.move()
                        # draw image
                        screen.blit(each.image_list[each.image_number], each.rect)
                        # draw blood volume
                        pygame.draw.line(screen, BLACK, (each.rect.left + 50, each.rect.top - 5), \
                                        (each.rect.right - 50, each.rect.top - 5), 2)
                        blood_remain = each.blood / enemy.BigEnemy.blood
                        if blood_remain > 0.2:
                            blood_color = GREEN
                        else:
                            blood_color = RED
                        pygame.draw.line(screen, blood_color, (each.rect.left + 50, each.rect.top - 5), \
                                        (each.rect.left + 50 + (each.rect.width - 100) * blood_remain, each.rect.top - 5), 2)    
                        # play big enemies music
                        if each.rect.bottom > -50 and each.rect.bottom < 50:
                            enemy3_fly_sound.play()
                    # destroy:
                    else:
                        # draw destroy image
                        if not (delay % 3):
                            if each.destroy_index == 0:
                                # play destroy music
                                enemy3_down_sound.play()
                            screen.blit(each.destroy_images, each.rect)
                            each.destroy_index = (each.destroy_index + 1) % 5
                            if each.destroy_index == 0:
                                score += 5000
                                each.reset()
                
                # draw mid enemies
                for each in mid_enemies:
                    # alive
                    if each.alive:
                        each.move()
                        # draw image
                        screen.blit(each.image_list[each.image_number], each.rect)
                        # draw blood volume
                        pygame.draw.line(screen, BLACK, (each.rect.left + 50, each.rect.top - 5), \
                                        (each.rect.right - 50, each.rect.top - 5), 2)
                        blood_remain = each.blood / enemy.MidEnemy.blood
                        if blood_remain > 0.2:
                            blood_color = GREEN
                        else:
                            blood_color = RED
                        pygame.draw.line(screen, blood_color, (each.rect.left + 50, each.rect.top - 5), \
                                        (each.rect.left + 50 + (each.rect.width - 100) * blood_remain, each.rect.top - 5), 2) 
                    # destroy:
                    else:
                        # draw destroy image
                        if not (delay % 3):
                            if each.destroy_index == 0:
                                # play destroy music
                                enemy2_down_sound.play()
                            screen.blit(each.destroy_images, each.rect)
                            each.destroy_index = (each.destroy_index + 1) % 5
                            if each.destroy_index == 0:
                                score += 1000
                                each.reset()
                        
                # draw small enemies
                for each in small_enemies:
                    # alive
                    if each.alive:
                        each.move()
                        # draw image
                        screen.blit(each.image_list[each.image_number], each.rect)
                    # destroy:
                    else:
                        # draw destroy image
                        if not (delay % 3):
                            if each.destroy_index == 0:
                                # play destroy music
                                enemy1_down_sound.play()
                            screen.blit(each.destroy_images, each.rect)
                            each.destroy_index = (each.destroy_index + 1) % 5
                            if each.destroy_index == 0:
                                score += 200
                                each.reset()
            elif boss1:
                # alive
                if boss_1.alive:
                    boss_1.move()
                    # draw image
                    screen.blit(boss_1.image, boss_1.rect)
                    # draw blood volume
                    pygame.draw.line(screen, BLACK, (boss_1.rect.left + 50, boss_1.rect.top - 5), \
                                    (boss_1.rect.right - 50, boss_1.rect.top - 5), 2)
                    blood_remain = boss_1.blood / boss_1.blood1
                    if blood_remain > 0.2:
                        blood_color = GREEN
                    else:
                        blood_color = RED
                    pygame.draw.line(screen, blood_color, (boss_1.rect.left + 50, boss_1.rect.top - 5), \
                                    (boss_1.rect.left + 50 + (boss_1.rect.width - 100) * blood_remain, boss_1.rect.top - 5), 2)
                     # play boss enemies music
                    if boss_1.rect.bottom > -10000 and boss_1.rect.bottom < 50:
                        boss_sound.play()        
                # destroy:
                else:
                    # draw destroy image
                    if not (delay % 3):
                        if boss_1.destroy_index == 0:
                            # play destroy music
                            enemy3_down_sound.play()
                        screen.blit(boss_1.destroy_images, boss_1.rect)
                        boss_1.destroy_index = (boss_1.destroy_index + 1) % 6
                        if boss_1.destroy_index == 0:
                            score += 10000
                            boss_stage = False
                            boss1 = False
                            boss_1.reset(50)
                
            # collision detection for enemies
            collision = pygame.sprite.spritecollide(me, enemies, False, pygame.sprite.collide_mask)
            if collision:
    #             me.alive = False
                for e in collision:
                    e.alive = False
            
            # draw myplane
            if me.alive:
                screen.blit(me.image, me.rect)
            else:
                # draw destroy image
                if not (delay % 3):
                    if me.destory_index == 0:
                            # play destory music
                            me_down_sound.play()
                    screen.blit(me.destroy_images, me.rect)
                    me.destory_index = (me.destory_index + 1) % 6
    #                 if me.destory_index == 0:
    #                     me.reset()
            
            # draw bomb
            bomb_text = bomb_font.render('x %d' % bomb_num, True, WHITE)
            text_rect = bomb_text.get_rect()
            screen.blit(bomb_image, (10, height - 10 - bomb_rect.height))
            screen.blit(bomb_text, (20 + bomb_rect.width, height - 5 - text_rect.height))
        
        # draw score
        score_text = score_font.render("Score: %s" % str(score), True, WHITE)
        screen.blit(score_text, (10, 5))
        
        # draw pause image
        screen.blit(paused_image, paused_rect)
        if paused:
            screen.blit(again_image, again_rect)
            screen.blit(over_image, over_rect)
        
        # refresh delay
        delay -= 1
        if not delay:
            delay = 100
        
        # show
        pygame.display.flip()
        
        # fps
        clock.tick(60)

        
if __name__ == '__main__':
    try:
        plane_run()
    except SystemExit:
        pass
    except:
        traceback.print_exc()
        pygame.quit()
        input()

