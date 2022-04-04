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
    void isDead();
    bool deathStatus();
    virtual void setHealth(int health);
private:
    int damage;
    bool anger;
    bool dead;

};

#endif // ENEMY_H
