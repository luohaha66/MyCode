#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDateTime>


namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QString myfile, QWidget *parent = 0);
    ~info();

private:
    Ui::info *ui;
    QString  nfilepath;
};

#endif // INFO_H
