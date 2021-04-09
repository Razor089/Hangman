/**********************************/
/* Implementation of class player */
/*                                */ 
/* @Author Cosimo Davide Viggiano */
/**********************************/

#include "player.h"

Player::Player(string name)
{
    this->name = name;
}

Player::~Player() {}

string Player::getName()
{
    return this->name;
}
