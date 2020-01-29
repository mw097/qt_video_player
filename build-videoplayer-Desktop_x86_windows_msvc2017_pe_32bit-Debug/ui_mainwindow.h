/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QAction *actionAdd_Bookmark;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar_up;
    QToolBar *toolBar_down;
    QToolBar *commentBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QStringLiteral("background: #333;"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionBeginning = new QAction(MainWindow);
        actionBeginning->setObjectName(QStringLiteral("actionBeginning"));
        actionAdd_Bookmark = new QAction(MainWindow);
        actionAdd_Bookmark->setObjectName(QStringLiteral("actionAdd_Bookmark"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusbar);
        toolBar_up = new QToolBar(MainWindow);
        toolBar_up->setObjectName(QStringLiteral("toolBar_up"));
        toolBar_up->setStyleSheet(QStringLiteral("background: #fff;"));
        toolBar_up->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_up);
        toolBar_down = new QToolBar(MainWindow);
        toolBar_down->setObjectName(QStringLiteral("toolBar_down"));
        toolBar_down->setStyleSheet(QStringLiteral("background: #fff;"));
        toolBar_down->setMovable(false);
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar_down);
        commentBar = new QToolBar(MainWindow);
        commentBar->setObjectName(QStringLiteral("commentBar"));
        commentBar->setMovable(false);
        MainWindow->addToolBar(Qt::BottomToolBarArea, commentBar);
        MainWindow->insertToolBarBreak(commentBar);

        toolBar_up->addAction(actionOpen);
        toolBar_up->addSeparator();
        toolBar_up->addAction(actionAdd_Bookmark);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open A File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPlay->setToolTip(QApplication::translate("MainWindow", "Play A Video", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stop A Video", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionBeginning->setText(QApplication::translate("MainWindow", "Beginning", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBeginning->setToolTip(QApplication::translate("MainWindow", "Start Watching A Video From The Beginning", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAdd_Bookmark->setText(QApplication::translate("MainWindow", "Add Bookmark", Q_NULLPTR));
        toolBar_up->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_down->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
        commentBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
