#ifndef WORDLEGAME_H
#define WORDLEGAME_H
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class WordleGame
{
public:
    WordleGame();
private:
    vector<string> words;
    string guess;
    int wordCount;
};

#endif // WORDLEGAME_H
