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

#define PWMBASE 0x139d0000
#define TCFG0 0
#define TCFG1 1
#define TCON 2
#define TCNTB0 3
#define TCMPB0 4

#define GPD0CON 0x114000a0

#define PWM_ON 1
#define PWM_OFF 0

struct {
	struct cdev pwm_dev;
	unsigned int* baseaddr;
	unsigned int* gpioaddr;
  dev_t pwm_num;
}my_pwm;

#endif