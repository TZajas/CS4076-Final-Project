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
    virtual void setHealth(int setHealth)=0;
    int health;
public:
    Character();
    Character(string description, int health);
    virtual ~Character();
    void operator--();
    void operator++();
    inline string getDescription(){
        return description;
    }
    string getHealth();
    void decrementHealth();
};

#endif //CHARACTER_H_



