MYMOD ?= pwm_dri

PWD = $(shell pwd)  
KERNEL_SRC = /home/ha/linux-3.14
   
obj-m := $(MYMOD).o  
   
all:  
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules
	arm-linux-gcc pwm_app.c -o pwm_app
	cp pwm_app /home/ha/rootfs/driver/pwm_plat/
	cp $(MYMOD).ko /home/ha/rootfs/driver/pwm_plat/
	sudo cp $(MYMOD).ko /home/ha/rootfs/lib/modules/3.14.0/
  
.PHONY: clean     
clean:  
	rm -f *.ko  
	rm -f *.o 
	rm -f modules.order  Module.symvers *.mod.c
