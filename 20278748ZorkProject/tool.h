#ifndef TOOL_H
#define TOOL_H
#include "item.h"

class Tool : public Item
{
public:
    Tool(string name, int weight, float value, string use, int useSpeed);
    string getUse();
    int getUseSpeed();
    void setUse(string use);
    void setUseSpeed(int speed);
    virtual string getLongDescription() override;
private:
    string use;
    int useSpeed;
};

#endif // TOOL_H
