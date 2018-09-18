MYMOD ?= adc

PWD = $(shell pwd)  
KERNEL_SRC = /home/ha/linux-3.14
   
obj-m := $(MYMOD).o  
   
all:  
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) dtbs
	arm-linux-gcc adc_app.c -o adc_app
	cp adc_app /home/ha/rootfs/driver/adc/
	cp ~/linux-3.14/arch/arm/boot/dts/exynos4412-fs4412.dtb ~/tftpboot/
	cp $(MYMOD).ko /home/ha/rootfs/driver/adc/
	sudo cp $(MYMOD).ko /home/ha/rootfs/lib/modules/3.14.0/
  
.PHONY: clean     
clean:  
	rm -f *.ko  
	rm -f *.o 
	rm -f modules.order  Module.symvers *.mod.c
