#include "menu.h"
#include"utils.h"

void inchuCARO(int x, int y) {
    int t = 219;
    int v = 220;
    int u = 223;
    gotoxy(x, y);
    printf("%c%c%c%c%c%c     %c%c%c     %c%c%c%c     %c%c%c%c   \n", v, t, u, u, u, v, v, u, v, t, u, u, v, v, u, u, v);
    gotoxy(x, y + 1);
    printf("%c         %c   %c    %c  %c%c   %c    %c        \n", t, t, t, t, v, u, t, t);
    gotoxy(x, y + 2);
    printf("%c         %c%c%c%c%c    %c%c%c%c    %c    %c       \n", t, t, u, u, u, t, t, u, u, v, t, t);
    gotoxy(x, y + 3);
    printf("%c%c%c%c%c%c    %c   %c    %c   %c%c   %c%c%c%c     \n", u, t, v, v, v, u, t, t, t, u, v, u, v, v, u);

}

void oden(int x, int y) //Tab vao
{
    gotoxy(x, y);
    printf("\t\t\t\t\t\t");
    gotoxy(x, y + 1);
    printf("\t\t\t\t\t\t");
    gotoxy(x, y + 2);
    printf("\t\t\t\t\t\t");
    gotoxy(x, y + 3);
    printf("\t\t\t\t\t\t");
}

void khungtinh(int x, int y)
{
    int u = 179, v = 196;
    int i, j, k, l;
    for (i = x + 1; i <= x + 60; i++)
    {
        gotoxy(i, y);
        printf("%c", v);
    }
    printf("%c", 197);
    for (j = y; j <= y + 9; j++)
    {
        gotoxy(i, j + 1);
        printf("%c", u);
    }
    gotoxy(i, j);
    printf("%c", 197);
    for (k = i - 1; k >= x + 1; k--)
    {
        gotoxy(k, j);
        printf("%c", v);
    }
    gotoxy(k, j);
    printf("%c", 197);
    for (l = j - 1; l > y; l--)
    {
        gotoxy(x, l);
        printf("%c", u);
    }
    gotoxy(x, l);
    printf("%c", 197);
}

void khung(int x, int y)
{
    int u = 179, v = 196;
    int i, j, k, l;
    for (i = x + 1; i <= x + 60; i++)
    {
        gotoxy(i, y);
        printf("%c", v);
        Sleep(10);
        if (_kbhit())
        {
            khungtinh(x, y);
            return;
        }
    }
    printf("%c", 197);
    for (j = y; j <= y + 9; j++)
    {
        gotoxy(i, j + 1);
        printf("%c", u);
        Sleep(10);
        if (_kbhit())
        {
            khungtinh(x, y);
            return;
        }
    }
    gotoxy(i, j);
    printf("%c", 197);
    for (k = i - 1; k >= x + 1; k--)
    {
        gotoxy(k, j);
        printf("%c", v);
        Sleep(10);
        if (_kbhit())
        {
            khungtinh(x, y);
            return;
        }
    }
    gotoxy(k, j);
    printf("%c", 197);
    for (l = j - 1; l > y; l--)
    {
        gotoxy(x, l);
        printf("%c", u);
        Sleep(10);
        if (_kbhit())
        {
            khungtinh(x, y);
            return;
        }
    }
    gotoxy(x, l);
    printf("%c", 197);
}


void carovakhung()//re la lan lap hien chu va khung
{
    resize_console(1200, 710);
    InChu A;
    A.x = 60;
    A.y = 15;
    A.mau = 7;
    int x = A.x;
    while (1)
    {
        clrscr();
        ancontro();
        setcolor(A.mau);
        inchuCARO(A.x, A.y);
        if (x <= 90)
            oden(x, A.y);
        else
            break;
        x++;
        A.mau++;
        if (A.mau == 16)
            A.mau = 7;
        Sleep(70);
        if (_kbhit())
        {
            _getch();
            return;
        }
    }
    while (1)
    {
        setcolor(A.mau);
        inchuCARO(A.x, A.y);
        khung(A.x - 15, A.y - 4);
        A.mau++;
        if (A.mau == 16)
            A.mau = 7;
        if (_kbhit())
        {
            _getch();
            setcolor(14);
            inchuCARO(A.x, A.y);
            khungtinh(A.x - 15, A.y - 4);
            break;
        }
    }
}


void print_mode(int x, int y) {
    gotoxy(x, y);
    printf("       1. PvP             \n");
    gotoxy(x, y + 1);
    printf("       2. PvE             \n");
    gotoxy(x, y + 2);
    printf("       3. Help            \n");
    gotoxy(x, y + 3);
    printf("       4. Exit              ");
    gotoxy(arrow_begin_x + 4, arrow_begin_y);
}

void menu_gameplay(int &N, int x, int y) { //N Tra ve 1: PvP, 2: PvE, 0: Exit   
    system("cls");
    ancontro();
    int color = 8;
    //carovakhung();
    setcolor(14);
    inchuCARO(60, 15);
    khungtinh(45, 11);
    authors(100, 35);
    gotoxy(arrow_begin_x, arrow_begin_y);
    print_mode(x, y);
    setcolor(206);
    printf(">>     1. PvP      <<");
    int mode = 1;
    while (1) {
        while (1)
        {
            setcolor(color);
            khungtinh(45, 11);
            inchuCARO(60, 15);
            if (_kbhit())
                break;
            Sleep(40);
            color++;
            if (color == 16)
                color = 8;
        }
        setcolor(14);
        char k = _getch();
        if (k == 'w' || k == 0x48) {
            mode += 3;
        }
        if (k == 's' || k == 0x50) {
            mode += 1;
        }
        if (k == 13) { //Enter
            N = mode % 4;
            break;
        }
        print_mode(x, y);
        setcolor(206);
        gotoxy(arrow_begin_x + 4, (mode - 1) % 4 + arrow_begin_y);
        if (mode % 4 == 1)
            printf(">>     1. PvP      <<");
        else if (mode % 4 == 2)
            printf(">>     2. PvE      <<");
        else if (mode % 4 == 3)
            printf(">>     3. Help     <<");
        else if (mode % 4 == 0)
            printf(">>     4. Exit     <<");
        ancontro();
    }
}


void authors(int x, int y) {
    gotoxy(x, y);
    printf("Authors");
    gotoxy(x, y+1);
    printf("1. Tran Quang Khai");
    gotoxy(x, y+2);
    printf("2. Nguyen Phuc Khang");
    gotoxy(x, y+3);
    printf("3. Nguyen Minh Quan");
    gotoxy(x, y+4);
    printf("4. Phan Gia Hao");
}


void goodbye(){
    system("cls");
    setcolor(14);
    inchuCARO(60, 10);
    khungtinh(45, 6);
    gotoxy(65, 20);
    printf("SEE YOU NEXT TIME!");
    _getch();
}

void guide()
{
    system("cls");
    setcolor(14);
    inchuCARO(60, 10);
    khungtinh(45, 6);
    gotoxy(0, 20);
    printf("\
- Tro choi Caro la mot tro choi 2 nguoi tren ban co co kich thuoc 19x19 o.\n\
- Quan co cua 2 nguoi choi duoc the hien bang cac ki tu X va O.\n\
- Hai nguoi choi lan luot dat cac quan co vao cac o con trong tren ban co\n\
  (dung cac phim 'w' 's' 'a' 'd' hoac cac phim mui ten de di chuyen, space de dat co).\n\
- Nguoi thang van co la nguoi dat duoc 5 quan co xep thanh theo hang doc,\n\
  hang ngang hoac duong cheo nhung khong bi chan hai dau boi doi thu.\n\n\n");
    wait("return to menu");
}

int end_session(){
    system("cls");
    setcolor(14);
    inchuCARO(60, 10);
    khungtinh(45, 6);
    gotoxy(60,20);
    wait("return to menu");
    return 0;
}

void logoWIN(int x, int y)
{
    // system("cls");
    ancontro();
    x -= 5;
    gotoxy(x, y);
    printf("%c%c            %c%c            %c%c   %c%c%c%c%c%c   %c%c          %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 1);
    printf(" %c%c          %c%c%c%c          %c%c      %c%c     %c%c%c%c        %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 2);
    printf("  %c%c        %c%c  %c%c        %c%c       %c%c     %c%c%c%c%c%c      %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 3);
    printf("   %c%c      %c%c    %c%c      %c%c        %c%c     %c%c  %c%c%c%c    %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 4);
    printf("    %c%c    %c%c      %c%c    %c%c         %c%c     %c%c    %c%c%c%c  %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 5);
    printf("     %c%c  %c%c        %c%c  %c%c          %c%c     %c%c      %c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 6);
    printf("      %c%c%c%c          %c%c%c%c           %c%c     %c%c        %c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    gotoxy(x, y + 7);
    printf("       %c%c            %c%c          %c%c%c%c%c%c   %c%c          %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    _getch();
}
void logoLOSE(int x, int y)
{
    // system("cls");
	ancontro();
	gotoxy(x, y);
	printf("%c%c              %c%c%c%c          %c%c%c%c        %c%c%c%c%c%c%c%c", 219, 219, 220, 219, 219, 220, 220, 219, 219, 220, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(x, y + 1);
	printf("%c%c            %c%c%c  %c%c%c      %c%c%c  %c%c%c      %c%c      ", 219, 219, 220, 219, 223, 223, 219, 220, 220, 219, 223, 223, 219, 220, 219, 219);
	gotoxy(x, y + 2);
	printf("%c%c           %c%c      %c%c     %c%c%c           %c%c      ", 219, 219, 219, 219, 219, 219, 223, 219, 220, 219, 219);
	gotoxy(x, y + 3);
	printf("%c%c           %c%c      %c%c       %c%c%c         %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 223, 219, 220, 219, 219, 220, 220, 220, 220, 220, 220);
	gotoxy(x, y + 4);
	printf("%c%c           %c%c      %c%c         %c%c%c       %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 223, 219, 220, 219, 219, 223, 223, 223, 223, 223, 223);
	gotoxy(x, y + 5);
	printf("%c%c           %c%c      %c%c           %c%c%c     %c%c      ", 219, 219, 219, 219, 219, 219, 223, 219, 220, 219, 219);
	gotoxy(x, y + 6);
	printf("%c%c            %c%c%c  %c%c%c       %c%c%c  %c%c%c     %c%c      ", 219, 219, 223, 219, 220, 220, 219, 223, 223, 219, 220, 220, 219, 223, 219, 219);
	gotoxy(x, y + 7);
	printf("%c%c%c%c%c%c%c%c        %c%c%c%c           %c%c%c%c       %c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 223, 219, 219, 223, 223, 219, 219, 223, 219, 219, 219, 219, 219, 219, 219, 219);
    _getch();
}
