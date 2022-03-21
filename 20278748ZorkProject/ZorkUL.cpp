#include <iostream>
#include "item.h"
#include "character.h"
#include "player.h"

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
    p1 = new Player("Player1");
}

ZorkUL::~ZorkUL(){
    for(int i=0;i<rooms.size();i++){
        delete rooms[i];
    }
}

//intialises the rooms in the map and adds them to vector
inline void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *newRoom;

    a = new Room("a");
        a->addItem(new Weapon("x", 1, 22.0, 2, 4));
        a->addItem(new Weapon("y", 2, 22, 4, 5));
        a->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/a.jpg"));
    rooms.push_back(a);
    b = new Room("b");
        b->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/b.jpg"));
        b->addItem(new Weapon("x", 3, 33, 6, 7));
        b->addItem(new Weapon("yy", 4, 44, 8, 9));
    rooms.push_back(b);
    c = new Room("c");
        c->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/c.jpg"));
    rooms.push_back(c);
    d = new Room("d");
        d->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/d.jpg"));
    rooms.push_back(d);
    e = new Room("e");
        e->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/e.jpg"));
    rooms.push_back(e);
    f = new Room("f");
        f->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/f.jpg"));
    rooms.push_back(f);
    g = new Room("g");
        g->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/g.jpg"));
    rooms.push_back(g);
    h = new Room("h");
        h->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/h.jpg"));
    rooms.push_back(h);
    i = new Room("i");
        i->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/i.jpg"));
    rooms.push_back(i);
    newRoom = new Room("j");
        newRoom->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/j.jpg"));
    rooms.push_back(newRoom);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, newRoom, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    newRoom->setExits(d, NULL, NULL, NULL);
    currentRoom = a;
}

/**
 *  Main play routine.  L#ifndef PLAYER_H
#define PLAYER_Hoops until end of play.
 */

void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    /*bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    };
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (
    cout << endl;
    cout << "end" << endl;*/
}

string ZorkUL::printWelcome() {
    string w = "start\n";
    string e = "info for help\n";
    string l = "\n";
    string c =  currentRoom->longDescription();
    return w + e + l + c;

}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
/*bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }


    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "    ;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (     |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "        [newRoom]        " << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "in;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (complete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }
    else if (commandWord.compare("teleport") == 0)
    {
        if (!command.hasSecondWord()){
            cout << "incomplete input" << endl;
        }
        else{
            teleport(command.getSecondWord());
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; //signal to quit
    }
    return false;
}*/
/** COMMANDS **/
/*void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}*/

/*void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}*/

/*string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}*/

string ZorkUL::printRooms(){
    string des;
    des = currentRoom->longDescription();
    //QString str = QString::fromUtf8(des.c_str());
    return des;
}

void ZorkUL::goRoom(string direction){
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        currentRoom;
    else
    {
        currentRoom = nextRoom;
    }
}



void ZorkUL::teleport(){
        unsigned int roomSize = rooms.size();
        unsigned int randRoom = rand() % roomSize;
        currentRoom = rooms[randRoom];

}
