#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QDesktopServices>
#include <QTimer>
#include <QDesktopWidget>
#include <QPixmap>
#include <QClipboard>
#include <QFileDialog>
#include <QStandardPaths>
#include <QCursor>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
   void contextMenuEvent(QContextMenuEvent* event);

private slots:
    void on_pushButton_clicked();
    void new_screencut();
    void save_pic();
    void copy_pic();
    void del_pic();
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTimer*    time;
    QPixmap    pixcut;
    QString    filename;
    QMenu*     menu;
    QAction*   ac1;
    QAction*   ac2;
    QAction*   ac3;
};

#endif // WIDGET_H
