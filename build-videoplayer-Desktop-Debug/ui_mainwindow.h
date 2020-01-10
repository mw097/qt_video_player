/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionPlay;
    QAction *actionStop;
    QAction *actionBeginning;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar_up;
    QToolBar *toolBar_down;
    QToolBar *commentBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background: #333;"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionBeginning = new QAction(MainWindow);
        actionBeginning->setObjectName(QString::fromUtf8("actionBeginning"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar_up = new QToolBar(MainWindow);
        toolBar_up->setObjectName(QString::fromUtf8("toolBar_up"));
        toolBar_up->setStyleSheet(QString::fromUtf8("background: #fff;"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_up);
        toolBar_down = new QToolBar(MainWindow);
        toolBar_down->setObjectName(QString::fromUtf8("toolBar_down"));
        toolBar_down->setStyleSheet(QString::fromUtf8("background: #fff;"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar_down);
        commentBar = new QToolBar(MainWindow);
        commentBar->setObjectName(QString::fromUtf8("commentBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, commentBar);
        MainWindow->insertToolBarBreak(commentBar);

        toolBar_up->addAction(actionOpen);
        toolBar_down->addAction(actionPlay);
        toolBar_down->addSeparator();
        toolBar_down->addAction(actionStop);
        toolBar_down->addSeparator();
        toolBar_down->addAction(actionBeginning);
        toolBar_down->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open A File", nullptr));
#endif // QT_NO_TOOLTIP
        actionPlay->setText(QApplication::translate("MainWindow", "Play", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPlay->setToolTip(QApplication::translate("MainWindow", "Play A Video", nullptr));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stop A Video", nullptr));
#endif // QT_NO_TOOLTIP
        actionBeginning->setText(QApplication::translate("MainWindow", "Beginning", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBeginning->setToolTip(QApplication::translate("MainWindow", "Start Watching A Video From The Beginning", nullptr));
#endif // QT_NO_TOOLTIP
        toolBar_up->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_down->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        commentBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
