MYMOD ?= led

PWD = $(shell pwd)  
KERNEL_SRC = /home/ha/linux-3.14
   
obj-m := $(MYMOD).o  
   
all:  
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules
	arm-linux-gcc led_app.c -o led_app 
	cp $(MYMOD).ko led_app /home/ha/rootfs/driver/led_mmp/
	cp $(MYMOD).ko /lib/modules/3.14.0/
  
.PHONY: clean     
clean:  
	rm -f *.ko  
	rm -f *.o 
	rm -f modules.order  Module.symvers *.mod.c
