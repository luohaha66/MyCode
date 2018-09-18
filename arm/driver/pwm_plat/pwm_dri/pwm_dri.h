#ifndef _LED_H_
#define _LED_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <asm/io.h>
#include <linux/platform_device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <asm/io.h>

#define TCFG0 0
#define TCFG1 1
#define TCON 2
#define TCNTB0 3
#define TCMPB0 4

#define PWM_ON  _IO('L', 1)
#define PWM_OFF _IO('L', 0)

struct {
	struct cdev pwm_dev;
	struct class* pwm_class;
	struct device* pwm_device;
	struct resource* res_base;
	struct resource* res_gpio;
	unsigned int* baseaddr;
	unsigned int* gpioaddr;
  dev_t pwm_num;
}my_pwm;

#endif