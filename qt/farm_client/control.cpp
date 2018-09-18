#include "control.h"
#include <QDebug>
#include <stdio.h>
unsigned int  newtem = 35;
unsigned int  newlight = 800;
unsigned      char buffer[36] = {0xdd, 0x04, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

struct serial_data{
    int id;
    int tem;
    int hum;
    int light;
    float adc;
    int x;
    int y;
    int z;
};

control::control(show_pic* npic, QWidget *parent)
    :vpic(npic), QWidget(parent)
{
    mtimer = new QTimer(this);
    rtimer = new QTimer(this);
    light = 0;
    connect(vpic->socket, SIGNAL(readyRead()), this, SLOT(some_handler()));
    //当有数据到来时，处理
    connect(vpic->fan,      SIGNAL(clicked()), this, SLOT(fan_handler()));
    connect(vpic->beep,     SIGNAL(clicked()), this, SLOT(beep_handler()));
    connect(vpic->led1,     SIGNAL(clicked()), this, SLOT(led1_handler()));
    connect(vpic->led_7,    SIGNAL(clicked()), this, SLOT(led_7_handler()));
    connect(vpic->z_temp,   SIGNAL(clicked()), this, SLOT(opentemp_handler()));
    connect(vpic->z_light,  SIGNAL(clicked()), this, SLOT(openlight_handler()));
    connect(mtimer,         SIGNAL(timeout()), this, SLOT(openlight_handler()));
    connect(rtimer,         SIGNAL(timeout()), this, SLOT(opentemp_handler()));
}

void control::some_handler()
{
    struct serial_data data;
    vpic->socket->read((char *)&data,sizeof(struct serial_data));
    sid = QString::number(data.id, 10);
    vpic->d_id->setText(" Device Id: " + sid);
    stem = QString::number(data.tem, 10);
    shum = QString::number(data.hum, 10);
    vpic->temp->setText(" Real T&H: " + stem + "°C  " + shum + "hPa");
    slight = QString::number(data.light, 10);
    vpic->light->setText(" Real Light: " + slight + " cd");
    sacc_x = QString::number(data.x, 10);
    sacc_y = QString::number(data.y, 10);
    sacc_z = QString::number(data.z, 10);
    vpic->acc->setText(" Real Acc: X:" + sacc_x + " Y:" + sacc_y + " Z:" + sacc_z);
    sadc = QString::number(data.adc, 10.0);
    vpic->adc->setText(" Real Adc: " + sadc + " V");

    //    memset(buf, 0, 36);
//    int i=0;
//    unsigned int i1 = 0;
//    unsigned int i2 = 0;
//    unsigned int i3 = 0;
//    unsigned int i4 = 0;
//    QByteArray buff = vpic->socket->readAll();
//    for(i=0; i<36; i++)
//    {
//        buf[i] = (unsigned char) buff[i];

//    }
//    if (buf[0] = 0xbb)
//    {
//        id  = (unsigned int)buf[1];
//        sid = QString::number(id, 10);
//        vpic->d_id->setText(" Device Id: " + sid);

//        tem  = (int)buf[5] + (int)(buf[4]);
//        stem = QString::number(tem, 10);
//        hum  = (int)buf[7] + (int)(buf[6]);
//        shum = QString::number(hum, 10);
//        vpic->temp->setText(" Real T&H: " + stem + "°C  " + shum + "hPa");

//        i1 = (unsigned int)buf[23];
//        i2 = (unsigned int)buf[22];
//        i3 = (unsigned int)buf[21];
//        i4 = (unsigned int)buf[20];
//        i1 = i1 << 24;
//        i2 = i2 << 16;
//        i3 = i3 << 8;
//        light = i1 + i2 + i3 + i4;
//        slight = QString::number(light, 10);
//        vpic->light->setText(" Real Light: " + slight + " cd");

//        if ((acc_x = (int)buf[8]) > 127 )
//        {
//            acc_x  -= 256;
//            sacc_x = QString::number(acc_x, 10);
//        }
//        else
//        {
//           sacc_x = QString::number(acc_x, 10);
//        }

//        if ((acc_y = (int)buf[9]) > 127 )
//        {
//            acc_y  -= 256;
//            sacc_y = QString::number(acc_y, 10);
//        }
//        else
//        {
//           sacc_y = QString::number(acc_y, 10);
//        }

//        if ((acc_z = (int)buf[10]) > 127 )
//        {
//            acc_z  -= 256;
//            sacc_z = QString::number(acc_z, 10);
//        }
//        else
//        {
//           sacc_z = QString::number(acc_z, 10);
//        }

//        vpic->acc->setText(" Real Acc: X:" + sacc_x + " Y:" + sacc_y + " Z:" + sacc_z);

//        adc  = ((float)buf[12]) / 10;
//        sadc = QString::number(adc, 10.0);
//        vpic->adc->setText(" Real Adc: " + sadc + " V");
//    }
//    memset(buf, 0, 36);
}

void control::fan_handler()
{
    if (vpic->fan->isChecked())
    {
        buffer[4] = 0x04;
        vpic->socket->write((const char*)buffer, 36);
    }
    else
    {
        buffer[4] = 0x08;
        vpic->socket->write((const char*)buffer, 36);
    }
}

void control::led1_handler()
{
    if (vpic->led1->isChecked())
    {
        buffer[4] = 0x00;
        vpic->socket->write((const char*)buffer, 36);
    }
    else
    {
        buffer[4] = 0x01;
        vpic->socket->write((const char*)buffer, 36);
    }
}

void control::beep_handler()
{
    if (vpic->beep->isChecked())
    {
        buffer[4] = 0x02;
        vpic->socket->write((const char*)buffer, 36);
    }
    else
    {
        buffer[4] = 0x03;
        vpic->socket->write((const char*)buffer, 36);
    }
}

void control::led_7_handler()
{
    if (vpic->led_7->isChecked())
    {
        buffer[4] = 0x09;
        vpic->socket->write((const char*)buffer, 36);
    }
    else
    {
        buffer[4] = 0x0a;
        vpic->socket->write((const char*)buffer, 36);
    }
}

void control::opentemp_handler()
{
    if (vpic->z_temp->isChecked())
    {
        curtemp = QString::number(newtem, 10);
        vpic->c_temp->setText("当前设定值: " + curtemp);
        if ( tem > newtem)
        {
            buffer[4] = 0x02;
            vpic->socket->write((const char*)buffer, 36);
        }
        rtimer->start(1500);
        connect(vpic->set_temp, SIGNAL(clicked()), this, SLOT(settemp_handler()));
    }
    else
    {
        rtimer->stop();
        vpic->c_temp->setText(NULL);
    }
}

void control::openlight_handler()
{
    if (vpic->z_light->isChecked())
    {
        curlight = QString::number(newlight, 10);
        vpic->c_light->setText("当前设定值: " + curlight);
        if ( light < newlight)
        {
            buffer[4] = 0x00;
            vpic->socket->write((const char*)buffer, 36);
        }
        mtimer->start(1500);
        connect(vpic->set_light, SIGNAL(clicked()), this, SLOT(setlight_handler()));
    }
    else
    {
        mtimer->stop();
        vpic->c_light->setText(NULL);
    }
}

void control::settemp_handler()
{
    curtemp = vpic->temp_z->text();
    newtem  = curtemp.toInt();
    vpic->c_temp->setText("当前设定值: " + curtemp);
}

void control::setlight_handler()
{
    curlight = vpic->light_z->text();
    newlight = curlight.toInt();
    vpic->c_light->setText("当前设定值: " + curlight);
}
