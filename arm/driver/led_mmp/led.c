#include "led.h"

MODULE_LICENSE("Dual BSD/GPL");

int led_mmap(struct file* ops, struct vm_area_struct* vma)
{
	printk("led mmap!\n");
	remap_pfn_range(vma, vma->vm_start, LED1CON>>PAGE_SHIFT,
	vma->vm_end - vma->vm_start, vma->vm_page_prot);
	return 0;
}

struct file_operations led_fops = 
{
	.mmap = led_mmap,
};

static int led_init(void)
{
	alloc_chrdev_region(&led_num, 0, 1, "led");
	printk("%d is installed\n", MAJOR(led_num));
	cdev_init(&led_dev, &led_fops);
	cdev_add(&led_dev, led_num, 1);
	return 0;
}

static void led_exit(void)
{
	printk("module release\n");
	cdev_del(&led_dev);
	unregister_chrdev_region(led_num, 4);
}

module_init(led_init);
module_exit(led_exit);



