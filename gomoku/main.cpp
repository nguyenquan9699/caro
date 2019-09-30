#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#include "menu.h"
#include "utils.h"
#include "player.h"
#include "board.h"

int board[30][30] = {};
Player p1, p2;

int main(){
    int N;
    atexit(goodbye);
    resize_console(1100, 710);
    carovakhung();
    while(1){
        do
        {
            menu_gameplay(N, chose_begin_x, chose_begin_y);
            if (N == 3)
                guide();
        } while (N == 3);

        if (N == 0) {
            return 0;
        }

        if (N == 1) 
        {
            system("cls");
            inchuCARO(60, 10);
            khungtinh(45, 6);
            hiencontro();
            gotoxy(50, 18);
            printf("Mode: PvP ");
            gotoxy(50, 19);
            printf("Enter the first player's name: ");
            gets_s(p1.name, 109);
            p1.bot = false;
            gotoxy(50, 20);
            printf("Enter the second player's name: ");
            gets_s(p2.name, 109);
            p2.bot = false;
        }
        if (N == 2)
        {
            system("cls");
            inchuCARO(60, 10);
            khungtinh(45, 6);
            hiencontro();
            gotoxy(50, 18);
            printf("Mode: PvE ");
            gotoxy(50, 19);
            printf("Enter your username: ");
            gets_s(p1.name, 109);
            p1.bot = false;
            strcpy_s(p2.name, "BOT");
            p2.bot = true;
        }

        system("cls");
        inchuCARO(60, 10);
        khungtinh(45, 6);
        gotoxy(50, 18);
        printf("Player 1: %30s - X",p1.name);
        gotoxy(50, 19);
        printf("Player 2: %30s - O\n",p2.name);
        gotoxy(50, 21);
        wait("start");
        
        system("cls");
        reset_board(board);
        draw_board();
        hiencontro();
        if(N == 1) PvP(p1, p2, board);
        else PvE(p1, p2, board);
        if(end_session()) break;
        system("cls");
        // wait("continue");
    }
    return 0;
}
