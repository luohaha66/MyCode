/**gtk±à³Ì²Î¿¼
http://blog.csdn.net/lianghe_work/article/details/47087109
http://blog.csdn.net/exbob/article/details/6932864
http://blog.csdn.net/fykhlp/article/details/5985131
*/

#include <gtk/gtk.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>


#define DEF_CONN_IP 	"192.168.1.230"
#define DEF_PORT 	    "19868"
#define LOGO_IMG  	    "./icons/webcam_icon.png"
#define LOGO_IMG1  	    "./icons/wcamclient.png"

#define WIN_TITLE 	        "Web Camera"
#define WIN_ICON	        "./icons/icon.png"

#define SNAP_BUTTON_IMG	    "./icons/snap-icon-small.xpm"
#define SETTING_BUTTON_IMG	"./icons/settings.png"

#define WCAM_VERSION 	    "Web Camera 2.0"
#define WCAM_HOMEPAGE 	    "http://www.enjoylinux.cn"
#define SNAPSHOT_PATH       IMGDIR

    #define FRAME_MAX_SZ    253
    #define VID_FRAME_MAX_SZ    (0xFFFFF - FRAME_MAX_SZ)

struct entry_win {
    GtkWidget   *win;
    GtkWidget   *ip_entry;
    GtkWidget   *port_entry;
    GtkWidget   *connect_button;
    gboolean    connected;
    int         sock;
};

typedef struct entry_win *entry_win_t;	

typedef void (*wcc_img_proc_t)(const void *p, int size, void *arg);

struct wcam_cli {
    int                     sock;           /* ä¸ŽæœåŠ¡å™¨é€šä¿¡çš„å¥—ç»“å­— */
    pthread_t               tid;            /* å¤„ç†çº¿ç¨‹ */      
    bool                    need_stop;
    
    __u8                    req[FRAME_MAX_SZ];
    __u8                    rsp[FRAME_MAX_SZ + VID_FRAME_MAX_SZ];

    wcc_img_proc_t          proc;           /* å›¾åƒå¤„ç†å‡½æ•° */ 
    void                    *arg;           /* å›¾åƒå¤„ç†å‡½æ•°ä¼ å…¥å‚æ•° */
};

typedef struct wcam_cli *wcc_t;


struct wcam_win {
    GtkWidget           *win; 
    wcc_t               client;
    entry_win_t         entry_win; 

    GtkWidget           *video_area; 

    guint32             video_format;
    guint32             video_width;
    guint32             video_height;
    gboolean            video_fullscreen;
    gboolean            need_snapshot;

    //struct wcam_uctls   *uctls;   

    gchar               ipaddr[24];     /* format: "ip :port" */

    GtkWidget           *fps_label;
    GtkWidget           *frmsize_label;
    guint32             frm_cnt;
    guint64             last_twenty_frm_us;

    GtkWidget           *info_area;
    GtkWidget           *button_area;
    GtkWidget           *control_area_button;
    GtkWidget           *control_area;

};

__u64 clock_get_time_us()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (__u64)ts.tv_sec * 1000000LL + (__u64)ts.tv_nsec / 1000LL;
}

void draw_video_frame(const void *p, int size, void *arg)
{
    struct wcam_win *c      = arg;
    GdkPixbufLoader *pixbuf_loader;
    GdkPixbuf       *pixbuf;
    GdkPixbuf       *pixbuf4fullscreen = NULL;
    GdkScreen       *screen;
    cairo_t         *cr;
    gchar           outstr[100];
    gfloat          fps; 
    guint64         now_us;

    gdk_threads_enter();
    
    /* update frame size label */
    sprintf(outstr, "%d å­—èŠ‚", size);
    gtk_label_set_text(GTK_LABEL(c->frmsize_label), outstr);

    /* update fps label */
    c->frm_cnt++;
    if (c->frm_cnt == 1) {
        c->last_twenty_frm_us = clock_get_time_us();
    } else if (c->frm_cnt > 10) {
        now_us = clock_get_time_us();
        fps = 10.0 * 1000000.0 / (now_us - c->last_twenty_frm_us);
        c->frm_cnt = 0;
        sprintf(outstr, "%2.1f å¸§/ç§’", fps);
        gtk_label_set_text(GTK_LABEL(c->fps_label), outstr);
    }

    /* update video */
    pixbuf_loader = gdk_pixbuf_loader_new(); 		
    gdk_pixbuf_loader_write(pixbuf_loader, p, size, NULL); 
    gdk_pixbuf_loader_close(pixbuf_loader, NULL); 
    pixbuf = gdk_pixbuf_loader_get_pixbuf(pixbuf_loader); 

    /*´´½¨cairo*/
    cr = gdk_cairo_create(c->video_area->window);
    
    /*µ¼ÈëÍ¼Ïñ*/
    gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
	
    /*»æÖÆÍ¼Ïñ*/
    cairo_paint(cr);
    cairo_destroy(cr);

    g_object_unref(pixbuf_loader);
    if (pixbuf4fullscreen)
        g_object_unref(pixbuf4fullscreen);
        
	gdk_threads_leave();

    if (c->need_snapshot) {     /* Maybe we should open a file_save_dialog here */
        char img_path[100];     /* or maybe we should make the image_storage_path Configurable */ 
        FILE *fp;               
        time_t t;
        struct tm *tmp;
        t = time(NULL);
        tmp = localtime(&t);

        strftime(outstr, sizeof(outstr), "%F-%T", tmp);
        printf(SNAPSHOT_PATH"/webcam-%s.jpg\n", outstr);
        printf(SNAPSHOT_PATH"/webcam-%s.jpg", outstr);
        sprintf(img_path, SNAPSHOT_PATH"/webcam-%s.jpg", outstr);
        fp = fopen(img_path, "w");        
        fwrite(p, size, 1, fp);
        fclose(fp);
        c->need_snapshot = FALSE;
    }
}

static void connect_handler(GtkButton *button, gpointer data) 
{
    	struct entry_win *c = data;
    	const gchar      *ip;
    	gint16           port;
	
	/*¶ÁÈ¡IPºÍ¶Ë¿Ú*/
	ip   = gtk_entry_get_text(GTK_ENTRY(c->ip_entry));
	port = atoi(gtk_entry_get_text(GTK_ENTRY(c->port_entry)));
    
        c->connected = TRUE;
        gtk_main_quit();   
}

static gboolean logo_draw(struct entry_win *c, GtkWidget* box)
{
	gtk_box_pack_start_defaults(GTK_BOX(box), gtk_image_new_from_file(LOGO_IMG));
	gtk_box_pack_start_defaults(GTK_BOX(box), gtk_image_new_from_file(LOGO_IMG1));
	return TRUE;
}

static gboolean entry_area_draw(struct entry_win *c, GtkWidget* box)
{
	GtkWidget *label;	
	GtkWidget *entry;	

        /*´´½¨±êÇ©*/
	label = gtk_label_new("Server Ip:");
    	gtk_box_pack_start_defaults(GTK_BOX(box), label);
	
	/*´´½¨ÎÄ±¾ÊäÈë¿ò*/
	entry = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry), DEF_CONN_IP);
	gtk_entry_set_max_length(GTK_ENTRY(entry), 15);

    	gtk_box_pack_start_defaults(GTK_BOX(box), entry);
        c->ip_entry = entry;	
	
        /*´´½¨±êÇ©*/
	label = gtk_label_new("Server Port:");
        gtk_box_pack_start_defaults(GTK_BOX(box), label);	
        
        /*´´½¨ÎÄ±¾ÊäÈë¿ò*/
	entry = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entry), DEF_PORT);
	gtk_entry_set_max_length(GTK_ENTRY(entry), 5);

    	gtk_box_pack_start_defaults(GTK_BOX(box), entry);	
    	c->port_entry = entry;	

	return TRUE;
}

static gboolean button_area_draw(struct entry_win *c, GtkWidget* box)
{
	GtkWidget *button;
	
	/* ´´½¨´øÎÄ×ÖµÄ°´Å¥ */
	button = gtk_button_new_with_label("OK");  
    	gtk_box_pack_start_defaults(GTK_BOX(box), button);
    	c->connect_button = button;
	
	/*¹ØÁª°´Å¥µã»÷ÊÂ¼þ*/
    	g_signal_connect(button, "clicked", G_CALLBACK(connect_handler), c);		

	/* ´´½¨´øÎÄ×ÖµÄ°´Å¥ */
	button = gtk_button_new_with_label("Cancel");  
    	gtk_box_pack_start_defaults(GTK_BOX(box), button);
	
    	g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL);	

	return TRUE;
}


static gboolean entry_win_draw_face(struct entry_win *c)
{
    GtkWidget *vbox;
    GtkWidget *hbox;	

    /*´´½¨´¹Ö±²¼¾ÖÈÝÆ÷*/
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(c->win), vbox);          
 	
    /*´´½¨Ë®Æ½²¼¾ÖÈÝÆ÷*/
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
	
    /*»æÖÆlogo*/
    logo_draw(c, hbox);

    /*ÊäÈëipºÍ¶Ë¿Ú*/
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
    entry_area_draw(c, hbox);

    /*´´½¨Ë®Æ½°´¼ü²¼¾ÖÈÝÆ÷*/
    hbox = gtk_hbutton_box_new();
    /*ÉèÖÃ°´Å¥¼äÐª*/
    gtk_box_set_spacing(GTK_BOX(hbox), 5);
    gtk_button_box_set_layout(GTK_BUTTON_BOX(hbox), GTK_BUTTONBOX_END);	
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
    button_area_draw(c, hbox);

    return TRUE;
}

static gboolean
key_press_func(GtkWidget* widget, GdkEventKey* key, gpointer data)
{
#define KEY_ENTER 0xff0d
#define KEY_ESC   0xff1b
    struct entry_win *c = data;
    if (KEY_ENTER == key->keyval) {
		connect_handler(GTK_BUTTON(c->connect_button), c); 
        return TRUE;
    } else if (KEY_ESC == key->keyval) {
		c->connected = FALSE; 
        gtk_main_quit();
        return TRUE;
    }
	return FALSE;
#undef  KEY_ENTER
#undef  KEY_ESC
} 

entry_win_t login_create()
{
    struct entry_win *c = calloc(1, sizeof(struct entry_win));
    if (!c) {
		perror("entry_win_create");
		return NULL;
	}

    /*---´´½¨ÐÂ´°¿Ú---*/
    c->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);     
 
    /*---ÉèÖÃ´°¿Ú±êÌâ---*/
    gtk_window_set_title(GTK_WINDOW(c->win), WIN_TITLE); 
    
    /*---ÉèÖÃ´°¿ÚÍ¼±ê---*/              
    gtk_window_set_icon(GTK_WINDOW(c->win), gdk_pixbuf_new_from_file(WIN_ICON, NULL));
    
    /*---ÉèÖÃ´°¿ÚÎ»ÖÃ---*/  
    gtk_window_set_position(GTK_WINDOW(c->win), GTK_WIN_POS_CENTER); 
    
    /*---ÉèÖÃ´°¿ÚÊÇ·ñ¿ÉÉìËõ---*/
    gtk_window_set_resizable(GTK_WINDOW(c->win), FALSE);    
    
    /*---ÉèÖÃ´°¿Ú±ß¿ò¿í¶È---*/
    gtk_container_set_border_width(GTK_CONTAINER(c->win), 0); 
    
    /*---¹ØÁªÍË³öÐÅºÅÓë´¦Àíº¯Êý---*/
    g_signal_connect(GTK_OBJECT(c->win), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    /*---¹ØÁª°´¼üÐÅºÅÓë´¦Àíº¯Êý---*/
    g_signal_connect(G_OBJECT(c->win), "key_press_event", G_CALLBACK(key_press_func), c);
	
    entry_win_draw_face(c);
	
    gtk_widget_show_all(c->win);
    return c;
}

int login_run(entry_win_t win)
{
    struct entry_win *c = win; 
    /*Æô¶¯¸Ã´°¿Ú*/
    gtk_main();
    return c->connected == TRUE ? 0 : -1;
}

void login_hide(entry_win_t win)
{
    struct entry_win *c = win; 
    gtk_widget_hide_all(c->win);
}



/*------------Ö÷´°¿Ú-------------------*/

int entry_win_get_ip(entry_win_t win, char *ip)
{
    struct entry_win *c = win; 
    if (c->connected == FALSE)
        return -1;
    strcpy(ip, gtk_entry_get_text(GTK_ENTRY(c->ip_entry)));
    return 0;
}

int entry_win_get_port(entry_win_t win, char *port)
{
    struct entry_win *c = win; 
    if (c->connected == FALSE)
        return -1;
    strcpy(port, gtk_entry_get_text(GTK_ENTRY(c->port_entry)));
    return 0;
}

void main_quit(GtkWidget *Object, gpointer data) 
{
    gtk_main_quit();
}

static gboolean
draw_area_draw(struct wcam_win *c, GtkWidget *box)
{
    /*´´½¨Í¼ÏñÏÔÊ¾ÇøÓò*/
    c->video_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(c->video_area, c->video_width, c->video_height);
	gtk_box_pack_start(GTK_BOX(box), c->video_area, FALSE, FALSE, 0);
	
    gtk_widget_add_events(c->video_area, GDK_BUTTON_PRESS_MASK);

	return TRUE;
}

static gboolean
info_area_draw(struct wcam_win *c, GtkWidget *box)
{
	GtkWidget   *frame;
	GtkWidget   *table;
	GtkWidget   *label;
	GtkWidget   *align;
	GtkWidget   *separator;
    gchar       buf[256];

	frame = gtk_frame_new("ä¿¡æ¯åŒº");
    c->info_area = frame;
	gtk_box_pack_start_defaults(GTK_BOX(box), frame);

	table = gtk_table_new(9, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(frame), table);
	
    /* VERSION & HOMEPAGE */
    label = gtk_label_new("ä¸»é¡µ:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 0, 1,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_link_button_new_with_label(WCAM_HOMEPAGE, "www.enjoylinux.cn");
    align = gtk_alignment_new(0, 0, 0, 0);	            /* å·¦å¯¹é½ */
    gtk_container_add(GTK_CONTAINER(align), label);	
    gtk_table_attach(GTK_TABLE(table), align, 1, 2, 0, 1,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_label_new("ç‰ˆæœ¬:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 1, 2,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_label_new(WCAM_VERSION);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 1, 2,
                     GTK_FILL, GTK_SHRINK, 8, 1);

    /* IP & PORT */
    label = gtk_label_new("æœåŠ¡å™¨:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 2, 3,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_label_new(c->ipaddr);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 2, 3,
                     GTK_FILL, GTK_SHRINK, 8, 1);

    separator = gtk_hseparator_new(); 
    gtk_table_attach(GTK_TABLE(table), separator, 0, 1, 3, 4,
                     GTK_FILL, GTK_SHRINK, 1, 1);
    separator = gtk_hseparator_new(); 
    gtk_table_attach(GTK_TABLE(table), separator, 1, 2, 3, 4,
                     GTK_FILL | GTK_EXPAND, GTK_SHRINK, 1, 1);

    /* Frame Format */
    label = gtk_label_new("å¸§æ ¼å¼:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 4, 5,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    sprintf(buf, "%c%c%c%c", (c->video_format)&0xFF,
                             (c->video_format>>8)&0xFF,
                             (c->video_format>>16)&0xFF,
                             (c->video_format>>24)&0xFF);
    label = gtk_label_new(buf);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 4, 5,
                     GTK_FILL, GTK_SHRINK, 8, 1);

    /* Frame width x height */
    label = gtk_label_new("å¸§å°ºå¯¸:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 5, 6,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    sprintf(buf, "%d x %d", c->video_width, c->video_height); 
    label = gtk_label_new(buf);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 5, 6,
                     GTK_FILL, GTK_SHRINK, 8, 1);

    /* Frame Size */
    label = gtk_label_new("å¸§å¤§å°:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 6, 7,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_label_new("0");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 6, 7,
                     GTK_FILL, GTK_SHRINK, 8, 1);
    c->frmsize_label = label;

    /* FPS */
    label = gtk_label_new("å¸§é€ŸçŽ‡:");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 0, 1, 7, 8,
                     GTK_FILL, GTK_SHRINK, 1, 1);

    label = gtk_label_new("0");
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_table_attach(GTK_TABLE(table), label, 1, 2, 7, 8,
                     GTK_FILL, GTK_SHRINK, 8, 1);
    c->fps_label = label;

    /* hseparator */
    separator = gtk_hseparator_new(); 
    gtk_table_attach(GTK_TABLE(table), separator, 0, 1, 8, 9,
                     GTK_FILL, GTK_SHRINK, 1, 1);
    separator = gtk_hseparator_new(); 
    gtk_table_attach(GTK_TABLE(table), separator, 1, 2, 8, 9,
                     GTK_FILL, GTK_SHRINK, 1, 1);

	return TRUE;
}

static gboolean main_button_area_draw(struct wcam_win *c, GtkWidget *box)
{
	GtkWidget *buttonbox;		
	GtkWidget *button;		
	GtkWidget *hbox;		
	GtkWidget *label;	
	GtkWidget *image;	

	buttonbox = gtk_hbutton_box_new();
    gtk_box_pack_start(GTK_BOX(box), buttonbox, FALSE, FALSE, 0);
    c->button_area = buttonbox;
 	/* control button */
	image = gtk_image_new_from_file(SETTING_BUTTON_IMG);
	label = gtk_label_new("æ˜¾ç¤ºæŽ§åˆ¶é¡¹ ");
	hbox = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), image);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), label);

	button = gtk_check_button_new();	
	gtk_container_add(GTK_CONTAINER(button), hbox);
    c->control_area_button = button;
	
	gtk_box_pack_start_defaults(GTK_BOX(buttonbox), button);	
	
 	/* snapshot button */
	image = gtk_image_new_from_file(SNAP_BUTTON_IMG);
	label = gtk_label_new("å¿«ç…§");
	hbox  = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), image);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), label);

	button = gtk_button_new();	
	gtk_container_add(GTK_CONTAINER(button), hbox);
	
	gtk_box_pack_start_defaults(GTK_BOX(buttonbox), button);
  

	return TRUE;
}

static gboolean main_win_draw_face(struct wcam_win *c)
{
    GtkWidget *box;
    GtkWidget *hbox;	
    GtkWidget *hseparator;	

    box = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(c->win), box);          

 	/* draw_area & info_area */
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), hbox, FALSE, TRUE, 0);
	draw_area_draw(c, hbox);
    info_area_draw(c, hbox);	

 	/* hseparator */
	hseparator=gtk_hseparator_new(); 
    gtk_box_pack_start(GTK_BOX(box), hseparator, FALSE, TRUE, 0);
    
 	/* button_area */
    main_button_area_draw(c, box);

 	/* control_area */
   // control_area_draw(c, box);

    return TRUE;
}

static gboolean main_create(struct wcam_win *c)
{
    int len;
    /*------------³õÊ¼»¯----------------*/
    c->video_width = 640;
    c->video_height = 480;

    /* fullscreen */
    c->video_fullscreen = FALSE;
    
    /* ip & port */
    entry_win_get_ip(c->entry_win, c->ipaddr);

    len = strlen(c->ipaddr);

    c->ipaddr[len] = ':';
    entry_win_get_port(c->entry_win, &c->ipaddr[len+1]);
	
	
    c->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
 	
    /* è®¾ç½®çª—å£æ ‡é¢˜ */
    gtk_window_set_title(GTK_WINDOW(c->win), WIN_TITLE);                

    gtk_window_set_icon(GTK_WINDOW(c->win), 
                        gdk_pixbuf_new_from_file(WIN_ICON, NULL));
    
    /* çª—å£è¾¹æ¡†å¤§å°è®¾ç½®ä¸º0 */
    gtk_container_set_border_width(GTK_CONTAINER(c->win), 0); 
    
    g_signal_connect(c->win, "destroy",
                     G_CALLBACK(main_quit), c);
    gtk_widget_set_app_paintable(c->win, TRUE);

	main_win_draw_face(c);

    gtk_widget_show_all(c->win);
    //toggle_control_area(GTK_TOGGLE_BUTTON(c->control_area_button), c);
    
    gtk_widget_hide(c->win);
    gtk_window_set_position(GTK_WINDOW(c->win), GTK_WIN_POS_CENTER); 
    gtk_widget_show(c->win);

    return TRUE;
}

void main_run( )
{
    gtk_main();
}

gint main(gint argc,gchar* argv[])
{	
    int res;
    
    /*---GTK³õÊ¼»¯----*/
    gtk_init(&argc, &argv);	
    g_thread_init(NULL);
    gdk_threads_init();

    struct wcam_win *c = calloc(1, sizeof(struct wcam_win));

    c->entry_win = login_create();
    
    res = login_run(c->entry_win);
    if (res == -1) {
        goto err_win;
    }
    
    login_hide(c->entry_win);
  
    main_create(c);
    
    main_run();

err_win:
    free(c->entry_win);
    free(c);

    return 0;
}

