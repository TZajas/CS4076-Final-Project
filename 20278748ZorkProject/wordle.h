#ifndef WORDLE_H
#define WORDLE_H
#include <string>
#include <vector>
using namespace std;

class Wordle
{
public:
    Wordle();
    void allowed_guesses(string fileName);
    string start();
    void solution(string fileName);
    bool check_if_occurs(const string &guess);
    bool check_if_correct(const vector<string> &letterColour);
    string play(const string &guess);
    string printNextLine();
    int guess_count;

    bool game_won;
private:
    vector<string> checkLetter(const string &guess);
    string output;
    string solutionWord;
    vector<string> guess_words;
};

#endif // WORDLE_H
