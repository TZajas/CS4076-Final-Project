#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string description;
	string longDescription;
	int weightGrams;
	float value;
    bool dropped;
    //bool weaponCheck;

public:
    Item ();
    Item (string description, float inWeight, float inValue /*int weaponCheck*/);
    Item (string description);
    template <typename T>
        void setWeight(const T& weightGrams);
    string getShortDescription();
    virtual string getLongDescription();
    bool isDropped() const;
    void setDropped(bool dropped);
    float getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
    //int getWeaponCheck();
    //void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
