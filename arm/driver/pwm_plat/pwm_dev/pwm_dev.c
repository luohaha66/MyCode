#include "pwm_dev.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Luo@haha");
MODULE_DESCRIPTION("a simple pwm device");

static int mymodule_init(void)
{
	my_pwm.pwm_dev = platform_device_alloc("pwm", -1);
	
	platform_device_add_resources(my_pwm.pwm_dev, pwm_res, 2);

	platform_device_add(my_pwm.pwm_dev);
	printk("pwm_device install\n");
	return 0;
}

static void mymodule_exit(void)
{
	platform_device_del(my_pwm.pwm_dev);
	printk("pwm_device release\n");
}


module_init(mymodule_init);
module_exit(mymodule_exit);



