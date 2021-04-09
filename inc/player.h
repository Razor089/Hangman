#ifndef PLAYER_H
#define PLAYER_H

/**********************************/
/* Definition of the class player */
/**********************************/

#include <string>

using std::string;

class Player
{
    private:
        string name;

    public:
        Player(string name);
        ~Player();
        string getName();
};

#endif
