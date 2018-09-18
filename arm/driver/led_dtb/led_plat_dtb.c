#include "led_plat_dri.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("luo@haha");
MODULE_DESCRIPTION("a simple led_driver!");

int led_init_pre(struct inode* node, struct file* ops)
{
	unsigned int data = 0;
	int i = 1;
	for(i = 1; i < my_led.num; i++)
	{
			data = ioread32(my_led.baseaddr[i]);
    	data &= ~(0xf << (my_led.pin[i] * my_led.num));
    	data |= (0x1 << (my_led.pin[i] * my_led.num));
    	iowrite32(data, my_led.baseaddr[i]); 
	}
	return 0; 
}

long led_ioctl(struct file* ops, unsigned int cmd, unsigned long arg)
{
	int i = 1;
	for(i = 1; i < my_led.num; i++)
	{
		if(arg == i)
			{
				switch (cmd)
        	{
        		case LED_ON:
        			iowrite32(ioread32(my_led.baseaddr[i] + 1) | (0x1 << my_led.pin[i]), 
        			(my_led.baseaddr[i] + 1));
        		return 0;
        		case LED_OFF:
        			iowrite32(ioread32(my_led.baseaddr[i] + 1) & ~(0x1 << my_led.pin[i]), 
        			(my_led.baseaddr[i] + 1));
        		return 0;
        		default:
        		return -1;
        	}
			}
	}
	return 0;
}

int led_probe(struct platform_device* dev)
{
	int i = 0;
	my_led.res = platform_get_resource(dev, IORESOURCE_MEM, 0);
	my_led.num = my_led.res->end - my_led.res->start;
	for(i = 1; i < my_led.num; i++)
	{
			my_led.res = platform_get_resource(dev, IORESOURCE_MEM, i);
    	my_led.baseaddr[i] = ioremap(my_led.res->start, 8);
    	my_led.pin[i] = my_led.res->end - my_led.res->start;
	}
	
	alloc_chrdev_region(&my_led.led_num, 0, 1, "led");
	printk("led_driver %d is installed\n", MAJOR(my_led.led_num));
	cdev_init(&my_led.led_dev, &led_fops);
	cdev_add(&my_led.led_dev, my_led.led_num, 1);
	
	my_led.led_class = class_create(THIS_MODULE, "led");
	device_create(my_led.led_class, NULL, my_led.led_num, NULL, "led");
	return 0;
}

int led_remove(struct platform_device* dev)
{
	int i = 0;
	printk("led_driver release\n");
	for(i = 1; i < my_led.num; i++)
	{
		iounmap(my_led.baseaddr[i]);
	}
	cdev_del(&my_led.led_dev);
  unregister_chrdev_region(my_led.led_num, 1);
  device_destroy(my_led.led_class, my_led.led_num);
	class_destroy(my_led.led_class);
	return 0;
}

static int led_module_init(void)
{
	platform_driver_register(&led_driver);
	return 0;
}

static void led_module_exit(void)
{
	platform_driver_unregister(&led_driver);
}


module_init(led_module_init);
module_exit(led_module_exit);