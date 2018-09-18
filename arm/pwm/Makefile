CROSS := arm-linux-
CC := ${CROSS}gcc

all:
	${CC} -c -g start.S -o start.o
	${CC} -c -g main.c -o main.o
	arm-linux-ld -Ttest.lds start.o main.o -o test.elf
	arm-linux-objcopy -O binary test.elf test.bin
clean:
	rm -f *.o *.elf *.bin
 
