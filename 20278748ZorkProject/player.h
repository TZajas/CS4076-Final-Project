#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

class Player : public Character
{
public:
    Player(string playerName, int health);
    ~Player();
    string listItems();
    void addItems(Item *item);
    string shortDescription();
    void emptyInventory();
    void removeItem(Item *item);
    bool hasItem(string item);
    virtual void setHealth(int setHealth);
    //vector <Item*>itemsInCharacter;itemsInCharacter;
    inline vector <Item*> getInventory(){
        return itemsInCharacter;
    }
private:
    vector <Item*>itemsInCharacter;
    bool inventoryWeight();
};

#endif //PLAYER_H
