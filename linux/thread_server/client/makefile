BIN = wcamclient

LDFLAGS = -lpthread

SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))

LIBS 	=   `pkg-config --libs gthread-2.0 gtk+-2.0`
LDFLAGS = 	-lpthread -ljpeg 

CFLAGS 	= 	-Wall $(FUNCS) $(INC) $(DBG) -DPREFIX=\"$(PREFIX)\" -DIMGDIR=\"$(IMGDIR)\"\
            `pkg-config --cflags gthread-2.0 gtk+-2.0` 

CC 	 	= 	gcc


$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS) 

clean:
	rm -f $(BIN) $(OBJS) *.bak
