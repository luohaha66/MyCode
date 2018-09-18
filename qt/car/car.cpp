#include "car.h"
#include "ui_car.h"

car::car(QString n_ip, unsigned int n_port, QWidget *parent) :
    ip(n_ip), port(n_port), QDialog(parent),
    ui(new Ui::car)
{
    ui->setupUi(this);
    this->setWindowTitle("Car Control"); //设置界面标题
    this->setWindowIcon(QIcon(":/image/car.png")); //设置界面图标
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角

    this->setAutoFillBackground(true);
    QPalette uipa;
    QPixmap pix(":/image/5.png");
    uipa.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(uipa); //设置窗体背景图片

    QString buttonstyle =
                      "QPushButton{color:#55ffff;border:0;}"
                      "QPushButton:!hover:!pressed{border-image:url(:/image/2.png)}"
                      "QPushButton:hover{border-image:url(:/image/1.png)}"
                      "QPushButton:pressed{border-image:url(:/image/2.png)}";
    QFont buttonfont("Century Schoolbook L", 14, 75);
    ui->l1->setStyleSheet(buttonstyle);
    ui->l1->setFont(buttonfont);
    ui->l2->setStyleSheet(buttonstyle);
    ui->l2->setFont(buttonfont);
    ui->l3->setStyleSheet(buttonstyle);
    ui->l3->setFont(buttonfont);
    ui->l4->setStyleSheet(buttonstyle);
    ui->l4->setFont(buttonfont);
    ui->l5->setStyleSheet(buttonstyle);
    ui->l5->setFont(buttonfont);
    ui->l6->setStyleSheet(buttonstyle);
    ui->l6->setFont(buttonfont);
    ui->l7->setStyleSheet(buttonstyle);
    ui->l7->setFont(buttonfont);
    ui->l8->setStyleSheet(buttonstyle);
    ui->l8->setFont(buttonfont);
    ui->l9->setStyleSheet(buttonstyle);
    ui->l9->setFont(buttonfont);

    QString spinstyle =
        "QSpinBox{color:#700000;}"
        "QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right;image: url(:/image/right.png);width: 18px;height: 25px;}"
        "QSpinBox::down-button {subcontrol-origin:border; subcontrol-position:left;image: url(:/image/left.png);width:18px;height: 25px;}"
        "QSpinBox::up-button:pressed {subcontrol-origin:border; subcontrol-position:right;image: url(:/image/right1.png);width:18px;height: 25px;}"
        "QSpinBox::down-button:pressed {subcontrol-origin:border; subcontrol-position:left;image: url(:/image/left1.png);width:18px;height: 25px;}";
    ui->engine_7->setStyleSheet(spinstyle);
    ui->engine_8->setStyleSheet(spinstyle);
    ui->r_speed->setStyleSheet(spinstyle);
    ui->l_speed->setStyleSheet(spinstyle);
    ui->engine_7->setRange(0, 180);
    ui->engine_8->setRange(0, 180);
    ui->r_speed->setRange(0, 10);
    ui->l_speed->setRange(0, 10);
    ui->engine_7->setFixedSize(80, 35);
    ui->engine_8->setFixedSize(80, 35);
    ui->r_speed->setFixedSize(70, 35);
    ui->l_speed->setFixedSize(70, 35);

    QString radiostyle =
            "QRadioButton{spacing: 10px;background-color:#ffffff;color:#00ffff;}"
            "QRadioButton::indicator {width: 65px;height: 35px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c1.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c5.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on.png);}";
    ui->module_1->setStyleSheet(radiostyle);
    ui->module_2->setStyleSheet(radiostyle);
    ui->module_3->setStyleSheet(radiostyle);
    ui->module_4->setStyleSheet(radiostyle);

    QString ledstyle =
                "QRadioButton{spacing: 10px;background-color:#ffffff;color:#aa00ff;}"
                "QRadioButton::indicator {width: 65px;height: 35px;}"
                "QRadioButton::indicator:unchecked {image: url(:/image/off1.png);}"
                "QRadioButton::indicator:unchecked:hover {image: url(:/image/c2.png);}"
                "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off1.png);}"
                "QRadioButton::indicator:checked {image: url(:/image/on1.png);}"
                "QRadioButton::indicator:checked:hover {image: url(:/image/c6.png);}"
                "QRadioButton::indicator:checked:pressed {image: url(:/image/on1.png);}";
     ui->led->setStyleSheet(ledstyle);
     ui->camera->setStyleSheet(ledstyle);

     ui->video->setFixedHeight(320);
     ui->video->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::JavaEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
     ui->video->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
     ui->video->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::SpatialNavigationEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::LinksIncludedInFocusChain, true);
     ui->video->settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
     ui->video->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
     ui->video->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
     ui->video->settings()->enablePersistentStorage("F:/qt5.5_work/cache");
     ui->video->settings()->setIconDatabasePath("/home/ha/qt_work/cache");
     ui->video->settings()->setLocalStoragePath("/home/ha/qt_work/cache");
     ui->video->settings()->setOfflineStoragePath("/home/ha/qt_work/cache");
     ui->video->settings()->setOfflineWebApplicationCachePath("/home/ha/qt_work/cache");

     flag = false;
     socket = new QTcpSocket();
     socket->connectToHost(ip, port);

     connect(socket, SIGNAL(connected()), this, SLOT(new_connect()));
     connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(messge_error()));
     connect(socket, SIGNAL(disconnected()), this, SLOT(discon_from_host()));
     connect(socket, SIGNAL(readyRead()), this, SLOT(control_car()));
}

car::~car()
{
    delete ui;
}

void car::new_connect()
{
    ui->status->setText("Connect Successful");
    flag = true;
}


void car::messge_error()
{
    ui->status->setText("Error IP or Port");
}

void car::discon_from_host()
{
    ui->status->setText("Connect is Interrupt");
}

void car::on_button_clicked()
{
    if(!flag)
        return;
    QPushButton* button = static_cast<QPushButton*>(sender());
    QString butext(button->text());
    if(butext == "s")
        buff[2] = 0x00;
    if(butext == "↑")
        buff[2] = 0x01;
    if(butext == "↓")
        buff[2] = 0x02;
    if(butext == "←")
        buff[2] = 0x03;
    if(butext == "→")
        buff[2] = 0x04;
    if(butext == "↖")
        buff[2] = 0x05;
    if(butext == "↙")
        buff[2] = 0x06;
    if(butext == "↗")
        buff[2] = 0x07;
    if(butext == "↘")
        buff[2] = 0x08;
    socket->write((const char*)buffer, 5);
}

void car::on_spinbox_changed()
{
    if(!flag)
        return;
    QSpinBox* spin = static_cast<QSpinBox*>(sender());
    std::string str = spin->objectName().toStdString();
    const char* name = str.c_str();
    if (qstrcmp(name, "engine_7") == 0)
    {
        bool ok;
        char buf_tem[1];
        QString value = ui->engine_7->text();
        int temp = value.toInt(&ok, 10);
        buffer[1] = 0x01;
        buffer[2] = 0x07;
        sprintf(buf_tem, "%x", temp);
        buffer[3] = (unsigned char)buf_tem[0];
    }
    if (qstrcmp(name, "engine_8") == 0)
    {
        bool ok;
        char buf_tem[1];
        QString value = ui->engine_8->text();
        int temp = value.toInt(&ok, 10);
        buffer[1] = 0x01;
        buffer[2] = 0x08;
        sprintf(buf_tem, "%x", temp);
        buffer[3] = (unsigned char)buf_tem[0];
    }
    if (qstrcmp(name, "l_speed") == 0)
    {
        bool ok;
        char buf_tem[1];
        QString value = ui->l_speed->text();
        int temp = value.toInt(&ok, 10);
        buffer[1] = 0x02;
        buffer[2] = 0x01;
        sprintf(buf_tem, "%x", temp);
        buffer[3] = (unsigned char)buf_tem[0];
    }
    if (qstrcmp(name, "r_speed") == 0)
    {
        bool ok;
        char buf_tem[1];
        QString value = ui->r_speed->text();
        int temp = value.toInt(&ok, 10);
        buffer[1] = 0x02;
        buffer[2] = 0x02;
        sprintf(buf_tem, "%x", temp);
        buffer[3] = (unsigned char)buf_tem[0];
    }
    socket->write((const char*)buffer, 5);
}

void car::on_radio_clicked()
{
    if(!flag)
        return;
    QRadioButton* radio = static_cast<QRadioButton*>(sender());
    std::string str = radio->objectName().toStdString();
    const char* name = str.c_str();
    if(qstrcmp(name, "led") == 0)
    {
        buffer[1] = 0x04;
        if(ui->led->isChecked())
        {
            buffer[2] = 0x00;
        }
        else
        {
            buffer[2] = 0x01;
        }
    }
    if(qstrcmp(name, "module_1") == 0)
    {
        if(ui->module_1->isChecked())
        {
            buffer[1] = 0x13;
            buffer[2] = 0x01;
        }
    }
    if(qstrcmp(name, "module_2") == 0)
    {
        if(ui->module_1->isChecked())
        {
            buffer[1] = 0x13;
            buffer[2] = 0x02;
        }
    }
    if(qstrcmp(name, "module_3") == 0)
    {
        if(ui->module_1->isChecked())
        {
            buffer[1] = 0x13;
            buffer[2] = 0x03;
        }
    }
    if(qstrcmp(name, "module_4") == 0)
    {
        if(ui->module_1->isChecked())
        {
            buffer[1] = 0x13;
            buffer[2] = 0x04;
        }
    }
    socket->write((const char*)buffer, 5);
}

void car::control_car()
{
    if(!flag)
        return;
    memset(buff, 0, 5);
    QByteArray buf = socket->readAll();
    for(int i = 0; i < 5; i++)
    {
        buff[i] = (unsigned char)buf[i];
    }
    if (buff[0] == 0xFF)
    {
        switch (buff[1])
        {
        case 0x03:
            dis = (unsigned int)buff[2];
            view = (unsigned int)buff[3];
            sdis = QString::number(dis, 10);
            sview = QString::number(view, 10);
            ui->leida_dis->setText(sdis);
            ui->leida_view->setText(sview);
            break;
        case 0x60:
            power = (unsigned int)buff[2];
            spower = QString::number(power, 10);
            ui->power->setText(spower);
            break;
        case 0x61:
            hum = (unsigned int)buff[2];
            shum = QString::number(hum, 10);
            ui->hum->setText(shum);
            break;
        case 0x62:
            radiate = (unsigned int)buff[2];
            sradiate = QString::number(radiate, 10);
            ui->radiate->setText(sradiate);
            break;
        case 0x63:
            tem = (unsigned int)buff[2];
            stem = QString::number(tem, 10);
            ui->tem->setText(stem);
            break;
        }
    }
}

void car::on_camera_clicked()
{
    if(ui->camera->isChecked())
    {
        ui->video->load(QUrl("http://192.168.3.102:8080/javascript_simple.html"));
        ui->video->pageAction(QWebPage::DownloadLinkToDisk);
        ui->video->pageAction(QWebPage::DownloadMediaToDisk);
        ui->video->pageAction(QWebPage::DownloadImageToDisk);
    }
    else
    {
         ui->video->load(QUrl("http://192.168.3.102:8080/static_simple.html"));
    }
}
