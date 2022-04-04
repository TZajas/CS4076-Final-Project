#include <iostream>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    createRooms();
    p1 = new Player("Player1");
}

ZorkUL::~ZorkUL(){
    for(int i=0;i< static_cast<int>(rooms.size());i++){
        delete rooms[i];
    }
}

//intialises the rooms in the map and adds them to vector
inline void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *newRoom, *wordleRoom;

    a = new Room("a", false);
        a->addItem(new Weapon("Dagger", 10, 5, 4, 2));
        a->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/a.jpg"));
    rooms.push_back(a);

    b = new Room("b", false);
        b->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/b.jpg"));
        b->addItem(new Tool("Hoe", 10, 5.0, "Loosen soil", 2));
        b->addItem(new Weapon("Hatchet", 12, 7, 6, 1.5));
    rooms.push_back(b);

    c = new Room("c", false);
        c->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/c.jpg"));
    rooms.push_back(c);

    d = new Room("d", false);
        d->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/d.jpg"));
    rooms.push_back(d);

    e = new Room("e", false);
        e->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/e.jpg"));
    rooms.push_back(e);

    f = new Room("f", false);
        f->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/f.jpg"));
    rooms.push_back(f);

    g = new Room("g", false);
        a->addItem(new Weapon("Sword", 20, 40.0, 28, 0.75));
        g->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/g.jpg"));
    rooms.push_back(g);

    h = new Room("h", false);
        //Weapon *axe = new Weapon("Axe", 20, 22.0, 25, 1.2);
        h->addCharacter(new Zombie(25, true, new Item("Key Number 1", 5, 100)));
        h->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/zombie.jpg"));
    rooms.push_back(h);

    i = new Room("i", false);
        i->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/i.jpg"));
        i->addItem(new Item("Golden Key", 5, 100));
    rooms.push_back(i);

    newRoom = new Room("j", true);
        newRoom->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/j.jpg"));
    rooms.push_back(newRoom);

    wordleRoom = new Room("Treasure Room", false);
        wordleRoom->addImage(new Image("/home/tomek/Desktop/ZorkProject20278748/ProjectImages/k.png"));
    rooms.push_back(wordleRoom);


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
    newRoom->setExits(d, NULL, wordleRoom, NULL);
    wordleRoom->setExits(newRoom, NULL, NULL, NULL);
    currentRoom = a;
}

void ZorkUL::play() {
    printWelcome();
}

string ZorkUL::printWelcome() {
    string w = "start\n";
    string e = "info for help\n";
    string l = "\n";
    string c =  currentRoom->longDescription();
    return w + e + l + c;
}

string ZorkUL::printRooms(){
    string des;
    des = currentRoom->longDescription();
    //QString str = QString::fromUtf8(des.c_str());
    return des;
}

void ZorkUL::goRoom(string direction){
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        ;
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
