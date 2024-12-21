#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
public:
    Player(string name, char token):name_(name),token_(token){}
    char get_token(){return token_;}
    string get_name(){return name_;}
private:
    string name_;
    char token_;
};

#endif