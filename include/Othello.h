#pragma once
#include "Engine.h"


using namespace std;

const int MAX = 1000;
const int MIN = -1000;

typedef struct v_node 
{
    int x;
    int y;
    vector<int> length;
    vector<int> dir_to_flip;
}vNode;

void printV(vector<vNode> &v);
int deleteV(vector<v_node> &v);
int isValid(int a, int b);


class Othello_Game;
class Othello_Board;
class Othello_Move;
class Othello_Checker;
class Othello_Player;
class Othello_Piece;

int check_for_bette_move(Othello_Board temp_board, int depth, int maximizing_player, int alpha, int beta, vNode p, Othello_Player pl, Othello_Player computer);


class Othello_Board : public Board
{
    protected:
        int get_number_of_pieces();

    public:
        int board[8][8];
        int black_piece;
        int white_piece;
        Othello_Board();
        int get_winner();
        void print_board_in_terminal();
        void initial_board();
        int clone_board(Othello_Board);

        friend class Othello_Move;
        friend class Othello_Checker;
        friend int Check_for_better_move(Othello_Board temp_board, int depth, int maximizing_player, int alpha, int beta, vNode p, Othello_Player pl, Othello_Player computer);

};


class Othello_Player : public Player 
{
    int black_or_white;

    public:
        int get_black_or_white();
        void set_black_or_white(int);
        Othello_Player();
};


class Othello_Piece : public Piece 
{
};


class Othello_Move :public Move , public Othello_Board
{
    public:
        int** flip_board(v_node p, Othello_Board board, Othello_Player player);

};


class Othello_Checker : public Checker, public Othello_Board 
{
    public:
        int validation(Othello_Board board, Othello_Player player, int i, int j);
        int chain_of_moves(Othello_Board board, Othello_Player player, vector<v_node> &v);
};


class Othello_Game : public Main_Game
{
};
