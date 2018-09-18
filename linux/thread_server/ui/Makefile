BIN 	= 	wcamclient
PREFIX 	= 	/usr/bin
IMGDIR  =   /root/wcam/images
DESKTOP_ICON = wcamclient.png

DBG     =   
DBG     +=  -DDBG_CLI   

INC 	= 	-Iinclude
LDFLAGS = 	-lpthread -ljpeg  
SRC 	= 	$(wildcard *.c)
OBJS 	= 	$(patsubst %.c, %.o, $(SRC))
LIBS 	=   `pkg-config --libs gthread-2.0 gtk+-2.0`

CC 	 	= 	gcc

CFLAGS 	= 	-Wall $(FUNCS) $(INC) $(DBG) -DPREFIX=\"$(PREFIX)\" -DIMGDIR=\"$(IMGDIR)\"\
            `pkg-config --cflags gthread-2.0 gtk+-2.0` 

#if gtk-2.0 version < 2.32
CFLAGS += 	-DGTK_OLD_VERSION

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS) 	

clean:
	$(RM) $(OBJS) $(BIN)
install:
	mkdir 	-p 	$(IMGDIR)
	mkdir   -p  $(PREFIX)/icons
	install icons/*   $(PREFIX)/icons
	install $(BIN)    $(PREFIX)
	install GQ\ Webcam\ Client.desktop  /usr/share/applications
	install icons/$(DESKTOP_ICON)  /usr/share/pixmaps
uninstall:
	rm 	-r 	$(IMGDIR)
	rm  -r  $(PREFIX)/icons
	rm  $(PREFIX)/$(BIN)
	rm  /usr/share/applications/GQ\ Webcam\ Client.desktop 
	rm  /usr/share/pixmaps/$(DESKTOP_ICON)
