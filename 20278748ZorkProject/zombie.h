#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "character.h"
#include "enemy.h"
#include "weapon.h"

class Zombie : public Character, public Enemy
{
public:
    Zombie(string description, int damage, bool anger, int attackSpeed, Weapon weapon);
};

#endif // ZOMBIE_H
