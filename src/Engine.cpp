#include "Engine.h"

int Dice::random()
{
    srand(time(NULL));
    int random_number = rand() % 6 + 1;                
    return random_number;
}


void Board::set_number_of_pieces(int number_of_shapes)
{
    _number_of_pieces = number_of_shapes;
}


void Board::set_width(int width)
{
    _width = width;
}


void Board::set_height(int height)
{
    _height = height;
}


int Board::get_width()
{
    return _width;
}


int Board::get_height()
{
    return _height;
}

