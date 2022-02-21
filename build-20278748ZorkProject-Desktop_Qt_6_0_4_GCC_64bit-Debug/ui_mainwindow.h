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
#include <QtWidgets/QComboBox>
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
    QPushButton *MapButton;
    QLabel *imgLabel;
    QComboBox *TeleportBox;
    QPushButton *TeleportButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1235, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NorthButton = new QPushButton(centralwidget);
        NorthButton->setObjectName(QString::fromUtf8("NorthButton"));
        NorthButton->setGeometry(QRect(880, 30, 131, 61));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setKerning(true);
        NorthButton->setFont(font);
        EastButton = new QPushButton(centralwidget);
        EastButton->setObjectName(QString::fromUtf8("EastButton"));
        EastButton->setGeometry(QRect(1010, 140, 131, 61));
        QFont font1;
        font1.setPointSize(15);
        EastButton->setFont(font1);
        WestButton = new QPushButton(centralwidget);
        WestButton->setObjectName(QString::fromUtf8("WestButton"));
        WestButton->setGeometry(QRect(750, 140, 131, 61));
        WestButton->setFont(font1);
        SouthButton = new QPushButton(centralwidget);
        SouthButton->setObjectName(QString::fromUtf8("SouthButton"));
        SouthButton->setGeometry(QRect(880, 250, 131, 61));
        SouthButton->setFont(font1);
        dir_label = new QLabel(centralwidget);
        dir_label->setObjectName(QString::fromUtf8("dir_label"));
        dir_label->setGeometry(QRect(820, 490, 341, 161));
        MapButton = new QPushButton(centralwidget);
        MapButton->setObjectName(QString::fromUtf8("MapButton"));
        MapButton->setGeometry(QRect(1010, 400, 131, 61));
        QFont font2;
        MapButton->setFont(font2);
        imgLabel = new QLabel(centralwidget);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(40, 10, 651, 361));
        imgLabel->setFrameShape(QFrame::Panel);
        imgLabel->setFrameShadow(QFrame::Raised);
        imgLabel->setLineWidth(6);
        TeleportBox = new QComboBox(centralwidget);
        TeleportBox->setObjectName(QString::fromUtf8("TeleportBox"));
        TeleportBox->setGeometry(QRect(770, 350, 86, 25));
        TeleportButton = new QPushButton(centralwidget);
        TeleportButton->setObjectName(QString::fromUtf8("TeleportButton"));
        TeleportButton->setGeometry(QRect(750, 400, 131, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Samyak Malayalam"));
        TeleportButton->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1235, 22));
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
        dir_label->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        MapButton->setText(QCoreApplication::translate("MainWindow", "Map", nullptr));
        imgLabel->setText(QString());
        TeleportButton->setText(QCoreApplication::translate("MainWindow", "Teleport", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
