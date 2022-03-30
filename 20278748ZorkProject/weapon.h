#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
protected:
    int damage;
    int attackSpeed;


public:
    Weapon(string description, int weight, float value, int damage, int speed);
    ~Weapon();
    virtual string getLongDescription() override;
    int getDamage();
    void setDamage(int dmg);
    int getSpeed();
    void setSpeed(int spd);

}
;

#endif // WEAPON_H
