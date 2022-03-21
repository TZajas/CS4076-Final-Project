#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "item.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
protected:
    string description;
    int health;
    //vector <Item> itemsInCharacter;
    virtual void setHealth(int setHealth) = 0;
    //virtual void setStamina(int stamina) = 0;
    int getHealth();
public:
    Character(string description);
    //void addItems(Item *item);
    //string shortDescription();
    //string longDescription();

};

#endif //CHARACTER_H_



