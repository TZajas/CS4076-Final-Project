#ifndef ROOM_H_
#define ROOM_H_

#include "tool.h"
#include "weapon.h"
#include <map>
#include <string>
#include <vector>
//#include "item.h"
#include "image.h"
#include "wordle.h"
#include "character.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item*> itemsInRoom;
    vector <Image> images;
    vector <Character*> characters;
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void addImage(Image *img);
    void addItem(Item *inItem);
    void addCharacter(Character *character);
    void addWordle(Wordle *wordle);
    int isItemInRoom(string inString);
    friend class ZorkUL;
public:
    inline vector<Item*> getItems()
    {
        return itemsInRoom;
    }
    inline vector<Image> getImages()
    {
        return images;
    }

    inline vector<Character*> getCharacters()
    {
        return characters;
    }
    int numberOfItems();
    Room(string description, bool wordleCheck);
    bool wordleCheck;
	string shortDescription();
    string longDescription();
	Room* nextRoom(string direction);
    string displayItem();
    int numberOfWeapons();
    void removeItemFromRoom(int location);
};

#endif
