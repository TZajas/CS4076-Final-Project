#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "enemy.h"

class Zombie : public Enemy
{
public:
    Zombie(string description, int damage, int health, bool anger, Item *heldItem);
    ~Zombie();
    Item* dropItem();
    void isDead();
    bool deathStatus();
private:
    int attackSpeed;
    Item *droppedItem;
    bool dead;
};

#endif // ZOMBIE_H
