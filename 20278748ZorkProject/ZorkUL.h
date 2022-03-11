#ifndef ZORKUL_H_
#define ZORKUL_H_


#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    //Parser parser;
    Room *currentRoom;
    vector<Room*> rooms;
    void createRooms();
   // bool processCommand(Command command);
    void printHelp();
   // void goRoom(Command command);
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
