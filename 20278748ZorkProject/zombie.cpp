#include "zombie.h"

Zombie::Zombie(string description, int health, int damage, bool angry, Item *heldItem) : Enemy(description, health, damage, angry)
{
    this->description = "Zombie";
    this->droppedItem = heldItem;
    this->attackSpeed = 2;
    this->dead = false;
}

Zombie::~Zombie(){

}

Item* Zombie::dropItem(){
    if(dead)
        return droppedItem;
}

void Zombie::isDead(){
    if(this->health<=0){
        dead = true;
    }else{
        dead =false;
    }
}

bool Zombie::deathStatus(){
    isDead();
    return dead;
}
