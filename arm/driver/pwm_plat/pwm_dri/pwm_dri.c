#include "pwm_dri.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Luo@haha");
MODULE_DESCRIPTION("a simple pwm_driver!");

void pwm_on(void)
{
	unsigned int data = 0;
	data = ioread32((my_pwm.baseaddr + TCON));
	data &= (~(1 << 1));
	data |= 1 << 0;
	iowrite32(data, (my_pwm.baseaddr + TCON));	
}

void pwm_off(void)
{
	unsigned int data = 0;
	data = ioread32((my_pwm.baseaddr + TCON));
	data &= (~(1 << 0));
	iowrite32(data, (my_pwm.baseaddr + TCON));	
}

int pwm_init_pre(struct inode* node, struct file* ops)
{
	unsigned int data = 0;
	
	data = ioread32(my_pwm.gpioaddr);
	data &= ~(0xf);
	data |= 0x2;
	iowrite32(data, my_pwm.gpioaddr);
	
	data = ioread32((my_pwm.baseaddr + TCFG0));
	data &= ~(0xFF);
	data |= 0xF9;
	iowrite32(data, (my_pwm.baseaddr + TCFG0));
	
	data = ioread32((my_pwm.baseaddr + TCFG1));
	data &= ~(0xf);
	data |= 0x2;
	iowrite32(data, (my_pwm.baseaddr + TCFG1));
	
	iowrite32(5000, (my_pwm.baseaddr + TCNTB0));
	iowrite32(2500, (my_pwm.baseaddr + TCMPB0));
	
	data = ioread32((my_pwm.baseaddr + TCON));
	data &= ~(0xf);
	data |= 1 << 3 | 1 << 1;
	iowrite32(data, (my_pwm.baseaddr + TCON));
	
	return 0;
}

long pwm_ioctl(struct file* ops, unsigned int cmd, unsigned long arg)
{
	/*unsigned int id = iminor(ops->f_inode); 获得次设备号 */
	switch (cmd)
	{
		case PWM_ON:
			pwm_on();
		return 0;
		case PWM_OFF:
			pwm_off();
		return 0;
		default:
		return -1;
	}
	return 0;
}

struct file_operations pwm_fops = 
{
	.owner = THIS_MODULE,
	.open = pwm_init_pre,
	.unlocked_ioctl = pwm_ioctl,
};

int pwm_probe(struct platform_device* dev)
{
	my_pwm.res_base = platform_get_resource(dev, IORESOURCE_MEM, 0);
	my_pwm.baseaddr = ioremap(my_pwm.res_base->start, 
	my_pwm.res_base->end - my_pwm.res_base->start);
	
	my_pwm.res_gpio = platform_get_resource(dev, IORESOURCE_MEM, 1);
	my_pwm.gpioaddr = ioremap(my_pwm.res_gpio->start, 
	my_pwm.res_gpio->end - my_pwm.res_gpio->start);
	
	alloc_chrdev_region(&my_pwm.pwm_num, 0, 1, "pwm");
	printk("pwm_driver %d is installed\n", MAJOR(my_pwm.pwm_num));
	cdev_init(&my_pwm.pwm_dev, &pwm_fops);
	cdev_add(&my_pwm.pwm_dev, my_pwm.pwm_num, 1);
	
	my_pwm.pwm_class = class_create(THIS_MODULE, "pwm");
	my_pwm.pwm_device = device_create(my_pwm.pwm_class, NULL, my_pwm.pwm_num, NULL, "pwm");
	return 0;
}

int pwm_remove(struct platform_device* dev)
{
	printk("pwm_driver release\n");
	iounmap(my_pwm.baseaddr);
	iounmap(my_pwm.gpioaddr);
	cdev_del(&my_pwm.pwm_dev);
	unregister_chrdev_region(my_pwm.pwm_num, 1);
	device_destroy(my_pwm.pwm_class, my_pwm.pwm_num);
	class_destroy(my_pwm.pwm_class);
	return 0;
}

struct platform_driver pwm_driver = {
	.probe = pwm_probe,
	.remove = pwm_remove,
	.driver = {
		.name = "pwm"
	}
};

static int pwm_init(void)
{
	platform_driver_register(&pwm_driver);
	return 0;
}

static void pwm_exit(void)
{
	platform_driver_unregister(&pwm_driver);
}

module_init(pwm_init);
module_exit(pwm_exit);



