#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   // this->setStyleSheet("background-color: black;");
    ui->setupUi(this);
    zork = new ZorkUL();
    wordle = new Wordle();
    ui->dir_label->setText(toQString(GameOutputs::beginGame));
    ui->wordleEdit->setVisible(false);
    ui->WordleInputLabel->setVisible(false);
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
    for(int i=0; i< static_cast<int>(item.size()); i++){
        ui->ItemBox->addItem(toQString(item.at(i)->getShortDescription()));
    }
}

void MainWindow::createInventoryBox(){
    for(int i=0; i< static_cast<int>(zork->getPlayer()->itemsInCharacter.size()); i++)
        ui->InventoryBox->addItem(toQString(zork->getPlayer()->itemsInCharacter.at(i)->getShortDescription()));
}

QString MainWindow::toQString(string s){
    QString str = QString::fromUtf8(s.c_str());
    return str;
}

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
    wordleCheck();
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
    wordleCheck();
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
    wordleCheck();
}


void MainWindow::on_SouthButton_clicked()
{
    if(!zork->getCurrentRoom()->wordleCheck){
        dir = "south";
        zork->goRoom(dir);
        ui->dir_label->setText(toQString(zork->printRooms()));
        imageDes = toQString(zork->getCurrentRoom()->getImages().at(0).getImage());
        updateImage(imageDes);
        ui->ItemBox->clear();
        createItemBox();
        /*if(zork->getCurrentRoom()->wordleCheck){
            ui->wordleEdit->setVisible(true);
            ui->dir_label->setText(toQString(GameOutputs::wordleBegin));
        }else{
            ui->wordleEdit->setVisible(false);
        }*/
        wordleCheck();
    }else{
        ;
    }
}


void MainWindow::wordleCheck(){

    if(zork->getCurrentRoom()->wordleCheck && zork->getPlayer()->hasItem("Golden Key")){
        ui->wordleEdit->setVisible(true);
        ui->WordleInputLabel->setVisible(true);
        ui->dir_label->setText(toQString(GameOutputs::wordleBegin));
    }else{
        if(zork->getCurrentRoom()->wordleCheck){
            ui->dir_label->setText(toQString(GameOutputs::wordleHint));
        }
        ui->wordleEdit->setVisible(false);
        ui->WordleInputLabel->setVisible(false);

    }
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
    ui->ItemBox->clear();
    createItemBox();
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
    for(int i=0;i< static_cast<int>(zork->getPlayer()->itemsInCharacter.size());i++){
        if(zork->getPlayer()->itemsInCharacter.at(i)->getLongDescription() == curItem){
            zork->getPlayer()->removeItem(zork->getPlayer()->itemsInCharacter.at(i));
            ui->InventoryBox->removeItem(ui->InventoryBox->currentIndex());
        }
    }
    int counter = zork->getPlayer()->itemsInCharacter.size();
    ui->inventorycounter->display(counter);
}

void MainWindow::on_wordleEdit_returnPressed()
{
      wordleInput= ui->wordleEdit->text();
      ui->dir_label->setText(toQString(wordle->play(wordleInput.toStdString())));
      if(wordle->game_won){
          ui->dir_label->setText(toQString(GameOutputs::beatWordle));
          zork->getCurrentRoom()->wordleCheck = false;
          ui->wordleEdit->setVisible(false);
      }
}

