#include "tool.h"
#include <sstream>

Tool::Tool(string name, int weight, float value, string use, int useSpeed) : Item(name, weight, value)
{
    setUse(use);
    setUseSpeed(useSpeed);
}

void Tool::setUse(string use){
    this->use = use;
}

void Tool::setUseSpeed(int speed){
    this->useSpeed = speed;
}

int Tool::getUseSpeed(){
    return this->useSpeed;
}

string Tool::getUse(){
    return this->use;
}

string Tool::getLongDescription(){
       stringstream str;
        str << "Tool: " << getShortDescription() << ", Value: " << to_string(getValue()) << endl << "Tool use: " << getUse() << endl << "Use Speed: " << getUseSpeed();
        return str.str();
}
