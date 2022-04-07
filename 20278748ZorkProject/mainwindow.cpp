#include "mainwindow.h"
#include "ui_mainwindow.h"
//#define DEBUG
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    wordle = new Wordle();
    ui->dir_label->setText(toQString(GameOutputs::beginGame));
    ui->wordleEdit->setVisible(false);
    ui->WordleInputLabel->setVisible(false);
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
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
void MainWindow::createTeleportBox()
{
    for(int i=65;i<=74;i++){
        char c = i;
        string s(1, c);
        ui->TeleportBox->addItem("room " + toQString(s));
    }
    ui->TeleportBox->addItem("Random");
}

//creates combox that contains Items in current room
void MainWindow::createItemBox()
{
    vector<Item*> items = zork->getCurrentRoom()->getItems();
    for(int i=0; i< static_cast<int>(items.size()); i++){
        ui->ItemBox->addItem(toQString(items.at(i)->getShortDescription()));
    }
}

//creates inventory combobox that displays all items in players inventory
void MainWindow::createInventoryBox()
{
    for(int i=0; i< static_cast<int>(zork->getPlayer()->getInventory().size()); i++)
        ui->InventoryBox->addItem(toQString(zork->getPlayer()->getInventory().at(i)->getShortDescription()));
}

//method that converts c string to QString
QString MainWindow::toQString(string s)
{
    QString str = QString::fromUtf8(s.c_str());
    return str;
}

//updates the image lable depending on location
void MainWindow::updateImage(QString dest)
{
    QPixmap pix(dest);
    int w = ui->imgLabel->width();
    int h = ui->imgLabel->height();
    ui->imgLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

//method that changes room depending on direction given;
void MainWindow::changeRoom(string dir)
{
#ifdef DEBUG
        string output = zork->goRoom(dir);
        ui->dir_label->setText(toQString(zork->printRooms()));
#else
        string output = zork->goRoom(dir);
        ui->dir_label->setText(toQString(output));
        imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
        updateImage(imageDes);
        ui->ItemBox->clear();
        createItemBox();
        wordleCheck();
#endif
}

void MainWindow::on_NorthButton_clicked()
{
        dir = "north";
        changeRoom(dir);
}


void MainWindow::on_WestButton_clicked()
{

    if(!zork->getCurrentRoom()->wordleCheck){
        dir = "west";
        changeRoom(dir);
    }else{
        ;
    }
}


void MainWindow::on_EastButton_clicked()
{
    if(!zork->getCurrentRoom()->wordleCheck){
        dir = "east";
        changeRoom(dir);
    }else{
        ;
    }
}


void MainWindow::on_SouthButton_clicked()
{
    if(!zork->getCurrentRoom()->wordleCheck){
        dir = "south";
        changeRoom(dir);
    }else{
        ;
    }
}

//function that checks if the room contains a wordle puzzle, if it does it shows the opening text and the text label
//if it does not it hides the text label and displays a hint
void MainWindow::wordleCheck()
{
#ifdef DEBUG
        if(zork->getCurrentRoom()->wordleCheck){
            ui->wordleEdit->setVisible(true);
            ui->WordleInputLabel->setVisible(true);
            ui->dir_label->setText(toQString(GameOutputs::wordleBegin));
        }
#else
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
#endif
}

//checks indexes from combo box to teleport player to random room or room of choice;
void MainWindow::on_TeleportButton_clicked()
{
    vector<Room*> rooms = zork->getRooms();
    int pos = ui->TeleportBox->currentIndex();
    if(pos == ui->TeleportBox->count()-1){
        //if the last button is pressed in combo box teleport to random location
        zork->teleport();
        ui->dir_label->setText(toQString(zork->printRooms()));
    }else{
        zork->setCurrentRoom(rooms[pos]);
        ui->dir_label->setText(toQString(zork->printRooms()));
    }
    ui->ItemBox->clear();
    createItemBox();
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
    updateImage(imageDes);
}


//function that removes an item from the current room and its to the players inventory and inventory combobox
void MainWindow::on_TakeButton_clicked()
{
    if(zork->getCurrentRoom()->getItems().size()!=0){
        //vector<Item*> item = zork->getCurrentRoom()->getItems();
        int curPos = ui->ItemBox->currentIndex();
        QString str = ui->ItemBox->currentText();
        string curItem = str.toStdString();
        zork->getPlayer()->addItems(zork->getCurrentRoom()->getItems().at(curPos));
        ui->InventoryBox->addItem(toQString(zork->getPlayer()->getInventory().back()->getLongDescription()));
        zork->getCurrentRoom()->removeItemFromRoom(curPos);
        ui->ItemBox->removeItem(curPos);

        //increments inventory counter
        int counter = zork->getPlayer()->getInventory().size();
        ui->inventorycounter->display(counter);


        //changes images if key is taken
        ui->dir_label->setText(toQString(zork->printRooms()));
        if(zork->getPlayer()->hasItem("Golden Key") && zork->getCurrentRoom()->getImages().size()>1){
            changeImage(2);
        }
    }else{
        ;
    }
}


//displays map image while the map button is pressed
void MainWindow::on_MapButton_released()
{
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
    updateImage(imageDes);
}

void MainWindow::on_MapButton_pressed()
{
    updateImage("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/map.png");
}



void MainWindow::on_DropButton_clicked()
{
#ifdef DEBUG
    ui->InventoryBox->removeItem(ui->InventoryBox->currentIndex());
#else
    QString str = ui->InventoryBox->currentText();
    string curItem = str.toStdString();
    //searches through entire inventory and if it finds an item that matches it deletes it and removes it from combobox
    for(int i=0;i< static_cast<int>(zork->getPlayer()->getInventory().size());i++){
        if(zork->getPlayer()->getInventory().at(i)->getLongDescription() == curItem){
            zork->getPlayer()->removeItem(zork->getPlayer()->getInventory().at(i));
            ui->InventoryBox->removeItem(ui->InventoryBox->currentIndex());
        }
    }
    int counter = zork->getPlayer()->getInventory().size();
    ui->inventorycounter->display(counter);
#endif
}


//once text is input into the text box and enter is pressed
void MainWindow::on_wordleEdit_returnPressed()
{
      //players input
      wordleInput= ui->wordleEdit->text();
      ui->dir_label->setText(toQString(wordle->play(wordleInput.toStdString())));
      //if game is won it allows the player to progress
      if(wordle->game_won){
          ui->dir_label->setText(toQString(GameOutputs::beatWordle));
          zork->getCurrentRoom()->wordleCheck = false;
          ui->wordleEdit->setVisible(false);
          ui->WordleInputLabel->setVisible(false);
      }
}

//function that updates the image when enemy is killed
void MainWindow::changeImage(int i)
{

    zork->getCurrentRoom()->getImages().at(0)->setImage(zork->getCurrentRoom()->getImages().at(i)->getImage());
    imageDes = toQString(zork->getCurrentRoom()->getImages().at(0)->getImage());
    updateImage(imageDes);

}

//function that when pressed decrements the enemies health and when killed it deletes the enemy
void MainWindow::on_AttackButton_clicked()
{
    if(zork->getCurrentRoom()->getEnemies().size()>0){
        Zombie *zom = zork->getCurrentRoom()->getEnemies().at(0);
        zom->operator--();
        ui->dir_label->setText(toQString(zom->getHealth()));
        if(zom->deathStatus()){
            zork->getCurrentRoom()->addItem(zom->dropItem());
            zork->getCurrentRoom()->removeEnemy();
            changeImage(1);
            ui->ItemBox->clear();
            createItemBox();
            ui->dir_label->setText(toQString(zork->printRooms()));
        }
    }else{
        ;
    }
}

