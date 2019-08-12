#include "Othello.h"

void printV(vector<vNode>& v)
{
    int i;
    for (i = 0; i<v.size(); i++)
    {
        cout << v[i].x << " " << v[i].y;
        cout << endl;
    }
    cout << "***************************\n";
}


int deleteV(vector<v_node>& v)
{
    v.clear();
    return 1;
}


int is_valid(int a, int b)
{
    if (a<8 && b<8 && a >= 0 && b >= 0)
    {
        return 1;
    }
    else return 0;
}


int Othello_Board::get_number_of_pieces()
{
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (this->board[i][j] == 0) 
            {
                this->black_piece++;
            }
            else if (this->board[i][j] == 1) 
            {
                this->white_piece++;
            }
        }
    }
    return 0;
}


Othello_Board::Othello_Board()
{
    black_piece = 0;
    white_piece = 0;
    this->set_height(8);
    this->set_width(8);
}


int Othello_Board::get_winner()
{
    this->get_number_of_pieces();
    this->set_number_of_pieces(this->black_piece + this->white_piece);
    return this->black_piece - this->white_piece;
}


void Othello_Board::print_board_in_terminal()
{
    int i, j;
    cout << "\t";

    for (i = 0; i<8; i++)
    {
        cout << i << "\t";
    }
    cout << endl;

    for (i = 0; i<8; i++)
    {
        cout << i << "\t";
        for (j = 0; j<8; j++)
        {
            if (this->board[i][j] == -1)
            {
                cout << "_" << "\t";
            }
            else if (this->board[i][j] == 0) 
            {
                cout << "B" << "\t";
            }
            else 
            {
                cout << "W" << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}


void Othello_Board::initial_board()
{
    int i, j;
    for (i = 0; i<8; i++)
    {
        for (j = 0; j<8; j++)
        {
            this->board[i][j] = -1;
        }
    }

    this->board[4][4] = 0;
    this->board[3][3] = 0;
    this->board[3][4] = 1;
    this->board[4][3] = 1;
}


int Othello_Board::clone_board(Othello_Board board)
{
    copy(&board.board[0][0], &board.board[0][0] + 64, &this->board[0][0]);
    return 0;
}


int Othello_Player::get_black_or_white()
{
    return black_or_white;
}


void Othello_Player::set_black_or_white(int color)
{
    this->black_or_white = color;
}


Othello_Player::Othello_Player()
{
    this->_number_of_pieces = 32;
}


int** Othello_Move::flip_board(v_node p, Othello_Board board, Othello_Player player)
{
    int a[8][8];
    copy(&board.board[0][0], &board.board[0][0] + 64, &a[0][0]);
    int typePeice = player.get_black_or_white();
    a[p.x][p.y] = typePeice;
    int i = p.x, j = p.y, k, l, m;
    for (m = 0; m<p.dir_to_flip.size(); m++)
    {
        if (p.dir_to_flip[m] == 1)
        {
            a[i - 1][j - 1] = typePeice;
            for (k = i - 2, l = j - 2; is_valid(k, l); k--, l--)
            {
                if (a[k][l] == typePeice)
                {
                    break;
                }
                a[k][l] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 2)
        {
            a[i - 1][j] = typePeice;
            for (k = i - 2; k >= 0 && a[k][j] != -1; k--)
            {
                if (a[k][j] == typePeice)
                {
                    break;
                }
                a[k][j] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 3)
        {
            a[i - 1][j + 1] = typePeice;
            for (k = i - 2, l = j + 2; is_valid(k, l); k--, l++)
            {
                if (a[k][l] == typePeice)
                {
                    break;
                }
                a[k][l] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 4)
        {
            a[i][j - 1] = typePeice;
            for (k = j - 2; k >= 0; k--)
            {
                if (a[i][k] == typePeice)
                {
                    break;
                }
                a[i][k] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 6)
        {
            a[i][j + 1] = typePeice;
            for (k = j + 2; k<8; k++)
            {
                if (a[i][k] == typePeice)
                {
                    break;
                }
                a[i][k] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 7)
        {
            a[i + 1][j - 1] = typePeice;
            for (k = i + 2, l = j - 2; is_valid(k, l); k++, l--)
            {
                if (a[k][l] == typePeice)
                {
                    break;
                }
                a[k][l] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 8)
        {
            a[i + 1][j] = typePeice;
            for (k = i + 2; k<8 && a[k][j] != -1; k++)
            {
                if (a[k][j] == typePeice)
                {
                    break;
                }
                a[k][j] = typePeice;
            }
        }
        else if (p.dir_to_flip[m] == 9)
        {
            a[i + 1][j + 1] = typePeice;
            for (k = i + 2, l = j + 2; is_valid(k, l); k++, l--)
            {
                if (a[k][l] == typePeice)
                {
                    break;
                }
                a[k][l] = typePeice;
            }
        }
    }
    copy(&a[0][0], &a[0][0] + 64, &board.board[0][0]);
    int** temp;
    temp = (int**)malloc(8 * sizeof(int*));

    for (int i = 0; i < 8; i++)
    {
        temp[i] = (int*)malloc(8 * sizeof(int));
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) {
            temp[i][j] = a[i][j];
        }
    }
    return temp;

}


int Othello_Checker::validation(Othello_Board board, Othello_Player player, int i, int j)
{
    int count = 0, k, l;
    int a[8][8];
    copy(&board.board[0][0], &board.board[0][0] + 64, &a[0][0]);
    int typePeice = player.get_black_or_white();
    if (a[i][j] == -1)
    {
        if (is_valid(i + 1, j) && a[i + 1][j] == (1 - typePeice))
        {
            for (k = i + 2; k<8 && a[k][j] != -1; k++)
            {
                if (a[k][j] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i - 1, j) && a[i - 1][j] == (1 - typePeice))
        {
            for (k = i - 2; k >= 0 && a[k][j] != -1; k--)
            {
                if (a[k][j] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i + 1, j + 1) && a[i + 1][j + 1] == (1 - typePeice))
        {
            for (k = i + 2, l = j + 2; is_valid(k, l) && a[k][l] != -1; k++, l++)
            {
                if (a[k][l] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i + 1, j - 1) && a[i + 1][j - 1] == (1 - typePeice))
        {
            for (k = i + 2, l = j - 2; is_valid(k, l) && a[k][l] != -1; k++, l--)
            {
                if (a[k][l] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i, j - 1) && a[i][j - 1] == (1 - typePeice))
        {
            for (k = j - 2; k >= 0 && a[i][k] != -1; k--)
            {
                if (a[i][k] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i, j + 1) && a[i][j + 1] == (1 - typePeice))
        {
            for (k = j + 2; k<8 && a[i][k] != -1; k++)
            {
                if (a[i][k] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i - 1, j - 1) && a[i - 1][j - 1] == (1 - typePeice))
        {
            for (k = i - 2, l = j - 2; is_valid(k, l) && a[k][l] != -1; k--, l--)
            {
                if (a[k][l] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
        if (is_valid(i - 1, j + 1) && a[i - 1][j + 1] == (1 - typePeice))
        {
            for (k = i - 2, l = j + 2; is_valid(k, l) && a[k][l] != -1; k--, l++)
            {
                if (a[k][l] == typePeice)
                {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}


int Othello_Checker::chain_of_moves(Othello_Board board, Othello_Player player, vector<v_node>& v)
{
    int i, j, k, l;
    int count = 0, flag = 0;
    int a[8][8];
    copy(&board.board[0][0], &board.board[0][0] + 64, &a[0][0]);
    int typePiece = player.get_black_or_white();
    for (i = 0; i<8; i++)
    {
        for (j = 0; j<8; j++)
        {
            flag = 0;
            if (a[i][j] == -1)
            {
                vNode temp;
                temp.x = i;
                temp.y = j;
                if (is_valid(i + 1, j) && a[i + 1][j] == (1 - typePiece))
                {
                    for (k = i + 2; k<8 && a[k][j] != -1; k++)
                    {
                        if (a[k][j] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(k - i - 1);
                            temp.dir_to_flip.push_back(8);
                            break;
                        }
                    }
                }
                if (is_valid(i - 1, j) && a[i - 1][j] == (1 - typePiece))
                {
                    for (k = i - 2; k >= 0 && a[k][j] != -1; k--)
                    {
                        if (a[k][j] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(i - k - 1);
                            temp.dir_to_flip.push_back(2);
                            break;
                        }
                    }
                }
                if (is_valid(i + 1, j + 1) && a[i + 1][j + 1] == (1 - typePiece))
                {
                    for (k = i + 2, l = j + 2; is_valid(k, l) && a[k][l] != -1; k++, l++)
                    {
                        if (a[k][l] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(k - i - 1);
                            temp.dir_to_flip.push_back(9);
                            break;
                        }
                    }
                }
                if (is_valid(i + 1, j - 1) && a[i + 1][j - 1] == (1 - typePiece))
                {
                    for (k = i + 2, l = j - 2; is_valid(k, l) && a[k][l] != -1; k++, l--)
                    {
                        if (a[k][l] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(k - i - 1);
                            temp.dir_to_flip.push_back(7);
                            break;
                        }
                    }
                }
                if (is_valid(i, j - 1) && a[i][j - 1] == (1 - typePiece))
                {
                    for (k = j - 2; k >= 0 && a[i][k] != -1; k--)
                    {
                        if (a[i][k] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(j - k - 1);
                            temp.dir_to_flip.push_back(4);
                            break;
                        }
                    }
                }
                if (is_valid(i, j + 1) && a[i][j + 1] == (1 - typePiece))
                {
                    for (k = j + 2; k<8 && a[i][k] != -1; k++)
                    {
                        if (a[i][k] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(k - j - 1);
                            temp.dir_to_flip.push_back(6);
                            break;
                        }
                    }
                }
                if (is_valid(i - 1, j - 1) && a[i - 1][j - 1] == (1 - typePiece))
                {
                    for (k = i - 2, l = j - 2; is_valid(k, l) && a[k][l] != -1; k--, l--)
                    {
                        if (a[k][l] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(i - k - 1);
                            temp.dir_to_flip.push_back(1);
                            break;
                        }
                    }
                }
                if (is_valid(i - 1, j + 1) && a[i - 1][j + 1] == (1 - typePiece))
                {
                    for (k = i - 2, l = j + 2; is_valid(k, l) && a[k][l] != -1; k--, l++)
                    {
                        if (a[k][l] == typePiece)
                        {
                            flag = 1;
                            count++;
                            temp.length.push_back(i - k - 1);
                            temp.dir_to_flip.push_back(3);
                            break;
                        }
                    }
                }
                if (flag == 1)
                    v.push_back(temp);
            }
        }
    }
    return count;
}

int check_for_better_move(
    Othello_Board TempBoard,int depth, int maximizingPlayer, int alpha, int beta, vNode p, Othello_Player player,Othello_Player computer){
    int tempBoard[8][8];
    copy(&TempBoard.board[0][0], &TempBoard.board[0][0] + 64, &tempBoard[0][0]);
    int typePiece = player.get_black_or_white();
    Othello_Move move;
    Othello_Checker checker;
    move.flip_board(p, TempBoard, player);
    if (depth == 5)
        return TempBoard.get_winner();

    if (maximizingPlayer)
    {
        int best = MIN;
        vector<vNode> temp;
        checker.chain_of_moves(TempBoard, computer , temp);

        for (int i = 0; i < temp.size(); i++)
        {
            Othello_Board Tempboard1;
            int tempBoard1[8][8];
            copy(&Tempboard1.board[0][0], &Tempboard1.board[0][0] + 64, &tempBoard1[0][0]);
            copy(&tempBoard[0][0], &tempBoard[0][0] + 64, &tempBoard1[0][0]);
            int val = check_for_better_move(Tempboard1, depth + 1, false, alpha, beta, temp[i], computer , player);
            best = max(best, val);
            alpha = max(alpha, best);
            
            if (beta <= alpha)
                break;
        }
        return best;
    }
    else
    {
        int best = MAX;
        vector<vNode> temp;
        checker.chain_of_moves(TempBoard, computer, temp);
        for (int i = 0; i < temp.size(); i++)
        {
            Othello_Board Tempboard1;
            int tempBoard1[8][8];
            copy(&Tempboard1.board[0][0], &Tempboard1.board[0][0] + 64, &tempBoard1[0][0]);///////////////may cause lots of bugs
            copy(&tempBoard[0][0], &tempBoard[0][0] + 64, &tempBoard1[0][0]);////////////////////////////mix this with upper line
            int val = check_for_better_move(Tempboard1, depth + 1, true, alpha, beta, temp[i], computer , player);
            best = min(best, val);
            beta = min(beta, best);

            if (beta <= alpha)
                break;
        }
        return best;
    }
}

int main() {
    Othello_Board main_board;
    main_board.initial_board();

    Othello_Checker check;
    Othello_Move move;

    vector< vNode > v;

    main_board.print_board_in_terminal();
    Othello_Player player, computer;
    int temp_play;
    cout << "Do you want to play as \n0)Black or \n1)White?\n";
    cin >> temp_play;
    player.set_black_or_white(temp_play);
    computer.set_black_or_white(1 - temp_play);

    if (temp_play == 0)
    {
        check.chain_of_moves(main_board, player, v);
        cout << "********************\n";
        cout << "Your moves are: \n";
        printV(v);
        int tempX, tempY;
        cout << "Enter your move(x and y co-ordinates): ";
        cin >> tempX >> tempY;

        while (!check.validation(main_board, player, tempX, tempY))
        {
            cout << "Wrong Move\n";
            cout << "Enter your move(x and y co-ordinates): ";
            cin >> tempX >> tempY;
        }
        vNode temp;
        temp.x = tempX;
        temp.y = tempY;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].x == tempX && v[i].y == tempY)
            {
                for (int j = 0; j<v[i].dir_to_flip.size(); j++)
                {
                    temp.dir_to_flip.push_back(v[i].dir_to_flip[j]);
                }
            }
        }
        int ** temp_main_board;
        temp_main_board = move.flip_board(temp, main_board, player);

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                main_board.board[i][j] = temp_main_board[i][j];
            }
        }

        cout << "After Player's move:\n ";
        main_board.print_board_in_terminal();
    }
    int flag = 0;
    deleteV(v);
    while (check.chain_of_moves(main_board, computer, v))
    {
        int i;
        int alpha = MIN;
        int beta = MAX;
        int pos = 0;
        int best;

        if (computer.get_black_or_white() == 0)
        {
            best = MIN;
        }
        else 
        {
            best = MAX;
        }

        int tempBoard[8][8];
        Othello_Board temp_borad;

        for (i = 0; i < v.size(); i++)
        {
            temp_borad.clone_board(main_board);
            if (computer.get_black_or_white() == 0)
            {
                int val = check_for_better_move(temp_borad, 1, false, alpha, beta, v[i], computer,player);
                if (best < val)
                {
                    best = val;
                    pos = i;
                    alpha = max(alpha, best);
                }

                if (beta <= alpha)
                    break;
            }
            else 
            {
                int val = check_for_better_move(temp_borad, 1, true, alpha, beta, v[i], computer , player);
                if (best > val)
                {
                    best = val;
                    pos = i;
                    beta = min(beta, best);
                }

                if (beta <= alpha)
                    break;
            }
        }

        cout << "Computer's Move: " << v[pos].x << " " << v[pos].y << endl;
        int ** temp_main_board;
        temp_main_board = move.flip_board(v[pos], main_board, computer);

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                main_board.board[i][j] = temp_main_board[i][j];
            }
        }

        cout << best << endl;
        cout << "After Computer's move:\n ";
        main_board.print_board_in_terminal();
        deleteV(v);
        
        if (check.chain_of_moves(main_board, player, v))
        {
            cout << "********************\n";
            cout << "Your moves are: \n";
            printV(v);
            int tempX, tempY;
            cout << "Enter your move(x and y co-ordinates): ";
            cin >> tempX >> tempY;
            while (!check.validation(main_board, player, tempX, tempY))
            {
                cout << "Wrong Move\n";
                cout << "Enter your move(x and y co-ordinates): ";
                cin >> tempX >> tempY;
            }
            vNode temp;
            temp.x = tempX;
            temp.y = tempY;

            for (i = 0; i<v.size(); i++)
            {
                if (v[i].x == tempX && v[i].y == tempY)
                {
                    for (int j = 0; j<v[i].dir_to_flip.size(); j++)
                    {
                        temp.dir_to_flip.push_back(v[i].dir_to_flip[j]);
                    }
                }
            }

            int ** temp_main_board;
            temp_main_board = move.flip_board(temp, main_board, player);

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    main_board.board[i][j] = temp_main_board[i][j];
                }
            }

            cout << "After Player's move:\n ";
            main_board.print_board_in_terminal();
        }
        else 
        {
            cout << "No other move left!\n";
            flag = 1;
            break;
        }
        deleteV(v);
    }

    int score = main_board.get_winner();

    if (computer.get_black_or_white() == 0)
    {
        if (score > 0)
        {
            cout << "Computer has won!\n";
        }
        else if (score == 0)
        {
            cout << "It's a draw match'!\n";
        }
        else {
            cout << "You have won!\n";
        }
    }
    else {
        if (score > 0)
        {
            cout << "You have won!\n";
        }
        else if (score == 0)
        {
            cout << "It's a draw match'!\n";
        }
        else {
            cout << "Computer has won!\n";
        }
    }
    return 0;
}
