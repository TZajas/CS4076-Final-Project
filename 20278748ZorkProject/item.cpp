#include "item.h"
#include <sstream>

Item::Item(){
    description = "Unknown Item Type";
}

Item::Item (string inDescription, float inWeightGrams=0, float inValue=0) {
    this->description = inDescription;
	setWeight(inWeightGrams);
    setValue(inValue);
    this->dropped = false;
}

Item::Item(string inDescription) {
    description = inDescription;
}

Item::~Item(){

}

template <typename T>
void Item::setWeight(const T& inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weightGrams = inWeightGrams;
}

template void Item::setWeight<int>(const int&);
template void Item::setWeight<float>(const float&);


float Item::getWeight(){
    return weightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

float Item::getValue(){
    return value;
}

void Item::setDropped(bool dropped){
    this->dropped = dropped;
}

bool Item::isDropped() const{
    return dropped;
}

bool operator==(Item &item1, Item &item2) {
    return item1.getShortDescription() == item2.getShortDescription();
}

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    stringstream str;
    str<< "Item: " << getShortDescription() << "Value: " << to_string(getValue()) << "Weight: " << getWeight();
    return str.str();
}

