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
#include <linux/delay.h>
#include <linux/sched.h>   //wake_up_process()
#include <linux/kthread.h> //kthread_create()、kthread_run()
#include <linux/err.h>             //IS_ERR()、PTR_ERR()

#define LED1CON 0x11000C40
#define LED2CON 0x11000C20
#define LED3CON 0x114001E0

#define LED_ON 1
#define LED_OFF 0

struct {
	struct cdev led_dev;
	struct task_struct* led_task;
	struct task_struct* led_task1;
	struct {
		unsigned int* baseaddr;
		unsigned int pin;
	}led_status[4];
  dev_t led_num;
}my_led;

#endif