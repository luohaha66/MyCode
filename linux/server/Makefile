BIN = server
INC = -I include/
SRC = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRC))

CC = gcc
CFLAGS = $(INC) 

$(BIN) : $(OBJS)
	$(CC) -o $@ $^ -lpthread
	
clean:
	rm -f $(OBJS) $(BIN) *.bak