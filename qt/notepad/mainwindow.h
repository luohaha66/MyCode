#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDir>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QSplashScreen>
#include <QCloseEvent>

#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event);

private slots:
    void N_action();
    void O_action();
    void S_action();
    void A_action();
    void X_action();
    void font_action();
    void color_action();
    void time_action();
    void web_action();
    void soft_action();

private:
    Ui::MainWindow *ui;
    QFile*          file;
    QString         filename;
};

#endif // MAINWINDOW_H
