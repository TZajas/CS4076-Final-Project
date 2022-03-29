#ifndef ZORKUL_H_
#define ZORKUL_H_


#include "Room.h"
#include "item.h"
#include "character.h"
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Room *currentRoom;
    Player *p1;
    vector<Room*> rooms;
    void createRooms();
    void printHelp();
    void createItems();
    void displayItems();

public:
    inline Room* getCurrentRoom() const
    {
        return currentRoom;
    }

    inline void setCurrentRoom(Room* r)
    {
        currentRoom = r;
    }

    inline vector<Room*> getRooms()
    {
        return rooms;
    }

    inline Player* getPlayer()
    {
        return p1;
    }

    string printRooms();
    string printWelcome();
    string dir;
    ZorkUL();
    ~ZorkUL();
    void play();
    void goRoom(string direction);
    void teleport();
};

#endif /*ZORKUL_H_*/
