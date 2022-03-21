#ifndef ROOM_H_
#define ROOM_H_

#include "weapon.h"
#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "image.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item*> itemsInRoom;

public:
    inline vector<Item*> getItems()
    {
        return itemsInRoom;
    }
    inline vector<Image> getImages()
    {
        return images;
    }
    vector <Image> images;
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    Room* tpRoom();
    void addImage(Image *img);
    void addItem(Item *inItem);
    void addWeapon(Weapon *inWeapon);
    string displayItem();
    string displayWeapon();
    int numberOfWeapons();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
};

#endif
