/**********************/
/*                    */
/* Hangman Game       */
/* Ver 1.0            */
/*                    */
/* @Author            */
/* Cosimo Davide      */
/* Viggiano           */
/*                    */
/**********************/

/** INCLUDES **/
#include "game.h"
#include "file.h"

/** CONSTANTS **/

/** VARIABLES **/
int choice = 0;

/** PROTOTYPES **/
void mainMenu(int &choice);
void credits(void);
void highScores(void);
vector<string> order(vector<string> list);
int max(vector<string> list);
