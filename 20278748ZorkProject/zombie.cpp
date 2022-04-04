#include "zombie.h"

Zombie::Zombie(int damage, bool angry, Item *heldItem) : Enemy(damage, angry)
{
    this->health = 150;
    this->description = "Zombie";
    this->droppedItem = heldItem;
    this->attackSpeed = 2;
    this->dead = false;
}

Item Zombie::dropItem(){
    if(dead)
        return *droppedItem;
}

void Zombie::isDead(){
    if(this->health<=0){
        dead = true;
    }else{
        dead =false;
    }
}
