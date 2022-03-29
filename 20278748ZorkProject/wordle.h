#ifndef WORDLE_H
#define WORDLE_H
#include <string>
#include <vector>
using namespace std;

class Wordle
{
public:
    Wordle();

private:
    void allowed_guesses(string fileName);
    void solution(string fileName);
    bool check_if_occurs(const string &guess);
    bool check_if_correct(const vector<string> &letterColour);
    vector<string> checkLetter(const string &guess);
    string play(const string &guess);
    int guess_count;
    string currentWord;
    vector<string> guess_words;
    bool game_won;

};

#endif // WORDLE_H
