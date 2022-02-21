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
    //create rooom

{
    ui->setupUi(this);
    createRooms();
    createTeleportBox();


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*ZorkUL::ZorkUL() {
    createRooms();
}*/

void MainWindow::createTeleportBox(){
    for(int i=65;i<=74;i++){
        char c = i;
        string s(1, c);
        QString str = QString::fromUtf8(s.c_str());
        ui->TeleportBox->addItem("room " + str);
    }
    ui->TeleportBox->addItem("Random");
}

QString MainWindow::printRooms(){
    string des;
    des = currentRoom->longDescription();
    QString str = QString::fromUtf8(des.c_str());
    return str;
}

void MainWindow::updateImage(QString dest){
    QPixmap pix(dest);
    int w = ui->imgLabel->width();
    int h = ui->imgLabel->height();
    ui->imgLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *newRoom;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    rooms.push_back(a);
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    rooms.push_back(b);
    c = new Room("c");
    rooms.push_back(c);
    d = new Room("d");
    rooms.push_back(d);
    e = new Room("e");
    rooms.push_back(e);
    f = new Room("f");
    rooms.push_back(f);
    g = new Room("g");
    rooms.push_back(g);
    h = new Room("h");
    rooms.push_back(h);
    i = new Room("i");
    rooms.push_back(i);
    newRoom = new Room("j");
    rooms.push_back(newRoom);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, newRoom, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    newRoom->setExits(d, NULL, NULL, NULL);
    currentRoom = a;
    ui->dir_label->setText(printRooms());

}

void MainWindow::go() {

    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(dir);
    if (nextRoom == NULL)
        currentRoom;
    else
    {
        currentRoom = nextRoom;
    }
}

void MainWindow::teleport(){
    unsigned int roomSize = rooms.size();
    unsigned int randRoom = rand() % roomSize;
    currentRoom = rooms[randRoom];
    ui->dir_label->setText(printRooms());
}



void MainWindow::on_NorthButton_clicked()
{
    dir = "north";
    go();
    ui->dir_label->setText(printRooms());
    updateImage("/home/tomek/Pictures/minecraftWorld.jpg");
}


void MainWindow::on_WestButton_clicked()
{

    dir = "west";
    go();
    ui->dir_label->setText(printRooms());
}


void MainWindow::on_EastButton_clicked()
{
    dir = "east";
    go();
    ui->dir_label->setText(printRooms());
}


void MainWindow::on_SouthButton_clicked()
{
    dir = "south";
    go();
    ui->dir_label->setText(printRooms());
}


/*void MainWindow::on_TeleportButton_clicked()
{
    teleport();
    ui->dir_label->setText(printRooms());
}*/


void MainWindow::on_MapButton_clicked()
{

}


void MainWindow::on_TeleportButton_clicked()
{
    int pos = ui->TeleportBox->currentIndex();
    if(pos == ui->TeleportBox->count()-1){
        teleport();
    }else{
        currentRoom = rooms[pos];
        ui->dir_label->setText(printRooms());
    }


}

