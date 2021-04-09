#ifndef GAME_H
#define GAME_H

/**********************************/
/* Definition of the class Game.h */
/*                                */
/* @Author Cosimo Davide Viggiano */
/**********************************/

/* Includes */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "player.h"
#include "file.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::endl;

class Game
{
    private:
        int score;
        Player* player;
        int difficulty;
        int errors;
        string word;
        bool gameOver;
        enum diff {EASY, NORMAL, HARD};
        string guess_word;
        vector<char> letters;
        vector<string> wordList;

    public:
        Game();
        Game(string name);
        ~Game();
        void createPlayer();
        string loadWord();
        void displayWord();
        bool checkWord();
        bool used(char c);
        void initializeGuessWord();
        void play();
        void display();
        void saveScores(string name, int score);
        Player getPlayer();
        int setDifficulty();
};

#endif
