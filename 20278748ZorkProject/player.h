#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

class Player : public Character
{
public:

    Player(string playerName);
    ~Player();
    string listItems();
    void addItems(Item *item);
    string shortDescription();
    void emptyInventory();
    void removeItem(Item *item);
    bool hasItem(string item);
    virtual void setHealth(int setHealth);
    vector <Item*>itemsInCharacter;
private:
    bool inventoryWeight();
};

#endif //PLAYER_H
