#ifndef control_H
#define control_H

#include <QWidget>
#include "show_pic.h"

class show_pic;

class control : public QWidget
{
    Q_OBJECT
public:

    explicit control(show_pic* npic, QWidget *parent = NULL);

private:
   show_pic*     vpic;
   unsigned char buf[36];
   QTimer*       mtimer;
   QTimer*       rtimer;
   QString       sid;
   QString       stem;
   QString       shum;
   QString       slight;
   QString       sacc_x;
   QString       sacc_y;
   QString       sacc_z;
   QString       sadc;
   QString       curtemp;
   QString       curlight;
   unsigned int  id;
   unsigned int  tem;
   unsigned int  hum;
   unsigned int  light;
   int           acc_x;
   int           acc_y;
   int           acc_z;
   float         adc;
//   unsigned int  newtem = 35;
//   unsigned int  newlight = 800;
//   unsigned      char buffer[36] = {0xdd, 0x04, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};



public slots:
    void some_handler();
    void fan_handler();
    void beep_handler();
    void led1_handler();
    void led_7_handler();
    void settemp_handler();
    void setlight_handler();
    void opentemp_handler();
    void openlight_handler();

};

#endif // control_H
