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

    //Space Between Buttons And Time Slider
    space1 = new QLabel(this);
    QString img1 = ":/img/icons/space.png";
    QImage image1(img1);
    space1->setPixmap(QPixmap::fromImage(image1));
    ui->toolBar_down->addWidget(space1); //Adding space between Sliders

    // Setting Time Slider
    time_slider = new QSlider(this);
    time_slider->setOrientation(Qt::Horizontal); //Making slider horizontal
    ui->toolBar_down->addWidget(time_slider); //Adding slider to toolbar

    // Connecting TimeSlider With the Player
    connect(player, &QMediaPlayer::durationChanged, time_slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, time_slider, &QSlider::setValue);
    connect(time_slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    //Space Between Sliders
    space2 = new QLabel(this);
    QString img2 = ":/img/icons/sound.png";
    QImage image2(img2);
    space2->setPixmap(QPixmap::fromImage(image2));
    ui->toolBar_down->addWidget(space2); //Adding space between Sliders

    // Setting Volume Slider
    volume_slider = new QSlider(this);
    volume_slider->setOrientation(Qt::Horizontal); //Making slider horizontal
    ui->toolBar_down->addWidget(volume_slider); //Adding slider to toolbar
    volume_slider->setValue(50); //Set default value

    // Connecting VolumeSlider With the Player
    connect(volume_slider,&QSlider::sliderMoved, player, &QMediaPlayer::setVolume);

    //Space Between Slider And End Of The Window
    space3 = new QLabel(this);
    QString img3 = ":/img/icons/space.png";
    QImage image3(img3);
    space3->setPixmap(QPixmap::fromImage(image3));
    ui->toolBar_down->addWidget(space3); //Adding space between Sliders

    //Status Bar For Comments and Actions
    browser = new QLabel(this);
    ui->statusbar->addWidget(browser); //Adding space between Sliders
    browser->setStyleSheet(" QLabel{ color: #fff; } ");

    //CommentBar
    comment = new QLineEdit(this);
    ui->commentBar->addWidget(comment);
    ui->commentBar->setStyleSheet("QToolBar {background:#fff; height: 40px;}");
    comment->setStyleSheet(" QLineEdit{ background:#fff; color: #000; border-radius:5px; border: 1px solid #999; height: 19px; width: 80px; margin 0 0 0 5px; } ");
    comment->setPlaceholderText("Type comment here...");

    comment_btn = new QPushButton;
    connect(comment_btn, SIGNAL(clicked()), this , SLOT(on_comment_btn_triggered()));
    ui->commentBar->addWidget(comment_btn);
    comment_btn->setText("+");
    comment_btn->setStyleSheet(" QLineEdit{ background:#fff; color: #000; } ");



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
    browser->setText("Open Button");
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    browser->setText("Play Button");
}

void MainWindow::on_actionStop_triggered()
{
    player->pause();
    browser->setText("Pause Button");
}

void MainWindow::on_actionBeginning_triggered()
{
    player->stop();
    browser->setText("Stop Button");
}

void MainWindow::on_comment_btn_triggered()
{
    browser->setText("Comment Button");
}
