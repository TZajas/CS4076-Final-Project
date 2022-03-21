#include "weapon.h"
#include <sstream>

Weapon::Weapon(string description, int weight, float value, int damage, int speed) : Item(description, weight, value){
    setSpeed(speed);
    setDamage(damage);
}

Weapon::~Weapon() {
}

void Weapon::setDamage(int dmg){
    this->damage = dmg;
}

void Weapon::setSpeed(int spd){
    this->attackSpeed = spd;
}

int Weapon::getDamage(){
    return this->damage;
}

int Weapon::getSpeed(){
    return this->attackSpeed;
}

string Weapon::getLongDescription() {
    stringstream str;
    str <<"Weapon Type: " << getShortDescription() << endl << " | Value: "<< to_string(getValue()) << " | Weight: " << getWeight() << endl << " | Damage: "
       << getDamage() << " | Speed: " << getSpeed();
    return str.str();
}
