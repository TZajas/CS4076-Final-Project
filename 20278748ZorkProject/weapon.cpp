#include "weapon.h"
#include "item.h"
Weapon::Weapon(string inDescription, int inWeightGrams, float inValue, int inDamage) : Item(inDescription, inWeightGrams, inValue, inDamage)
{
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
    damage=inDamage;

}


