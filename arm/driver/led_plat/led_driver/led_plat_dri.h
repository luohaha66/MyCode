#ifndef _LED_PLAT_DRI_H_
#define _LED_PLAT_DRI_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <asm/io.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/string.h>

#define LED_ON  _IO('L', 1)
#define LED_OFF _IO('L', 0)

int led_probe(struct platform_device* dev);
int led_remove(struct platform_device* dev);
static int led_module_init(void);
static void led_module_exit(void);
int led_init_pre(struct inode* node, struct file* ops);
long led_ioctl(struct file* ops, unsigned int cmd, unsigned long arg);

struct {
	struct cdev led_dev;
	struct resource* res;
	unsigned int num;
	struct class* led_class;
	unsigned int* baseaddr[4];
	unsigned int pin[4];
  dev_t led_num;
}my_led;

struct platform_device_id led_id[] = {
	{
		.name = "led"
	},
	{
		.name = "led1"
	},
	{
		.name = "led2"
	},
	{
		.name = "led3"
	}
};

struct platform_driver led_driver = {
	.probe = led_probe,
	.remove = led_remove,
	.id_table = led_id,
	.driver = {
		.name = "led"
	}
};

struct file_operations led_fops = 
{
	.open = led_init_pre,
	.unlocked_ioctl = led_ioctl,
};

#endif