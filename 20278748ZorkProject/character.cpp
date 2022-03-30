#include "character.h"

Character::Character(){
    this->description="Unknown character";
}

Character::Character(string description) {
    this->description = description;
    this->health = 100;
}

Character::~Character() {
   ;
}

void Character::setHealth(int setHealth){
    this->health=setHealth;
}

int Character::getHealth(){
    return this->health;
}


void Character::operator--() {
    this->health = health - 20;
}

//4. Unary Operator Overloading
void Character::operator++() {
    this->health = health + 20;
}


