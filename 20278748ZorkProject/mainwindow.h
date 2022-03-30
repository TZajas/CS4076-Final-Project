#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Room.h"
#include "item.h"
#include "ZorkUL.h"
#include "character.h"
#include <iostream>
#include <string>
#include "wordle.h"
using namespace std;

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateImage(QString dest);
    void imageDestination(QString &pic);

private slots:
    void on_NorthButton_clicked();

    void on_WestButton_clicked();

    void on_EastButton_clicked();

    void on_SouthButton_clicked();

    void on_TeleportButton_clicked();

    void on_TakeButton_clicked();

    void on_MapButton_released();

    void on_MapButton_pressed();

    void on_DropButton_clicked();

    void on_wordleEdit_returnPressed();

private:
    QString imageDes;
    QString toQString(string s);
    void createInventoryBox();
    void createTeleportBox();
    void createItemBox();
    void resetItemBox();
    Ui::MainWindow *ui;
    string dir;
    ZorkUL *zork;
    Wordle *wordle;
    QString wordleInput;

};
#endif // MAINWINDOW_H
