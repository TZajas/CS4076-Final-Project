#include "wordle.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

Wordle::Wordle()
{
    solution(":/wordle_solutions.txt");
    allowed_guesses(":/wordle_guesses.txt");
    guess_count = 6;
    game_won = false;
}

void Wordle::allowed_guesses(string fileName){
    fstream textFile;
    string input;
    //textFile.open(":/wordle_guesses.txt",ios::in);
    textFile.open(fileName,ios::in);
    if(textFile.is_open()){
        while(getline(textFile, input)){
            guess_words.push_back(input);
        }
        textFile.close();
    }
}

void Wordle::solution(string fileName){
    fstream textFile;
    string input;
    srand( time(0));
    int random;
    random = rand() % 2315+1;
    //textFile.open(":/wordle_guesses.txt",ios::in);
    textFile.open(fileName,ios::in);
    if(textFile.is_open()){
        for(int i=0;i<random;i++){
            getline(textFile, input);
            currentWord = input;
        }
        textFile.close();
    }
}

bool Wordle::check_if_occurs(const string &guess)
{
    bool occurs = false;
    for (int i = 0; i < static_cast<int>(guess_words.size()); i++)
    {
        if (guess_words.at(i) == guess)
        {
            occurs = true;
        }
    }
    return occurs;
}

vector<string> Wordle::checkLetter(const string &guess){
    string solution = currentWord;
    char preventDuplication='0';
    vector<string> letterColour(static_cast<int>(guess.size()));
    for(int i=0;i<static_cast<int>(guess.size());i++){
        for(int j = 0; j < static_cast<int>(solution.size()); j++)
            if(guess.at(i) == solution.at(j)){
                if (guess.at(i) == solution.at(i)){
                                   letterColour.at(i) = "G";
                                   solution.at(i) = preventDuplication;
                                   break;
                               }else{
                                   letterColour.at(i) = "Y";
                                   solution.at(j) = preventDuplication;
                                   break;
                               }
            }
    }
    return letterColour;
}

bool Wordle::check_if_correct(const vector<string> &letterColour){
    bool check = true;
    for(int i=0;i<5;i++){
        if(letterColour.at(i) != "G"){
            check = false;
        }
    }
    return check;
}

string Wordle::play(const string &guess){
    vector<string>letterColour;
    string output;


    if(guess.length()>5 || guess.length()<5){
        output = "incorrect word";
        return output;
    }else if(check_if_occurs(guess)){
        output = "incorrect word";
        return output;
    }else{
        letterColour = checkLetter(guess);
        if(check_if_correct(letterColour)){
            output = "Game won in ";
            string count = to_string(guess_count);
            game_won = true;
            return output + count;
        }else{
            guess_count--;
            if(guess_count<0){
                game_won = false;
                return "game lost";
            }
            output = "";
            for(int i=0;i<5;i++){
                output = output + letterColour.at(i) + ",";
            }
            return output;
        }
    }


}





