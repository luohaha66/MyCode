#ifndef _PWM_DEV_H_
#define _PWM_DEV_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>

#define PWMBASE 0x139d0000
#define GPD0CON 0x114000a0


struct resource pwm_res[] = {
	{
		.start = PWMBASE,
		.end = PWMBASE + 20,
		.flags = IORESOURCE_MEM,
		.name = "pwm"
	},
	
	{
		.start = GPD0CON,
		.end = GPD0CON + 4,
		.flags = IORESOURCE_MEM,
		.name = "pwm"
	}
};

struct {
	struct platform_device* pwm_dev;
}my_pwm;

#endif