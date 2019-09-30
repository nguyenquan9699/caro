#ifndef _BOARD_H_
#define _BOARD_H_

#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

#include "utils.h"

const WORD BOARD_BLACK  = 0x00;
const WORD BOARD_WHITE  = 0xF0;

const WORD OUTLINE      = 0x0A;

void draw_board();
void reset_board(int board[30][30]);

#endif
