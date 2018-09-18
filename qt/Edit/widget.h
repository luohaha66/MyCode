#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFile>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void edit_save();
    void edit_open();
    void edit_close();
    void edit_resave();

private:
    QPushButton* open;
    QPushButton* close;
    QPushButton* save;
    QPushButton* resave;
    QTextEdit*   edit;
    QString      filename;
    int          fd = 0;
};

#endif // WIDGET_H
