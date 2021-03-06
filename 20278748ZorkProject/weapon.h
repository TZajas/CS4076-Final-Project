#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon : public Item
{
private:
    int damage;
    int attackSpeed;


public:
    Weapon(string description, int weight, float value, int damage, float speed);
    ~Weapon();
    virtual string getLongDescription() override;
    int getDamage();
    void setDamage(int dmg);
    int getSpeed();
    void setSpeed(float spd);

}
;

#endif // WEAPON_H
