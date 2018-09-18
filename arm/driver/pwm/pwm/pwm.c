#include "pwm.h"

MODULE_LICENSE("Dual BSD/GPL");

void pwm_on(void)
{
	unsigned int data = 0;
	data = readl((my_pwm.baseaddr + TCON));
	data &= (~(1 << 1));
	data |= 1 << 0;
	writel(data, (my_pwm.baseaddr + TCON));	
}

void pwm_off(void)
{
	unsigned int data = 0;
	data = readl((my_pwm.baseaddr + TCON));
	data &= (~(1 << 0));
	writel(data, (my_pwm.baseaddr + TCON));	
}


int pwm_init_pre(struct inode* node, struct file* ops)
{
	unsigned int data = 0;
	my_pwm.baseaddr = ioremap(PWMBASE, 20);
	my_pwm.gpioaddr = ioremap(GPD0CON, 4);
	
	data = readl(my_pwm.gpioaddr);
	data &= ~(0xf);
	data |= 0x2;
	writel(data, my_pwm.gpioaddr);
	
	data = readl((my_pwm.baseaddr + TCFG0));
	data &= ~(0xFF);
	data |= 0xF9;
	writel(data, (my_pwm.baseaddr + TCFG0));
	
	data = readl((my_pwm.baseaddr + TCFG1));
	data &= ~(0xf);
	data |= 0x2;
	writel(data, (my_pwm.baseaddr + TCFG1));
	
	writel(5000, (my_pwm.baseaddr + TCNTB0));
	writel(2500, (my_pwm.baseaddr + TCMPB0));
	
	data = readl((my_pwm.baseaddr + TCON));
	data &= ~(0xf);
	data |= 1 << 3 | 1 << 1;
	writel(data, (my_pwm.baseaddr + TCON));
	
	
	
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
	.open = pwm_init_pre,
	.unlocked_ioctl = pwm_ioctl,
};

static int pwm_init(void)
{
	alloc_chrdev_region(&my_pwm.pwm_num, 0, 1, "pwm");
	printk("%d is installed\n", MAJOR(my_pwm.pwm_num));
	cdev_init(&my_pwm.pwm_dev, &pwm_fops);
	cdev_add(&my_pwm.pwm_dev, my_pwm.pwm_num, 1);
	return 0;
}

static void pwm_exit(void)
{
	int i = 0;
	printk("module release\n");
	iounmap(my_pwm.baseaddr);
	iounmap(my_pwm.gpioaddr);
	cdev_del(&my_pwm.pwm_dev);
	unregister_chrdev_region(my_pwm.pwm_num, 1);
}

module_init(pwm_init);
module_exit(pwm_exit);



