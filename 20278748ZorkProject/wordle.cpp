#include "wordle.h"

Wordle::Wordle()
{
    allowed_guesses("/home/tomek/Desktop/ZorkProject20278748/20278748ZorkProject/wordle_guesses.txt");
    solution("/home/tomek/Desktop/ZorkProject20278748/20278748ZorkProject/wordle_solutions.txt");
    guess_count = 0;
    game_won = false;
}

//read allowed guesses into a vector
void Wordle::allowed_guesses(string fileName)
{
    fstream newfile;
    newfile.open(fileName,ios::in);
    if (newfile.is_open()) {
        string tp;
        int i=0;
        while (getline(newfile, tp)) {
            *(guess_words + i) = tp;
            i++;
        }
        newfile.close();
    }
}

//searches through solutions words and chooses a random one
void Wordle::solution(string fileName)
{
    fstream textFile;
    string input;
    srand( time(0));
    int random;
    random = rand() % 1574+1;
    textFile.open(fileName,ios::in);
    if(textFile.is_open()){
        for(int i=0;i<random;i++){
            getline(textFile, input);
            solutionWord = input;
        }
        textFile.close();
    }
}

int Wordle::arraySize()
{
    return sizeof(guess_words)/sizeof(guess_words[0]);
}


//searches through guess array to see if guess occurs
bool Wordle::check_if_occurs(const string &guess)
{
    bool occurs = false;
    for (int i = 0; i < arraySize(); i++)
    {
        if (*(guess_words + i) == guess)
        {
            occurs = true;
        }
    }
    return occurs;
}


//checks each individual letter of guess wod agaisnt solution word
//if a letter matches check if it is in the same position
//if it is store a G in that index in the vector if not store a Y at that index
vector<string> Wordle::checkLetter(const string &guess)
{
    string solution = solutionWord;
    char preventDuplication='0';
    vector<string> letterColour(static_cast<int>(guess.size()));
    for(int i=0;i<5;i++){
        letterColour.at(i) = " - ";
    }
    for(int i=0;i<static_cast<int>(guess.size());i++){
        for(int j = 0; j < static_cast<int>(solution.size()); j++)
            if(guess.at(i) == solution.at(j)){
                if (guess.at(i) == solution.at(i)){
                    letterColour.at(i) = " G ";
                    solution.at(i) = preventDuplication;
                    break;
                }else{
                    letterColour.at(i) = " Y ";
                    solution.at(j) = preventDuplication;
                    break;
                }
            }
    }
    return letterColour;
}

//if evry index in array is a G then word is correct
bool Wordle::check_if_correct(const vector<string> &letterColour)
{
    bool check = true;
    for(int i=0;i<5;i++){
        if(letterColour.at(i) != " G "){
            check = false;
        }
    }
    return check;
}


string Wordle::play(const string &guess)
{
    vector<string>letterColour;

    if(guess.length()>5 || guess.length()<5){
        output = "incorrect word\n"
                 "Please enter a 5 letter word";
        return output;
    }else if(!check_if_occurs(guess)){
        output = "Incorrect Word\n"
                 "Please enter a 5 letter word";
        return output;
    }else{
        letterColour = checkLetter(guess);
        if(check_if_correct(letterColour)){
            output = "Game won in ";
            string count = to_string(guess_count+1);
            game_won = true;

            return output + count;
        }else{
            guess_count++;
            string count = to_string(6-guess_count);
            if(guess_count>5){
                game_won = false;

                return "game lost";
            }
            output = "";
            for(int i=0;i<5;i++){
                output = output + letterColour.at(i);
            }
            output = solutionWord + "\n" + output + "\n" + count + " guesses remaining" + "\n" + "guess again";
            return output;
        }
    }
}





