#include "led.h"

MODULE_LICENSE("Dual BSD/GPL");

void led_on(int id)
{
	writel(1 << my_led.led_status[id].pin, (my_led.led_status[id].baseaddr + 1));
}

void led_off(int id)
{
	writel(0, (my_led.led_status[id].baseaddr + 1));
}

void led_on1(int id)
{
	unsigned short data = 0;
	data = readw(my_led.led_status[id].baseaddr + 1);
	data |= 1 << my_led.led_status[id].pin;
	writel(data, (my_led.led_status[id].baseaddr + 1));
}

void led_off1(int id)
{
	unsigned short data = 0;
	data = readw(my_led.led_status[id].baseaddr + 1);
	data &= ~(1 << my_led.led_status[id].pin);
  writel(data, (my_led.led_status[id].baseaddr + 1));
}

int led_func(void* data)
{
	int i = 0;
	while(1)
	{
		if(kthread_should_stop())
			break;
		i = 0;
		for(i = 0; i < 4; i++)
		{
			if (i < 2)
				{
					led_on(i);
					msleep(100);
					led_off(i);
					msleep(100);
				}
			else 
			{
				led_on1(i);
				msleep(100);
				led_off1(i);
				msleep(100);
			}
		}
	}
	return 0;
}

int led_func1(void* data)
{
	int i = 0;
	while(1)
	{
		if(kthread_should_stop())
			break;
		i = 3;
		for(i = 3; i >= 0; i--)
		{
			if (i < 2)
				{
					led_on(i);
					msleep(60);
					led_off(i);
					msleep(60);
				}
			else 
			{
				led_on1(i);
				msleep(60);
				led_off1(i);
				msleep(60);
			}
		}
	}
	return 0;
}

int led_run(void)
{
	int err = 0;
	my_led.led_task = kthread_create(led_func, NULL, "led_task");
	if(IS_ERR(my_led.led_task))
		{
			printk("Kernel_thread error");
			err = PTR_ERR(my_led.led_task);
			my_led.led_task = NULL;
			return err;
		}
	wake_up_process(my_led.led_task);
	
	my_led.led_task1= kthread_create(led_func1, NULL, "led_task1");
	if(IS_ERR(my_led.led_task1))
		{
			printk("Kernel_thread error");
			err = PTR_ERR(my_led.led_task1);
			my_led.led_task1 = NULL;
			return err;
		}
	wake_up_process(my_led.led_task1);
	return 0;
}

void led_stop(void)
{
	if(my_led.led_task)
		{
			kthread_stop(my_led.led_task);
			my_led.led_task = NULL;
		}
	if(my_led.led_task1)
		{
			kthread_stop(my_led.led_task1);
			my_led.led_task1 = NULL;
		}
}

int led_init_pre(struct inode* node, struct file* ops)
{
	int i = 0;
	unsigned int data = 0;
	
	my_led.led_status[0].baseaddr = ioremap(LED1CON, 8);
	my_led.led_status[0].pin = 7;
	
	my_led.led_status[1].baseaddr = ioremap(LED2CON, 8);
	my_led.led_status[1].pin = 0;
	
	my_led.led_status[2].baseaddr = ioremap(LED3CON, 8);
	my_led.led_status[2].pin = 4;
	
	my_led.led_status[3].baseaddr = ioremap(LED3CON, 8);
	my_led.led_status[3].pin = 5;
	
	for(i = 0; i < 4; i++)
	{
		data = readl(my_led.led_status[i].baseaddr);
		data &= ~(0xf << my_led.led_status[i].pin * 4);
		data |= (0x1 << my_led.led_status[i].pin * 4);
		writel(data, my_led.led_status[i].baseaddr);
	}
	
	return 0;
}

long led_ioctl(struct file* ops, unsigned int cmd, unsigned long arg)
{
	/*unsigned int id = iminor(ops->f_inode); 获得次设备号 */
	switch (arg)
	{
		case 0:
			switch (cmd)
    	{
    		case LED_ON:
    			led_on(0);
    		return 0;
    		case LED_OFF:
    			led_off(0);
    		return 0;
    		default:
    		return -1;
    	}
		break;
		
		case 1:
			switch (cmd)
    	{
    		case LED_ON:
    			led_on(1);
    		return 0;
    		case LED_OFF:
    			led_off(1);
    		return 0;
    		default:
    		return -1;
    	}
		break;
		
		case 2:
			switch (cmd)
    	{
    		case LED_ON:
    			led_on1(2);
    		return 0;
    		case LED_OFF:
    			led_off1(2);
    		return 0;
    		default:
    		return -1;
    	}
		break;
		
		case 3:
			switch (cmd)
    	{
    		case LED_ON:
    			led_on1(3);
    		return 0;
    		case LED_OFF:
    			led_off1(3);
    		return 0;
    		default:
    		return -1;
    	}
		break;
		
		case 4:
			switch (cmd)
    	{
    		case LED_ON:
    			led_run();
    		return 0;
    		case LED_OFF:
    			led_stop();
    		return 0;
    		default:
    		return -1;
    	}
		break;
		
		default:
		break;
	}

	return 0;
}

struct file_operations led_fops = 
{
	.open = led_init_pre,
	.unlocked_ioctl = led_ioctl,
};

static int led_init(void)
{
	alloc_chrdev_region(&my_led.led_num, 0, 1, "led");
	printk("%d is installed\n", MAJOR(my_led.led_num));
	cdev_init(&my_led.led_dev, &led_fops);
	cdev_add(&my_led.led_dev, my_led.led_num, 1);
	return 0;
}

static void led_exit(void)
{
	int i = 0;
	printk("module release\n");
	for(i = 0; i < 4; i++)
	{
		iounmap(my_led.led_status[i].baseaddr);
	}
	cdev_del(&my_led.led_dev);
	unregister_chrdev_region(my_led.led_num, 4);
}

module_init(led_init);
module_exit(led_exit);



