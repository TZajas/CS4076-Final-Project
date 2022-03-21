#include "character.h"

Character::Character(string description) {
    this->description = description;
    this->health = 100;
}

/*void Character::addItems(Item *item) {
    itemsInCharacter.push_back(*item);
}*/

/*string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}

int Character::getHealth(){
    return this->health;
}*/


