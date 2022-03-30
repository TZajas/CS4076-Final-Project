#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character
{
public:
    Enemy(int damage, bool anger);
    int attack(bool angry);
    void setDamage(int damage);
    int getDamage();
    void setAnger(bool angry);
    bool getAnger();
private:
    int damage;
    bool anger;

};

#endif // ENEMY_H
