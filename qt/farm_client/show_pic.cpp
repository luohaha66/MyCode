#include "show_pic.h"

show_pic::show_pic(QString ip1, int port1, QWidget *parent)
    : nip(ip1),  nport(port1), QWidget(parent)
{
    this->setWindowTitle("Farm Control"); //设置界面标题
    this->setWindowIcon(QIcon(":/image/watch.png")); //设置界面图标
    this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");//设置控件为圆角

    this->setAutoFillBackground(true);
    QPalette uipa;
    QPixmap pix(":/image/6.png");
    uipa.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(uipa); //设置窗体背景图片

    set_light = new QPushButton(this);
    set_temp  = new QPushButton(this);
    c_light   = new QLabel(this);
    c_temp    = new QLabel(this);
    temp_z    = new QSpinBox(this);
    light_z   = new QSpinBox(this);

    fan     = new QRadioButton(this);
    beep    = new QRadioButton(this);
    led     = new QRadioButton(this);
    led1    = new QRadioButton(this);
    led_7   = new QRadioButton(this);
    play    = new QRadioButton(this);
    z_temp  = new QRadioButton(this);
    z_light = new QRadioButton(this);
    mgroup  = new QButtonGroup(this);
    re_pl   = new QPushButton(this);
    re_tur  = new QPushButton(this);
    view    = new QWebView(this);

    acc     = new QLabel(this);
    pic1    = new QLabel(this);
    pic2    = new QLabel(this);
    status  = new QLabel(this);
    light   = new QLabel(this);
    temp    = new QLabel(this);
    adc     = new QLabel(this);
    d_id    = new QLabel(this);

    mgroup->setExclusive(false);
    mgroup->addButton(play);
    mgroup->addButton(led);
    mgroup->addButton(led1);
    mgroup->addButton(led_7);
    mgroup->addButton(fan);
    mgroup->addButton(beep);
    mgroup->addButton(z_temp);
    mgroup->addButton(z_light);

    QString idstyle =
                "QLabel{background-color:#54547d;color:#00ffff;border:0;}";
    QFont idft("Century Schoolbook L", 20, 87);
    d_id->setFixedSize(250, 55);
    d_id->setStyleSheet(idstyle);
    d_id->setFont(idft); //设置字体
    d_id->setText(" Device Id: ");

    QString listyle =
                "QLabel{background-color:#553855;color:#00ffff;border:0;}";
    QFont styleft("Century Schoolbook L", 16, 87);
    light->setStyleSheet(listyle);
    light->setFixedSize(315, 35);
    light->setFont(styleft); //设置字体
    light->setText(" Real Light: ");

    QString tempstyle =
                "QLabel{background-color:#553855;color:#ffaa00;border:0;}";
    temp->setStyleSheet(tempstyle);
    temp->setFixedSize(315,35);
    temp->setFont(styleft); //设置字体
    temp->setText(" Real T&H: ");

    QString adcstyle =
                "QLabel{background-color:#553855;color:#00aaff;border:0;}";
    adc->setStyleSheet(adcstyle);
    adc->setFixedSize(315,35);
    adc->setFont(styleft); //设置字体
    adc->setText(" Real Adc: ");

    QString accstyle =
                "QLabel{background-color:#553855;color:#aa55ff;border:0;}";
    acc->setStyleSheet(accstyle);
    acc->setFixedSize(315,35);
    acc->setFont(styleft); //设置字体
    acc->setText(" Real Acc: ");

    QString spinstyle =
        "QSpinBox{color:#700000;}"
        "QSpinBox::up-button {subcontrol-origin:border;subcontrol-position:right;image: url(:/image/right.png);width: 18px;height: 25px;}"
        "QSpinBox::down-button {subcontrol-origin:border; subcontrol-position:left;image: url(:/image/left.png);width:18px;height: 25px;}"
        "QSpinBox::up-button:pressed {subcontrol-origin:border; subcontrol-position:right;image: url(:/image/right1.png);width:18px;height: 25px;}"
        "QSpinBox::down-button:pressed {subcontrol-origin:border; subcontrol-position:left;image: url(:/image/left1.png);width:18px;height: 25px;}";
    QFont spinft("Century Schoolbook L", 14, 87);
    light_z->setFont(spinft);
    light_z->setStyleSheet(spinstyle);
    light_z->setRange(0, 4500);
    light_z->setValue(1000);
    light_z->setSingleStep(50);
    light_z->setSuffix("cd");
    light_z->setFixedSize(120,35);

    QString dspinstyle =
            "QSpinBox{color:#00496b;}";
    temp_z->setStyleSheet(dspinstyle);
    temp_z->setFont(spinft);
    temp_z->setRange(-10, 50);
    temp_z->setValue(20);
    temp_z->setSingleStep(1);
    temp_z->setSuffix("°C");
    temp_z->setFixedSize(120,35);


    QString stastyle =
                "QLabel{color:#ff7fbf;border:0;}";
    QFont stft("Century Schoolbook L", 16, 87);
    status->setFixedSize(225,35);
    status->setStyleSheet(stastyle);
    status->setFont(stft);

    c_light->setFixedSize(230,35);
    c_light->setStyleSheet(stastyle);
    c_light->setFont(stft);

    c_temp->setFixedSize(200,35);
    c_temp->setStyleSheet(stastyle);
    c_temp->setFont(stft);

    pic1->setScaledContents(true);
    pic1->setStyleSheet("border:0");
    pic1->setFixedSize(200,500);
    QPixmap pic1map(":/image/8.png");
    pic1->setPixmap(pic1map);

    view->setFixedSize(660, 500);
    view->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    view->settings()->setAttribute(QWebSettings::JavaEnabled, true);
    view->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    view->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    view->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    view->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    view->settings()->setAttribute(QWebSettings::SpatialNavigationEnabled, true);
    view->settings()->setAttribute(QWebSettings::LinksIncludedInFocusChain, true);
    view->settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    view->settings()->setAttribute(QWebSettings::AutoLoadImages, true);
    view->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    view->settings()->enablePersistentStorage("F:/qt5.5_work/cache");
    view->settings()->setIconDatabasePath("F:/qt5.5_work/cache");
    view->settings()->setLocalStoragePath("F:/qt5.5_work/cache");
    view->settings()->setOfflineStoragePath("F:/qt5.5_work/cache");
    view->settings()->setOfflineWebApplicationCachePath("F:/qt5.5_work/cache");

    pic2->setScaledContents(true);
    pic2->setStyleSheet("border:0");
    pic2->setFixedSize(200,500);
    QPixmap pic2map(":/image/9.png");
    pic2->setPixmap(pic2map);

    QString fanstyle =
            "QRadioButton{spacing: 10px;border:0;background-color:#ffffff;color:#00ffff;}"
            "QRadioButton::indicator {width: 65px;height: 35px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c1.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c5.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on.png);}";
    fan->setStyleSheet(fanstyle);
    fan->setFixedSize(155,36);
    QFont styft("CAbyssinica SIL", 14, 75);
    QFont sss("Century Schoolbook L", 14, 75);
    fan->setFont(styft);
    fan->setText("Fan");

    z_temp->setStyleSheet(fanstyle);
    z_temp->setFixedSize(165,35);
    z_temp->setFont(styft);
    z_temp->setText("智能温控");

    QString ledstyle =
            "QRadioButton{spacing: 10px;border:0;background-color:#ffffff;color:#aa00ff;}"
            "QRadioButton::indicator {width: 65px;height: 35px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off1.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c2.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off1.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on1.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c6.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on1.png);}";
    led->setStyleSheet(ledstyle);
    led->setFixedSize(160,36);
    led->setFont(sss);
    led->setText("ALed");

    z_light->setStyleSheet(ledstyle);
    z_light->setFont(styft);
    z_light->setFixedSize(165,35);
    z_light->setText("智能光感");

    QString spestyle =
            "QRadioButton{spacing: 10px;border:0;background-color:#ffffff;color:#ff5500;}"
            "QRadioButton::indicator {width: 65px;height: 35px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off2.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c4.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off2.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on2.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c8.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on2.png);}";
    beep->setStyleSheet(spestyle);
    beep->setFixedSize(155,36);
    beep->setFont(sss);
    beep->setText("Beep");

    QString myledstyle =
            "QRadioButton{spacing: 10px;border:0;background-color:#ffffff;color:#00ff00;}"
            "QRadioButton::indicator {width: 65px;height: 40px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/off3.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/c3.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/off3.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/on3.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/c7.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/on3.png);}";
    led1->setStyleSheet(myledstyle);
    led1->setFixedSize(155,36);
    led1->setFont(sss);
    led1->setText("Led");

    led_7->setStyleSheet(myledstyle);
    led_7->setFixedSize(155,36);
    led_7->setFont(sss);
    led_7->setText("7Led");


    QString buttonstyle =
                      "QPushButton{color:#55ffff;border:0;}"
                      "QPushButton:!hover:!pressed{border-image:url(:/image/2.png)}"
                      "QPushButton:hover{border-image:url(:/image/1.png)}"
                      "QPushButton:pressed{border-image:url(:/image/2.png)}";
    QFont style_ft("Century Schoolbook L", 18, 87);
    re_pl->setStyleSheet(buttonstyle);
    re_pl->setFont(style_ft);
    re_pl->setText("  Replay  ");
    re_pl->setFixedSize(200,45); //调整大小

    re_tur->setStyleSheet(buttonstyle);
    re_tur->setFont(style_ft); //设置字体
    re_tur->setText("  Return  ");
    re_tur->setShortcut(QKeySequence(QLatin1String("Esc")));
    re_tur->setFixedSize(200,45); //调整大小

    QFont style_set("Century Schoolbook L", 16, 87);
    set_temp->setStyleSheet(buttonstyle);
    set_temp->setFont(style_set); //设置字体
    set_temp->setText("  Set  ");
    set_temp->setFixedSize(75,34); //调整大小

    set_light->setStyleSheet(buttonstyle);
    set_light->setFont(style_set); //设置字体
    set_light->setText("  Set  ");
    set_light->setFixedSize(75,34); //调整大小

    QString playstyle =
            "QRadioButton{border:0;}"
            "QRadioButton::indicator {width: 60px;height: 60px;}"
            "QRadioButton::indicator:unchecked {image: url(:/image/play.png);}"
            "QRadioButton::indicator:unchecked:hover {image: url(:/image/play1.png);}"
            "QRadioButton::indicator:unchecked:pressed {image: url(:/image/play.png);}"
            "QRadioButton::indicator:checked {image: url(:/image/stop.png);}"
            "QRadioButton::indicator:checked:hover {image: url(:/image/stop1.png);}"
            "QRadioButton::indicator:checked:pressed {image: url(:/image/stop.png);}";
    play->setStyleSheet(playstyle);
    play->setFont(styft);
    play->setShortcut(QKeySequence(QLatin1String("Space")));


    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addStretch();
    hbox->addWidget(d_id);
    hbox->addStretch();

    QHBoxLayout* hbox1 = new QHBoxLayout;
    hbox1->addWidget(light);
    hbox1->addWidget(temp);
    hbox1->addWidget(adc);
    hbox1->addWidget(acc);

    QHBoxLayout* hbox2 = new QHBoxLayout;
    hbox2->addStretch();
    hbox2->addWidget(fan);
    hbox2->addStretch();
    hbox2->addWidget(led);
    hbox2->addStretch();
    hbox2->addWidget(beep);
    hbox2->addStretch();

    QHBoxLayout* hbox3 = new QHBoxLayout;
    hbox3->addStretch();
    hbox3->addWidget(led1);
    hbox3->addStretch();
    hbox3->addWidget(led_7);
    hbox3->addStretch();

    QHBoxLayout* hbox4 = new QHBoxLayout;
    hbox4->addStretch();
    hbox4->addStretch();
    hbox4->addWidget(re_pl);
    hbox4->addWidget(play);
    hbox4->addWidget(re_tur);
    hbox4->addStretch();
    hbox4->addWidget(status);

    QHBoxLayout* hbox5 = new QHBoxLayout;
    hbox5->addWidget(pic1);
    hbox5->addWidget(view);
    hbox5->addWidget(pic2);

    QHBoxLayout* hbox6 = new QHBoxLayout;
    hbox6->addWidget(z_light);
    hbox6->addWidget(light_z);
    hbox6->addWidget(set_light);
    hbox6->addWidget(c_light);
    hbox6->addStretch();
    hbox6->addWidget(c_temp);
    hbox6->addWidget(temp_z);
    hbox6->addWidget(set_temp);
    hbox6->addWidget(z_temp);


    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addLayout(hbox);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox6);
    vbox->addLayout(hbox5);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);

    setLayout(vbox);
    layout()->setMargin(0);

    if (!led->isChecked())
    {
        led1->hide();
        led_7->hide();
    }

    socket = new QTcpSocket();
    socket->connectToHost(nip, nport);

    connect(socket, SIGNAL(connected()), this, SLOT(new_connect()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(messge_error()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(discon_from_host()));
    connect(re_tur, SIGNAL(clicked()),this,SLOT(returnapp()));
    connect(led,    SIGNAL(clicked()), this, SLOT(hide_ledcon()));
    connect(play,   SIGNAL(clicked()), this, SLOT(playcontrol()));
    connect(re_pl,  SIGNAL(clicked()), this, SLOT(replaycontrol()));
}

void show_pic::hide_ledcon()
{
    if (led->isChecked())
    {
        led1->show();
        led_7->show();
    }
    else
    {
        led1->hide();
        led_7->hide();
    }
}

void show_pic::playcontrol()
{
    if (play->isChecked())
    {
        view->load(QUrl("http://192.168.1.110:8080/javascript_simple.html"));
        view->pageAction(QWebPage::DownloadLinkToDisk);
        view->pageAction(QWebPage::DownloadMediaToDisk);
        view->pageAction(QWebPage::DownloadImageToDisk);
    }
   else
    {
        view->load(QUrl("http://192.168.1.110:8080/static_simple.html"));
    }
}

void show_pic::replaycontrol()
{
    view->pageAction(QWebPage::ReloadAndBypassCache);
    view->reload();
}

void show_pic::new_connect()
{
    /*QMessageBox::information(NULL, "Connect Status", "Connect is Successful",
                      QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes); //输出连接信息*/
    status->setText("Connect Successful");
    control* my_control = new control(this);
}


void show_pic::messge_error()
{
    status->setText("！Error or Timeout");
}

void show_pic::discon_from_host()
{
    status->setText("Connect is Interrupt");
}

void show_pic::returnapp()
{
    socket->write("quit");
    socket->close();
    this->close();
    Widget* w =new Widget;
    w->show();
}
