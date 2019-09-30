#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iostream>

#include "menu.h"
#include "utils.h"
#include "board.h"

struct Player {
    char name[109];
    bool bot;
};

const WORD COLOR_X = 0x0C;
const WORD COLOR_O = 0x09;

int win_lose(int x, int y);
int draw(int board[30][30]);
void random_move(int &x, int &y, int board[30][30]);
int make_move(Player p1, Player p2, int x, int y, int &turn, int board[30][30]);
void PvP(Player p1, Player p2, int board[30][30]);
void PvE(Player p1, Player p2, int board[30][30]);
int win_lose(int x, int y, int board[30][30]);
void bot_move(int &x, int &y, int board_[30][30]);
int win_lose_without_COLOR(int x, int y, int board_[30][30]);

#endif
