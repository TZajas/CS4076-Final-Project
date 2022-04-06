
#include "character.h"

Character::Character(){
    this->description="Unknown character";
}

Character::Character(string description, int health) {
    this->description = description;
    this->health = health;
}

Character::~Character() {
   ;
}

void Character::setHealth(int setHealth){
    this->health=setHealth;
}

string Character::getHealth(){
    stringstream str;
    str << description << " health: " << this->health;
    return str.str();

}


void Character::operator--() {
    health = health - 20;
}

//4. Unary Operator Overloading
void Character::operator++() {
    this->health = this->health + 20;
}


