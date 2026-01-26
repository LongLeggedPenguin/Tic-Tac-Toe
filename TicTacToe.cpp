#include <iostream>
using namespace std;

char GameBoard[3][3];
char CharacterTurn = 'X';

void TicTacToe();
void OutputBoard();
void ChangeCharacterTurn();
bool CheckForWin(char Character);

int main()
{
    TicTacToe();
    return 0;
}

void TicTacToe()
{
    while (true)
    {
        OutputBoard();

        // CHECKS FOR WIN
        if (CheckForWin('X'))
        {
            for (int i = 0; i < 10; i++)
            {
                cout << " " << endl;
            }

            cout << "=================================" << endl;
            cout << " " << endl;
            cout << "X HAS WON THE GAME!!!" << endl;
            cout << " " << endl;
            cout << "=================================" << endl;
            exit(0);
        }
        else if (CheckForWin('O'))
        {

            for (int i = 0; i < 10; i++)
            {
                cout << " " << endl;
            }
            cout << "=================================" << endl;
            cout << " " << endl;
            cout << "O HAS WON THE GAME!!!" << endl;
            cout << " " << endl;
            cout << "=================================" << endl;
            exit(0);
        }

        int NumberPosition;
        cout << "Where would you like to place your piece? (You are " << CharacterTurn << " ): ";
        cin >> NumberPosition;

        int Row = (NumberPosition - 1) / 3;
        int Square = (NumberPosition - 1) % 3;

        GameBoard[Row][Square] = CharacterTurn;
        ChangeCharacterTurn();

        if (!NumberPosition)
        {
            cout << "Sorry there was an error. Exiting program.";
            exit(-1);
        };
    }
}

void OutputBoard()
{

    for (int i = 0; i < 10; i++)
    {
        cout << " " << endl;
    }

    int Number = 1;
    for (int Row = 0; Row < 3; Row++)
    {
        for (int Square = 0; Square < 3; Square++)
        {
            if (GameBoard[Row][Square] == 'X' || GameBoard[Row][Square] == 'O')
            {
                cout << " " << GameBoard[Row][Square] << " ";
            }
            else
            {
                cout << " " << Number << " ";
            }
            if (Square < 2)
            {
                cout << "|";
            }

            Number++;
        }

        cout << endl;
        if (Row < 2)
        {
            cout << "===========";
            cout << endl;
        }
    }
}

void ChangeCharacterTurn()
{
    if (CharacterTurn == 'X')
    {
        CharacterTurn = 'O';
    }
    else
    {
        CharacterTurn = 'X';
    }
}

bool CheckForWin(char Character)
{
    for (int Row = 0; Row < 3; Row++)
    { // Check for across
        if (GameBoard[Row][0] == Character && GameBoard[Row][1] == Character && GameBoard[Row][2] == Character)
        {
            return true;
        }

        for (int Square = 0; Square < 3; Square++)
        { // Check for straight down
            if (GameBoard[Row][Square] == Character && GameBoard[Row + 1][Square] == Character && GameBoard[Row + 2][Square] == Character)
            {
                return true;
            }
        }
    }

    if (GameBoard[0][0] == Character && GameBoard[1][1] == Character && GameBoard[2][2] == Character)
    {
        return true;
    }

    if (GameBoard[0][2] == Character && GameBoard[1][1] == Character && GameBoard[2][0] == Character)
    {
        return true;
    }

    // Nobody won
    return false;
    cout << "A";
}

