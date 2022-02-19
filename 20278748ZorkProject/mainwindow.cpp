#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "ZorkUL.h"
#include "Room.h"
#include "item.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //create rooom

{
    ui->setupUi(this);
    createRooms();
    //QPixmap pix("/home/tomek/Pictures/minecraftWorld.jpg");
    //int w = ui->label_pic->width();
    //int h = ui->label_pic->height();
    //ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*ZorkUL::ZorkUL() {
    createRooms();
}*/

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



void MainWindow::on_NorthButton_clicked()
{
    dir = "north";
    go();
    string des = currentRoom->longDescription();
    QString str = QString::fromUtf8(des.c_str());
    ui->dir_label->setText(str);
}


void MainWindow::on_WestButton_clicked()
{

    dir = "west";
    go();
    string des = currentRoom->longDescription();
    QString str = QString::fromUtf8(des.c_str());
    ui->dir_label->setText(str);
}


void MainWindow::on_EastButton_clicked()
{
    dir = "east";
    go();
    string des = currentRoom->longDescription();
    QString str = QString::fromUtf8(des.c_str());
    ui->dir_label->setText(str);
}


void MainWindow::on_SouthButton_clicked()
{
    dir = "south";
    go();
    string des = currentRoom->longDescription();
    QString str = QString::fromUtf8(des.c_str());
    ui->dir_label->setText(str);
}

