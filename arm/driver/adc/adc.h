#ifndef _ADC_H_
#define _ADC_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <asm/io.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/of.h>
#include <linux/interrupt.h>
#include <linux/err.h>

int adc_remove(struct platform_device* dev);

struct {
	struct cdev adc_dev;
	struct class* adc_class;
	struct device* adc_device;
	struct resource* res_con;
	struct resource* res_dat;
	struct resource* res_mux;
	struct resource* res_irq;
	unsigned int* conaddr;
	unsigned int* dataddr;
	unsigned int* muxaddr;
	unsigned int adc_data;
  dev_t adc_num;
}my_adc;

#endif