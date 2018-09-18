#ifndef _LED_H_
#define _LED_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <asm/io.h>
#include <linux/mm.h> 
#include <asm/page.h>

#define LED1CON 0x11000000
#define LED1DAT 0x11000C44
#define LED2CON 0x11000C20
#define LED3CON 0x114001E0

struct cdev led_dev;
dev_t led_num;

#endif