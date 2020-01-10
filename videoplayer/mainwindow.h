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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionBeginning_triggered();

    void on_actionAdd_Bookmark_triggered();

private:
    Ui::MainWindow *ui;
    /*Handles decompresing and decoding a file*/
    QMediaPlayer* player;
    /*Medium through which the video will be displayed upon*/
    QVideoWidget* canvas;
    QSlider* time_slider;
    QSlider* volume_slider;
    QLabel* space1;
    QLabel* space2;
    QLabel* space3;
    QComboBox* bookmarks;
    QInputDialog* bookmarkDialog;

};
#endif // MAINWINDOW_H
