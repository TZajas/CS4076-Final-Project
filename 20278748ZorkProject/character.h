#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <string>
#include <vector>
#include "item.h"
using namespace std;

class Character
{
protected:
    string description;
    int health;
    virtual void setHealth(int setHealth)=0;
    int getHealth();
public:
    Character();
    Character(string description);
    virtual ~Character();
    void operator--();
    void operator++();
    inline string getDescription(){
        return description;
    }
    //void addItems(Item *item);
    //string shortDescription();
    //string longDescription();

};

#endif //CHARACTER_H_



