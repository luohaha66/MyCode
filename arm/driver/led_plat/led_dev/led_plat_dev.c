#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <asm/io.h>
#include <linux/platform_device.h>

#define LED1CON 0x11000C40
#define LED2CON 0x11000C20
#define LED3CON 0x114001E0

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("zhur_cd@hqyj.com");
MODULE_DESCRIPTION("a simple driver example!");


struct resource myresource[] = {
	{
		.start = LED1CON,
		.end = LED1CON + 5,
		.flags = IORESOURCE_MEM,
		.name = "led"
	},
	
	{
		.start = LED1CON,
		.end = LED1CON + 7,
		.flags = IORESOURCE_MEM,
		.name = "led"
	},
	
	{
		.start = LED2CON,
		.end = LED2CON + 0,
		.flags = IORESOURCE_MEM,
		.name = "led1"
	},
	
	{
		.start = LED3CON,
		.end = LED3CON + 4,
		.flags = IORESOURCE_MEM,
		.name = "led2"
	},
	
	{
		.start = LED3CON,
		.end = LED3CON + 5,
		.flags = IORESOURCE_MEM,
		.name = "led3"
	}
};

struct platform_device *mydevice;
static int mymodule_init(void)
{
	mydevice = platform_device_alloc("led", -1);
	
	platform_device_add_resources(mydevice, myresource, 5);

	platform_device_add(mydevice);
	printk("led_device install\n");
	return 0;
}

static void mymodule_exit(void)
{
	platform_device_del(mydevice);
	printk("led_device release\n");
}


module_init(mymodule_init);
module_exit(mymodule_exit);
