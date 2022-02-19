/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *NorthButton;
    QPushButton *EastButton;
    QPushButton *WestButton;
    QPushButton *SouthButton;
    QLabel *dir_label;
    QPushButton *TeleportButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NorthButton = new QPushButton(centralwidget);
        NorthButton->setObjectName(QString::fromUtf8("NorthButton"));
        NorthButton->setGeometry(QRect(530, 80, 89, 25));
        EastButton = new QPushButton(centralwidget);
        EastButton->setObjectName(QString::fromUtf8("EastButton"));
        EastButton->setGeometry(QRect(650, 150, 89, 25));
        WestButton = new QPushButton(centralwidget);
        WestButton->setObjectName(QString::fromUtf8("WestButton"));
        WestButton->setGeometry(QRect(430, 140, 89, 25));
        SouthButton = new QPushButton(centralwidget);
        SouthButton->setObjectName(QString::fromUtf8("SouthButton"));
        SouthButton->setGeometry(QRect(530, 210, 89, 25));
        dir_label = new QLabel(centralwidget);
        dir_label->setObjectName(QString::fromUtf8("dir_label"));
        dir_label->setGeometry(QRect(30, 90, 341, 161));
        TeleportButton = new QPushButton(centralwidget);
        TeleportButton->setObjectName(QString::fromUtf8("TeleportButton"));
        TeleportButton->setGeometry(QRect(660, 430, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        NorthButton->setText(QCoreApplication::translate("MainWindow", "North", nullptr));
        EastButton->setText(QCoreApplication::translate("MainWindow", "East", nullptr));
        WestButton->setText(QCoreApplication::translate("MainWindow", "West", nullptr));
        SouthButton->setText(QCoreApplication::translate("MainWindow", "South", nullptr));
        dir_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        TeleportButton->setText(QCoreApplication::translate("MainWindow", "Teleport", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
