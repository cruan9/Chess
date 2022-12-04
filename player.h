#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>
#include "pieces.h"

class Board;

class Player{
    public:        
        std::vector<std::string> allValidMoves;  //strings formatted "startcoordsendcoords" ("a4e4")
        Board* b;
        Player(Board* b);
        virtual ~Player(){};
        virtual bool move(double &whiteScore, double &blackScore) = 0;
};
class Human : public Player{
    public:
        bool move(double &whiteScore, double &blackScore);
        Human(Board* b);
};

class Computer1 : public Player{

    public:
        bool move(double &whiteScore, double &blackScore);
        Computer1(Board* b);

};

class Computer2 : public Player{
    std::vector<std::string> captureCheckMoves;
    public:
        bool move(double &whiteScore, double &blackScore);
        Computer2(Board* b);
};

class Computer3 : public Player{
    public:
        bool move(double &whiteScore, double &blackScore);
};

class Computer4 : public Player{
    public:
        bool move(double &whiteScore, double &blackScore);
};
#endif