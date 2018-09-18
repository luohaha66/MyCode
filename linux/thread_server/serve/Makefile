BIN = wcamsrv
INC = -I include/
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRC))

CC = arm-linux-gcc
CFLAGS = $(INC) -g

$(BIN) : $(OBJS)
	$(CC) -o $@ $^
	
clean:
	rm -f $(OBJS) $(BIN) *.bak
