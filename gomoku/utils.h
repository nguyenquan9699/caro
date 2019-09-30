#ifndef _UTILS_H_
#define _UTILS_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <Windows.h>

const WORD DEFAULT = 0x07;

void resize_console(int, int);
void gotoxy(int,int);
void setcolor(WORD);
void print_color(const char*, WORD);
void print_color(char, WORD);
void wait(const char*);
void ancontro();
void hiencontro();
void clrscr();

#endif
