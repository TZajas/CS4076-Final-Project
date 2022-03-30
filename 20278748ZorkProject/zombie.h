#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "enemy.h"

class Zombie : public Enemy
{
public:
    Zombie(int damage, bool anger, Item *heldItem);
    Item dropItem();
    void isDead();
private:
    int attackSpeed;
    Item *droppedItem;
    bool dead;
};

#endif // ZOMBIE_H
