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

template void Item::setWeight<int>(const int&);
template void Item::setWeight<float>(const float&);
template void Item::setValue<int>(const int&);
template void Item::setValue<float>(const float&);

template <typename T>
void Item::setWeight(const T& inWeightGrams){
       weightGrams = inWeightGrams;
}

float Item::getWeight(){
    return weightGrams;
}

template <typename T>
void Item::setValue(const T& inValue){
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
    str<< "Item: " << getShortDescription() << " | Value: " << to_string(getValue()) << " | Weight: " << getWeight();
    return str.str();
}

