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
    virtual void setHealth(int setHealth);
    vector <Item*>itemsInCharacter;

};

#endif //PLAYER_H
