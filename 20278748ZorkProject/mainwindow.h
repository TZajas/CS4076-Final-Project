#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ZorkUL.h"
#include "gameoutputs.h"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QPixmap>
#include <QLayout>
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

    void on_AttackButton_clicked();

private:
    QString imageDes;
    QString toQString(string s);
    void createInventoryBox();
    void createTeleportBox();
    void createItemBox();
    void resetItemBox();
    void wordleCheck();
    void changeRoom(string dir);
    Ui::MainWindow *ui;
    string dir;
    ZorkUL *zork;
    Wordle *wordle;
    QString wordleInput;
    void changeImage(int i);

};
#endif // MAINWINDOW_H
