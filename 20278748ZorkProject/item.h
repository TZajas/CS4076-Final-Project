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

public:
    Item ();
    Item (string description, float inWeight, float inValue);
    Item (string description);
    ~Item();
    template <typename T>
        void setWeight(const T& weightGrams);
    string getShortDescription();
    virtual string getLongDescription();
    bool isDropped() const;
    void setDropped(bool dropped);
    float getWeight();
    //void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
    friend bool operator== (Item &item1, Item &item2);
};

#endif /*ITEM_H_*/
