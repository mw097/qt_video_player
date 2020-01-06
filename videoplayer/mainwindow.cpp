#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setting QMediaPlayer and QVideoWidget
    player = new QMediaPlayer(this);
    canvas = new QVideoWidget(this);
    player->setVideoOutput(canvas);
    this->setCentralWidget(canvas);

    // Setting Actions Icons
    ui->actionOpen->setIcon(QIcon(":/img/icons/open.png"));
    ui->actionPlay->setIcon(QIcon(":/img/icons/play.png"));
    ui->actionStop->setIcon(QIcon(":/img/icons/stop.png"));
    ui->actionBeginning->setIcon(QIcon(":/img/icons/beginning.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file","","Video Files (*.avi *.mpg *.mp4)");
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(filename));

}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_actionStop_triggered()
{
    player->pause();
}

void MainWindow::on_actionBeginning_triggered()
{
    player->stop();
}
