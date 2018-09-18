#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("NotePad");

    connect(ui->action_N, SIGNAL(triggered()), this, SLOT(N_action()));
    connect(ui->action_O, SIGNAL(triggered()), this, SLOT(O_action()));
    connect(ui->action_X, SIGNAL(triggered()), this, SLOT(X_action()));
    connect(ui->action_U, SIGNAL(triggered()), ui->textEdit,
            SLOT(undo()));
    connect(ui->action_R, SIGNAL(triggered()), ui->textEdit,
            SLOT(redo()));
    connect(ui->action_A_2, SIGNAL(triggered()), ui->textEdit,
            SLOT(selectAll()));

    connect(ui->action_T, SIGNAL(triggered()), ui->textEdit,
            SLOT(cut()));
    connect(ui->action_C, SIGNAL(triggered()), ui->textEdit,
            SLOT(copy()));
    connect(ui->action_P, SIGNAL(triggered()), ui->textEdit,
            SLOT(paste()));
    connect(ui->action_font, SIGNAL(triggered()), this, SLOT(font_action()));
    connect(ui->action_color, SIGNAL(triggered()), this, SLOT(color_action()));
    connect(ui->action_time, SIGNAL(triggered()), this, SLOT(time_action()));
    connect(ui->action_QT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->action_web, SIGNAL(triggered()), this, SLOT(web_action()));
    connect(ui->action_soft, SIGNAL(triggered()), this, SLOT(soft_action()));

}

void MainWindow::N_action()
{
    if ( !(filename.isEmpty()))
    {
        file->close();
    }

    filename = QFileDialog::getSaveFileName(this, tr("New File"),
                                            QDir::currentPath(), tr("*.*"));
    if (filename.isEmpty())
    {
        return;
    }
    file = new QFile();
    file->setFileName(filename);
    bool ok = file->open(QIODevice::ReadWrite);
    if (ok)
    {
       this->setWindowTitle(filename);
       ui->textEdit->clear();
       connect(ui->action_S, SIGNAL(triggered()), this, SLOT(S_action()),
               Qt::UniqueConnection);
       connect(ui->action_A, SIGNAL(triggered()), this, SLOT(A_action()),
               Qt::UniqueConnection);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Create Error");
        return;
    }

}

void MainWindow::O_action()
{
    if ( !(filename.isEmpty()))
    {
        file->close();
    }

    filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                            QDir::currentPath(), tr("*.*"));
    if (filename.isEmpty())
        return;
    file = new QFile();
    file->setFileName(filename);
    bool ok = file->open(QIODevice::ReadWrite);
    if (ok)
    {
        this->setWindowTitle(filename);
        QTextStream in(file);
        ui->textEdit->setText(in.readAll());
        connect(ui->action_S, SIGNAL(triggered()), this, SLOT(S_action()),
                Qt::UniqueConnection);
        connect(ui->action_A, SIGNAL(triggered()), this, SLOT(A_action()),
                Qt::UniqueConnection);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Open Error");
        return;
    }

}

void MainWindow::S_action()
{
    if (filename.isEmpty())
    {
        return;
    }
    file->resize(0);
    QTextStream out(file);
    out<<ui->textEdit->toPlainText(); //取出纯文本
}

void MainWindow::A_action()
{
    if (filename.isEmpty())
    {
        return;
    }
    else
    {
        file->close();
    }

    filename = QFileDialog::getSaveFileName(this, tr("Resave File"),
                                            QDir::currentPath(), tr("*.*"));
    if (filename.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name can't be empty");
        return;
    }
    file->setFileName(filename);
    bool ok = file->open(QIODevice::ReadWrite);
    if (ok)
    {
        QTextStream out(file);
        out<<ui->textEdit->toPlainText(); //取出纯文本
    }
    else
    {
        QMessageBox::warning(this, "Error", "Save Error");
        return;
    }

}

void MainWindow::X_action()
{
    if (filename.isEmpty())
    {
        ui->textEdit->clear();
        this->close();
    }
    else
    {
        ui->textEdit->clear();
        file->close();
        this->close();
    }

}

void MainWindow::font_action()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);//选择字体
    if (ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        return;
    }
}

void MainWindow::color_action()
{
    QColor color = QColorDialog::getColor(Qt::blue, this);//选择颜色
    if (color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        return;
    }
}

void MainWindow::time_action()
{
    QDateTime cur  = QDateTime::currentDateTime();
    QString   time = cur.toString("yyyy-M-dd hh:mm:ss");
    ui->textEdit->append(time);
}

void MainWindow::web_action()
{
    QDesktopServices::openUrl(QUrl("https://www.qt.io/"));
}

void MainWindow::soft_action()
{
    about* softabout = new about;
    softabout->show();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (ui->textEdit->document()->isModified())
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Save:
              // Save was clicked
            this->S_action();
              break;
          case QMessageBox::Discard:
              // Don't Save was clicked
            event->accept();
              break;
          case QMessageBox::Cancel:
              // Cancel was clicked
            event->ignore();
              break;
          default:
              // should never be reached
              break;
        }
    }
    else
    {
        event->accept();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
