#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
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
    void go();
    void createRooms();
    void teleportRand();
    void createTeleportBox();
    QString printRooms();
    void updateImage(QString dest);

private slots:
    void on_NorthButton_clicked();

    void on_WestButton_clicked();

    void on_EastButton_clicked();

    void on_SouthButton_clicked();

    void on_MapButton_clicked();

    void on_TeleportButton_clicked();

private:

    Ui::MainWindow *ui;
    vector<Room*> rooms;
    Room *currentRoom;
    string dir;
};
#endif // MAINWINDOW_H
