#include "Room.h"
#include "iostream"

Room::Room(string description, bool wordleCheck)
{
	this->description = description;
    this->wordleCheck = wordleCheck;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription()
{
	return description;
}

string Room::longDescription(Room &room)
{
//    if(!(getEnemies().size()<1)){
//        return "Room = " + description + ".\n" + displayItem() + "\n" + "Enemy = " + getEnemies().at(0)->getDescription() + exitString();
//    }else{
//        return "Room = " + description + ".\n" + displayItem() + "\n" + exitString();

//    }
    stringstream out;
    out<<room;
    return out.str();

}

ostream& operator<<(ostream& os, Room &room)
{
    if(!(room.getEnemies().size()<1)){
        os << "Room = " << room.description << "\n" + room.displayItem() << "\n" << "Enemy = " << room.getEnemies().at(0)->getDescription() << room.exitString();
    }else{
        os << "Room = " << room.description << "\n" + room.displayItem() << "\n" << room.exitString();

    }
    return os;
}


string Room::exitString()
{
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction)
{
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addImage(Image *img)
{
    images.push_back(img);
}

void Room::addItem(Item *inItem)
{
    itemsInRoom.push_back(inItem);
}
void Room::addEnemy(Zombie *enemy)
{
    enemies.push_back(enemy);
}
void Room::removeItemFromRoom(int location)
{
    itemsInRoom.erase(itemsInRoom.begin() + location);
}

string Room::displayItem()
{
    string tempString = "Items in room: ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "No items in this room\n"
                     "search somewhere else adventurer!";
        }
    else if (itemsInRoom.size() > 0) {
       int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + " | " + itemsInRoom[x]->getShortDescription() + " | " ;
            x++;
            }
        }
    return tempString;
}

int Room::numberOfItems()
{
    return itemsInRoom.size();
}

void Room::removeEnemy()
{
    enemies.erase(enemies.begin());
}


int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x]->getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

