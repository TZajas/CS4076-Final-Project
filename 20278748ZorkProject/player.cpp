#include "player.h"

Player::Player(string name) : Character(name){

}

Player::~Player() {

}

void Player::addItems(Item *item) {
    itemsInCharacter.push_back(item);
}

string Player::listItems()
{
    string ret = this->description;
    ret += "\n Item list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i)->getLongDescription() + "\n";
    return ret;
}

void Player::emptyInventory(){
    itemsInCharacter.clear();
}

void Player::removeItem(Item *item){
    for(int i=0; i<itemsInCharacter.size(); i++){
        if(itemsInCharacter.at(i) == item){
              itemsInCharacter.erase(itemsInCharacter.begin() + i);
        }
    }
}

void Player::setHealth(int setHealth){
    this->health = health+setHealth;
    if(this->health>100){
        this->health = 100;
    }

    if(this->health<=0){
        //character death;
    }
}

int Player::getHealth(){
    return this->health;
}
