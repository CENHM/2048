//
// Created by CENHM on 2021/12/8.
//

#ifndef INC_2048_MY_2048_H
#define INC_2048_MY_2048_H

#include "ctime"
#include "windows.h"
#include "iostream"

using namespace std;

int points;

void add_random(int b[4][4], int);
void show_board(int b[4][4]);
void dir_o_move(int b[4][4]);

int game_close(int b[4][4]);
int check_2048(int b[4][4]);
void end_judge(int judge);

void move_u(int b[4][4]);
void move_l(int b[4][4]);
void move_d(int b[4][4]);
void move_r(int b[4][4]);

int c(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
    return 0;
}

int game_close(int board[4][4])
{
    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if(i > 0 && board[i - 1][j] == board[i][j] ||
               i < 3 && board[i + 1][j] == board[i][j] ||
               j > 0 && board[i][j - 1] == board[i][j] ||
               j < 3 && board[i][j + 1] == board[i][j] ||
               board[i][j] == 0) return 0;
    return 2;
}

int check_2048(int board[4][4])
{

    for (int i = 0; i < 4; ++ i)
        for (int j = 0; j < 4; ++ j)
            if (board[i][j] == 2048)
                return 1;
    return 0;
}

void show_board(int board[4][4])
{
    cout << "Hello, 2048!" << endl;
    cout << endl;
    for (int i = 0; i < 4; ++ i)
    {
        for (int j = 0; j < 4; ++ j)
        {
            c(6); if(board[i][j] == 0) c(14);
            printf("%4d ", board[i][j]);

        }
        cout << endl;
    }
    cout << endl;
    cout << "current points : " << points << endl;
    cout << endl;
    cout << "Please input W/A/S/D : ";
}

void add_random(int board[4][4], int n)
{
    int c = 0;
    for (int i = 0; i <= n; ++ i)
    {
        int random = rand() % 16;
        if (board[random / 4][random % 4] == 0)
        {
            if (rand() % 10 == 0 || rand() % 10 == 1)
                board[random / 4][random % 4] = 4;
            else
                board[random / 4][random % 4] = 2;
        }
        else
        {
            -- i, ++ c;
            if(c == 100) break;
        }
    }
}

void dir_o_move(int board[4][4])
{
    char dir;
    scanf("%c", &dir);
    switch (dir)
    {
        case 'W': move_u(board); break;
        case 'A': move_l(board); break;
        case 'S': move_d(board); break;
        case 'D': move_r(board); break;
        default: printf("!!!!"); break;
    }
    scanf("%c", &dir);
}

void end_judge(int judge)
{
    if(judge == 1)
    {
        printf("\nCongratulation!\n");
    }
    else
    {
        printf("\nOops!Try again!\n");
    }
}

void move_u(int b[4][4])
{
    for(int i = 0; i < 4; ++ i)
    {
        int c = 0;
        int a[4] = {0, 0, 0, 0};
        for(int j = 0; j < 4; ++ j)
        {
            if(b[j][i]) a[c ++] = b[j][i];
            if(c > 1 && a[c - 1] == a[c - 2])
            {
                a[c - 2] *= 2;
                points += a[c - 1];
                a[c - 1] = 0;
            }
            else if(c > 1 && !a[c - 2])
            {
                a[c - 2] = a[c - 1];
                a[c - 1] = 0;
            }
        }
        for(int j = 0; j < 4; ++ j)
            b[j][i] = a[j];
    }
}

void move_d(int b[4][4])
{
    for(int i = 0; i < 4; ++ i)
    {
        int c = 0;
        int a[4] = {0, 0, 0, 0};
        for(int j = 3; j >= 0; -- j)
        {
            if(b[j][i]) a[c ++] = b[j][i];
            if(c > 1 && a[c - 1] == a[c - 2])
            {
                a[c - 2] *= 2;
                points += a[c - 1];
                a[c - 1] = 0;
            }
            else if(c > 1 && !a[c - 2])
            {
                a[c - 2] = a[c - 1];
                a[c - 1] = 0;
            }
        }
        for(int j = 3, k = 0; j >= 0; -- j, ++ k)
            b[j][i] = a[k];
    }
}

void move_l(int b[4][4])
{
    for(int i = 0; i < 4; ++ i)
    {
        int c = 0;
        int a[4] = {0, 0, 0, 0};
        for(int j = 0; j < 4; ++ j)
        {
            if(b[i][j]) a[c ++] = b[i][j];
            if(c > 1 && a[c - 1] == a[c - 2])
            {
                a[c - 2] *= 2;
                points += a[c - 1];
                a[c - 1] = 0;
            }
            else if(c > 1 && !a[c - 2])
            {
                a[c - 2] = a[c - 1];
                a[c - 1] = 0;
            }
        }
        for(int j = 0; j < 4; ++ j)
            b[i][j] = a[j];
    }
}

void move_r(int b[4][4])
{
    for(int i = 0; i < 4; ++ i)
    {
        int c = 0;
        int a[4] = {0, 0, 0, 0};
        for(int j = 3; j >= 0; -- j)
        {
            if(b[i][j]) a[c ++] = b[i][j];
            if(c > 1 && a[c - 1] == a[c - 2])
            {
                a[c - 2] *= 2;
                points += a[c - 1];
                a[c - 1] = 0;
            }
            else if(c > 1 && !a[c - 2])
            {
                a[c - 2] = a[c - 1];
                a[c - 1] = 0;
            }
        }
        for(int j = 3, k = 0; j >= 0; -- j, ++ k)
            b[i][j] = a[k];
    }
}

#endif //INC_2048_MY_2048_H
