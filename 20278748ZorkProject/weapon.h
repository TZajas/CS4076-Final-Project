#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"


class Weapon : public Item
{
public:
    //Weapon(string inDescription, int inWeightGrams=0, float inValue=0);
    Weapon(string inDescription, int inWeightGrams, float inValue, int inDamage);
private:
    string description;
    string longDescription;
    int weightGrams;
    float value;
    int damage;
};

#endif // WEAPON_H
