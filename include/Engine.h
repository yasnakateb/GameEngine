#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <fstream>
#include <algorithm>
#define ERROR -1
#define SUCCESS 1

using namespace std;

class Clock 
{
    public:
        int time;
};


class Shape 
{
};


class Board : public Shape
{
    int _number_of_pieces;
    int _width;
    int _height;
    public:
        void set_number_of_pieces(int number_of_shapes);
        void set_width(int width);
        void set_height(int height);
        int  get_width();
        int  get_height();
        virtual int get_winner() = 0;
};


class Player 
{
    public:
        string _name;
        int _number_of_pieces;
        Clock _clock;

};


class Piece 
{

};


class Dice {
public:
    static int random();
};


class Move 
{
};


class Checker 
{
    public:
        int validation();
        int chain_of_moves();
};


class AI 
{
    public:
        int check_for_better_move();
};


class Main_Game 
{
    public:
        vector <Player> players;

};