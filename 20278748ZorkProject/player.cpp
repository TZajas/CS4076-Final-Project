#include "player.h"

Player::Player(string name, int health) : Character(name, health)
{

}

Player::~Player()
{

}

void Player::addItems(Item *item)
{
    if(inventoryWeight()){
        itemsInCharacter.push_back(item);
    }
}

string Player::listItems()
{
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i)->getLongDescription() + "\n";
    return ret;
}

void Player::emptyInventory()
{
    itemsInCharacter.clear();
}

void Player::removeItem(Item *item)
{
    for(int i=0; i< static_cast<int>(itemsInCharacter.size()); i++){
        if(itemsInCharacter.at(i) == item){
              itemsInCharacter.erase(itemsInCharacter.begin() + i);
        }
    }
}

bool Player::hasItem(string item)
{
    for(int i=0; i< static_cast<int>(itemsInCharacter.size());i++){
        if(item == itemsInCharacter.at(i)->getShortDescription()){

           return true;
        }
    }
    return false;
}

bool Player::inventoryWeight()
{
    int weight=0;
    for(int i=0; i< static_cast<int>(itemsInCharacter.size());i++){
        weight = weight + itemsInCharacter.at(i)->getWeight();
    }
    if(weight>50){
        return false;
    }else{
        return true;
    }
}

void Player::setHealth(int setHealth)
{
    this->health = health+setHealth;
    if(this->health>100){
        this->health = 100;
    }

    if(this->health<=0){
        //character death;
    }
}
