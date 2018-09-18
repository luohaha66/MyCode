#include "adc.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Luo@haha");
MODULE_DESCRIPTION("a simple adc_driver!");

irqreturn_t adc_handler(int irq, void *dev)
{
	unsigned int data = 0;
	int h = 0;
	int w = 0;
	data = ioread32(my_adc.dataddr);
	my_adc.adc_data = data & 0xfff;
	my_adc.adc_data = my_adc.adc_data * 18 / 4096;
	h = my_adc.adc_data / 10;
	w = my_adc.adc_data % 10;
	printk("now the adc is: %d.%d v\n", h, w);
	return IRQ_HANDLED;	
}

int adc_init_pre(struct inode* node, struct file* ops)
{
	unsigned int data = 0;
	data |= (0x1 << 16 | 0x1 << 14 | 0xff << 6);
	iowrite32(data, my_adc.conaddr);
	
	iowrite32(0x3, my_adc.muxaddr);
	
	data = ioread32(my_adc.conaddr);
	data |= 0x1 << 0;
	iowrite32(data, my_adc.conaddr);
	
	return 0;
}

struct file_operations adc_fops = 
{
	.owner = THIS_MODULE,
	.open = adc_init_pre
};

int adc_probe(struct platform_device* dev)
{
	my_adc.res_con = platform_get_resource(dev, IORESOURCE_MEM, 0);
	my_adc.conaddr = ioremap(my_adc.res_con->start, 
	my_adc.res_con->end - my_adc.res_con->start);
	
	my_adc.res_dat = platform_get_resource(dev, IORESOURCE_MEM, 1);
	my_adc.dataddr = ioremap(my_adc.res_dat->start, 
	my_adc.res_dat->end - my_adc.res_dat->start);
	
	my_adc.res_mux= platform_get_resource(dev, IORESOURCE_MEM, 2);
	my_adc.muxaddr = ioremap(my_adc.res_mux->start, 
	my_adc.res_mux->end - my_adc.res_mux->start);
	  
	alloc_chrdev_region(&my_adc.adc_num, 0, 1, "adc");
	printk("adc_driver %d is installed\n", MAJOR(my_adc.adc_num));
	cdev_init(&my_adc.adc_dev, &adc_fops);
	cdev_add(&my_adc.adc_dev, my_adc.adc_num, 1);
	
	my_adc.adc_class = class_create(THIS_MODULE, "adc");
	my_adc.adc_device = device_create(my_adc.adc_class, NULL, my_adc.adc_num, NULL, "adc");
	
	my_adc.res_irq= platform_get_resource(dev, IORESOURCE_IRQ, 0);
	if((request_irq(my_adc.res_irq->start, adc_handler,
	  (my_adc.res_irq->flags & IRQF_TRIGGER_MASK), NULL, NULL)) != 0)
	  {
	  	 printk("request_irq error");
	  	 adc_remove(dev);
	  	 return -1;
	  }
	return 0;
}

int adc_remove(struct platform_device* dev)
{
	printk("adc_driver release\n");
	iounmap(my_adc.dataddr);
	iounmap(my_adc.conaddr);
	iounmap(my_adc.muxaddr);
	cdev_del(&my_adc.adc_dev);
	unregister_chrdev_region(my_adc.adc_num, 1);
	device_destroy(my_adc.adc_class, my_adc.adc_num);
	class_destroy(my_adc.adc_class);
	return 0;
}

struct of_device_id adc_tab[] = {
	{
		.compatible = "adc"
	},
	
	{
		
	}
};

struct platform_driver adc_driver = {
	.probe = adc_probe,
	.remove = adc_remove,
	.driver = {
		.name = "adc",
		.of_match_table = adc_tab
	}
};

static int adc_init(void)
{
	platform_driver_register(&adc_driver);
	return 0;
}

static void adc_exit(void)
{
	platform_driver_unregister(&adc_driver);
}

module_init(adc_init);
module_exit(adc_exit);



