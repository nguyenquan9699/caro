#ifndef _MENU_H_
#define _MENU_H_

#include <stdio.h>
#include <cstring>
#include <conio.h>
#include <Windows.h>

#include "player.h"

#define name_max 50
// arrow_begin_y = chose_begin_y , arrow_begin_x = chose_begin_x - 4
#define arrow_begin_x 60 // Toa do x bat dau ve mui ten
#define arrow_begin_y 25  // Toa do y bat dau ve mui ten
#define chose_begin_x 64 // Toa do x bat dau liet ke lua chon
#define chose_begin_y 25 // Toa do y bat dau liet ke lua chon

struct InChu
{
	int x, y, mau;
};

void inchuCARO(int x, int y);
void oden(int x, int y);
void khung(int x, int y);
void khungtinh(int x, int y);
void carovakhung();
void print_mode(int x, int y);
void menu_gameplay(int &N, int x, int y);
void authors(int x, int y);
void goodbye();
void guide();
int end_session();
void logoWIN(int x, int y);
void logoLOSE(int x, int y);

// int menu(Player&, Player&);

#endif
