#include <iostream>
using namespace std;
#define red "\033[31m"
#define blue "\033[34m"
#define yellow "\033[33m"
#define normal "\033[0m"

void initializeboard(char board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = '_';
        }
    }
}

void displayboard(char board[4][4])
{
    cout << "    1   2   3   4" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << " " << "|";
        for (int j = 0; j < 4; j++)
        {
            cout << " ";
            if (board[i][j] == 'x')
                cout << blue << board[i][j] << " " << normal << "|";
            else if (board[i][j] == 'o')
                cout << red << board[i][j] << " " << normal << "|";
            else
                cout << board[i][j] << " |";
        }
        cout << endl;
    }
}
void move(char board[4][4], char player)
{
    int r, c;
    bool check = false;
    while (check == false)
    {
        cout << "player " << "(" << player << ")" << " enter row and column:";
        cin >> r >> c;
        if (r >= 1 && r <= 4 && c >= 1 && c <= 4)
        {
            r--;
            c--;
            if (board[r][c] == '_')
            {
                board[r][c] = player;
                check = true;
            }
            else
            {
                cout << red << "This place is already filled!" << normal << endl;
            }
        }
        else
        {
            cout << red << "Invalid place,Enter agin number from 1 to 4" << normal << endl;
        }
    }
}

bool win(char board[4][4], char player)
{
    int count = 0;
    // rows
    for (int i = 0; i < 4; i++)
    {
        count = 0;
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == player)
            {
                count++;
            }
        }
        if (count == 4)
        {
            return true;
        }
    }
    // columns
    for (int i = 0; i < 4; i++)
    {
        count = 0;
        for (int j = 0; j < 4; j++)
        {
            if (board[j][i] == player)
            {
                count++;
            }
        }
        if (count == 4)
        {
            return true;
        }
    }
    // main diagonal
    count = 0;
    for (int j = 0; j < 4; j++)
    {
        if (board[j][j] == player)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    // sub_diagonal
    count = 0;
    for (int j = 0; j < 4; j++)
    {
        if (board[j][3 - j] == player)
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    return false;
}
bool draw(char board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == '_')
            {
                return false;
            }
        }
    }
    return true;
}

char switching(char player)
{
    if (player == 'x')
    {
        return 'o';
    }
    else
    {
        return 'x';
    }
}

int main()
{
    char board[4][4], choose;
    do
    {
        bool gameOver = false;
        char player = 'x';
        initializeboard(board);
        while (gameOver == false)
        {
            displayboard(board);
            move(board, player);
            if (win(board, player))
            {
                displayboard(board);
                if (player == 'x')
                    cout << blue << "Player " << player << " wins" << normal << endl;
                else
                    cout << red << "Player " << player << " wins" << normal << endl;
                gameOver = true;
            }
            else if (draw(board))
            {
                displayboard(board);
                cout << yellow << "game draw" << normal << endl;
                gameOver = true;
            }
            else
            {
                player = switching(player);
            }

            cout << "Do you want to play again?y/n" << endl;
            cin >> choose;
            if (choose == 'n' || choose == 'N')
            {
                cout << endl;
                cout << yellow << "XO khalset, bas 3ayzeen el final grade ya bashmohandes :)" << normal << endl;
            }
        }
    } while (choose == 'y' || choose == 'Y');
    return 0;
}