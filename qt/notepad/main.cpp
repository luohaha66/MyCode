#include "mainwindow.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QPixmap pixmap(":/imag/img/10.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    for(long i = 0; i < 1000000000; i++);
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
