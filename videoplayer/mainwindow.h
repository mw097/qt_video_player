#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QSlider>
#include <QLabel>
#include <QComboBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QTime>

#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer* player;

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionBeginning_triggered();

    void on_actionAdd_Bookmark_triggered();

    void on_comment_btn_triggered();

<<<<<<< HEAD
    void on_bookmarkIndex_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
=======
    void LookForComments();
    void playerOnPositionChanged(qint64 position);


signals:

private:
    Ui::MainWindow *ui;
    /*Handles decompresing and decoding a file*/

>>>>>>> comments
    /*Medium through which the video will be displayed upon*/
    QVideoWidget* canvas;
    QSlider* time_slider;
    QSlider* volume_slider;
    QLabel* browser;
    QLabel* space1;
    QLabel* space2;
    QLabel* space3;
    QComboBox* bookmarks;
    QString bookmarkText;
    QLineEdit* comment;
    //QTextBrowser* comment_time;
    QPushButton* comment_btn;
    DBManager *database;
    bool ok;
<<<<<<< HEAD
    QString base;
=======
    QString filename;
    QThread* thread;
    QList<qint64> commentTable;
>>>>>>> comments
};
#endif // MAINWINDOW_H
