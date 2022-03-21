#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QLayout>
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
   // this->setStyleSheet("background-color: black;");
    ui->setupUi(this);
    zork = new ZorkUL();
    ui->dir_label->setText(toQString(zork->printRooms()));
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
    createTeleportBox();
    createItemBox();
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

void MainWindow::createItemBox(){
    vector<Item*> item = zork->getCurrentRoom()->getItems();
    for(int i=0; i<item.size(); i++){
        ui->ItemBox->addItem(toQString(item.at(i)->getShortDescription()));
    }
}

void MainWindow::createInventoryBox(){
    for(int i=0; i<zork->getPlayer()->itemsInCharacter.size(); i++)
        ui->InventoryBox->addItem(toQString(zork->getPlayer()->itemsInCharacter.at(i)->getShortDescription()));
}

QString MainWindow::toQString(string s){
    QString str = QString::fromUtf8(s.c_str());
    return str;
}

/*void MainWindow::imageDestination(QString &pic){
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
}*/

//updates the image lable depending on location
void MainWindow::updateImage(QString dest){
    QPixmap pix(dest);
    int w = ui->imgLabel->width();
    int h = ui->imgLabel->height();
    ui->imgLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ui->dir_label->setText(dest);
}

void MainWindow::on_NorthButton_clicked()
{
    dir = "north";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
    ui->ItemBox->clear();
    createItemBox();
}


void MainWindow::on_WestButton_clicked()
{

    dir = "west";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
    ui->ItemBox->clear();
    createItemBox();
}


void MainWindow::on_EastButton_clicked()
{
    dir = "east";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
    ui->ItemBox->clear();
    createItemBox();
}


void MainWindow::on_SouthButton_clicked()
{
    dir = "south";
    zork->goRoom(dir);
    ui->dir_label->setText(toQString(zork->printRooms()));
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
    ui->ItemBox->clear();
    createItemBox();

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
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);



}


void MainWindow::on_TakeButton_clicked()
{
    if(zork->getCurrentRoom()->getItems().size()!=0){
        vector<Item*> item = zork->getCurrentRoom()->getItems();
        int curPos = ui->ItemBox->currentIndex();
        QString str = ui->ItemBox->currentText();
        std::string curItem = str.toStdString();
        //Item *x = &item.at(curPos);
        zork->getPlayer()->addItems(zork->getCurrentRoom()->getItems().at(curPos));
        ui->InventoryBox->addItem(toQString(zork->getPlayer()->itemsInCharacter.back()->getLongDescription()));
        zork->getCurrentRoom()->removeItemFromRoom(curPos);
        ui->ItemBox->removeItem(curPos);
        int counter = zork->getPlayer()->itemsInCharacter.size();
        ui->inventorycounter->display(counter);
        ui->dir_label->setText(toQString(zork->printRooms()));
    }else{
        ;
    }
}




void MainWindow::on_MapButton_released()
{
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
    updateImage(imageDes);
}


void MainWindow::on_MapButton_pressed()
{
    updateImage("/home/tomek/Pictures/minecraftWorld.jpg");
}




void MainWindow::on_DropButton_clicked()
{
    QString str = ui->InventoryBox->currentText();
    std::string curItem = str.toStdString();
    for(int i=0;i<zork->getPlayer()->itemsInCharacter.size();i++){
        if(zork->getPlayer()->itemsInCharacter.at(i)->getShortDescription() == curItem){
            zork->getPlayer()->removeItem(zork->getPlayer()->itemsInCharacter.at(i));
            ui->InventoryBox->removeItem(ui->InventoryBox->currentIndex());
        }
    }
    int counter = zork->getPlayer()->itemsInCharacter.size();
    ui->inventorycounter->display(counter);
}

