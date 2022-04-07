#ifndef ITEM_H_
#define ITEM_H_
#include <map>
#include <string>
#include <iostream>
#include <sstream>
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

    template <typename T>
        void setValue(const T& value);

    string getShortDescription();
    virtual string getLongDescription();
    bool isDropped() const;
    void setDropped(bool dropped);
    float getWeight();
	float getValue();
    friend bool operator== (Item &item1, Item &item2);
    friend ostream& operator<<(ostream& os, Item &item);

};

#endif /*ITEM_H_*/
