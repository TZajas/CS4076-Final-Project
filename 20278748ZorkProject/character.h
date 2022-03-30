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
    virtual void setHealth(int setHealth) = 0;
    virtual int getHealth() = 0;
public:
    Character();
    Character(string description);
    ~Character();
    void operator--();
    void operator++();
    //void addItems(Item *item);
    //string shortDescription();
    //string longDescription();

};

#endif //CHARACTER_H_



