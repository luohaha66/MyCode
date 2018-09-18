#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    movie = new QMovie(":/imag/img/timg.gif");
    ui->movielabel->setMovie(movie);
    movie->start();
    connect(ui->start, SIGNAL(clicked()), this, SLOT(startmovie()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(stopmovie()));
}

void about::startmovie()
{
    movie->start();
}

void about::stopmovie()
{
    movie->stop();
}


about::~about()
{
    delete ui;
}
