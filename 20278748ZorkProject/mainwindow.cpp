#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "ZorkUL.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    ui->dir_label->setText(toQString(zork->printRooms()));
    /*createRooms();*/
    createTeleportBox();
}

MainWindow::~MainWindow()
{
    delete zork;
    delete ui;
}

//creates combobox with teleport options
void MainWindow::createTeleportBox(){
    for(int i=65;i<=74;i++){
        char c = i;
        string s(1, c);
        //QString str = QString::fromUtf8(s.c_str());
        ui->TeleportBox->addItem("room " + toQString(s));
    }
    ui->TeleportBox->addItem("Random");
}

QString MainWindow::toQString(string s){
    QString str = QString::fromUtf8(s.c_str());
    return str;
}

void MainWindow::imageDestination(QString &pic){
    vector<Room*>rooms = zork->getRooms();
    string loc = "/home/tomek/Desktop/ZorkProject20278748/ProjectImages/";
    string end = ".jpg";
    int j=0;
    string letter;
    for(int i=97;i<=106;i++){
        char c = i;
        if(rooms[j] == zork->getCurrentRoom()){
            string s(1, c);
            string letter = s;
            break;
        }
        j++;
    }
     //QString picture = toQString(loc + letter + end);

     pic = toQString(letter);
}
//updates the image lable depending on location
void MainWindow::updateImage(QString dest){
    /*QPixmap pix(dest);
    int w = ui->imgLabel->width();
    int h = ui->imgLabel->height();
    ui->imgLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));*/
    ui->dir_label->setText(dest);
}

void MainWindow::on_NorthButton_clicked()
{
    dir = "north";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
    //imageDestination(imageDes);
    //updateImage("/home/tomek/Pictures/minecraftWorld.jpg");
    //updateImage(imageDes);
}


void MainWindow::on_WestButton_clicked()
{

    dir = "west";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
}


void MainWindow::on_EastButton_clicked()
{
    dir = "east";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
}


void MainWindow::on_SouthButton_clicked()
{
    dir = "south";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
}


void MainWindow::on_MapButton_clicked()
{

}

//checks indexes from combo box to teleport player to random room or room of choice;
void MainWindow::on_TeleportButton_clicked()
{
    vector<Room*> rooms = zork->getRooms();
    int pos = ui->TeleportBox->currentIndex();
    if(pos == ui->TeleportBox->count()-1){
        zork->teleport();
        ui->dir_label->setText(toQString(zork->printRooms()));
    }else{
        //currentRoom = rooms[pos];
        zork->setCurrentRoom(rooms[pos]);
        ui->dir_label->setText(toQString(zork->printRooms()));
    }


}

