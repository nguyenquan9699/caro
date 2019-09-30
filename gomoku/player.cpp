#include "player.h"

void logoX(int x, int y, Player p, bool in_turn = true)
{
    if(in_turn){
        gotoxy(x - 5, y - 3);
        printf("Luot nguoi choi : %s%20c ", p.name, ' ');
    }
    setcolor(COLOR_X);
    gotoxy(x, y);
    printf("%c%c    %c%c", 223, 220, 220, 223);
    gotoxy(x, y + 1);
    printf("  %c%c%c%c  ", 223, 220, 220, 223);
    gotoxy(x, y + 2);
    printf("  %c%c%c%c  ", 220, 223, 223, 220);
    gotoxy(x, y + 3);
    printf("%c%c    %c%c", 220, 223, 223, 220);
}

void logoO(int x, int y, Player p, bool in_turn = true)
{
    if(in_turn){
        gotoxy(x - 5, y - 3);
        printf("Luot nguoi choi : %s%20c ", p.name,' ');
    }
    setcolor(COLOR_O);
    gotoxy(x, y);
    printf("  %c%c%c%c  ", 220, 223, 223, 220);
    gotoxy(x, y + 1);
    printf(" %c    %c ", 219, 219);
    gotoxy(x, y + 2);
    printf(" %c    %c ", 219, 219);
    gotoxy(x, y + 3);
    printf("  %c%c%c%c  ", 223, 220, 220, 223);
}

void random_move(int &x, int &y, int board[30][30]) {
    srand(time(0));
    x = rand() % 19;
    y = rand() % 19;
    while (board[x][y] != 0) {
        x = rand() % 19;
        y = rand() % 19;
    }
    // board[x][y] = -1;
}

int make_move(Player p1, Player p2, int x, int y, int &turn, int board[30][30]) {
    WORD color;
    // gotoxy(80, 4);
    // printf("%d %d - %d", x, y, board[(x - 5) / 4][(y - 2) / 2]);
    if (p2.bot == false && board[(x - 5) / 4][(y - 2) / 2] != 0) return 0;
    board[(x - 5) / 4][(y - 2) / 2] = (turn++ % 2 == 0) ? 1 : -1;
    if (board[(x - 5) / 4][(y - 2) / 2] == 1)
    {
        print_color("X", COLOR_X);
        logoO(90, 5, p2);
        color = COLOR_X;
    }
    if (board[(x - 5) / 4][(y - 2) / 2] == -1)
    {
        if(p2.bot == false) print_color("O", COLOR_O);
        logoX(90, 5, p1);
        color = COLOR_O;
    }
    if (win_lose(x, y, board) == 1)
    {
        system("cls");
        setcolor(color);
		if (p2.bot == true){
            setcolor(COLOR_X);
            if(turn % 2 == 0) logoLOSE(50, 15);
            else logoWIN(50, 15);
        }else{
            if(turn % 2 == 0) logoO(35, 17, p2, false);
            else logoX(35, 17, p1, false);
            logoWIN(55, 15);
        }
        return 1;
    }
    if (draw(board) == 1) {
        system("cls");
        printf("DRAW"); return 1;
    }
    return 0;
}

void PvP(Player p1, Player p2, int board[30][30]) {
    srand(time(0));
    int x = 5, y = 2, turn = ((rand() % 100) >= 50) ? 1 : 0;
    if(turn % 2 == 0) logoX(90, 5, p1);
    else logoO(90, 5, p2);
    gotoxy(5, 2);
    while (1) {
        int key_pressed = 0, finish = 0;
        Player p_turn = (turn % 2 == 0) ? p1 : p2;
        key_pressed = _getch();
        if (key_pressed == 0x4B || key_pressed == 'a') x -= 4;  // left
        if (key_pressed == 0x4D || key_pressed == 'd') x += 4;  // right
        if (key_pressed == 0x48 || key_pressed == 'w') y -= 2;  // up
        if (key_pressed == 0x50 || key_pressed == 's') y += 2;  // down
        if (key_pressed == ' ') finish = make_move(p1, p2, x, y, turn, board);
        x = min(5 + 4 * 18, x); x = max(5, x);
        y = min(2 + 2 * 18, y); y = max(2, y);
        gotoxy(x, y);
        if (key_pressed == 27) break;
        if(finish) break;
    }
}

void PvE(Player p1, Player p2, int board[30][30]) {
    srand(time(0));
    int x = 5, y = 2, turn = ((rand() % 100) >= 50) ? 1 : 0;
    if(turn % 2 == 0) logoX(90, 5, p1);
    else{
        logoO(90, 5, p2);
        x = (7 + rand() % 6) * 4 + 5;
        y = (7 + rand() % 6) * 2 + 2;
    }
    gotoxy(x, y);
    while (1) {
        int key_pressed = 0, finish = 0;
        Player p_turn = (turn % 2 == 0) ? p1 : p2;
        if (p_turn.bot == false) {
            key_pressed = _getch();
            if (key_pressed == 0x4B || key_pressed == 'a') x -= 4;  // left
            if (key_pressed == 0x4D || key_pressed == 'd') x += 4;  // right
            if (key_pressed == 0x48 || key_pressed == 'w') y -= 2;  // up
            if (key_pressed == 0x50 || key_pressed == 's') y += 2;  // down
            if (key_pressed == ' ') finish = make_move(p1, p2, x, y, turn, board);
            x = min(5 + 4 * 18, x); x = max(5, x);
            y = min(2 + 2 * 18, y); y = max(2, y);
            gotoxy(x, y);
        }else{
            bot_move(x,y,board);
            finish = make_move(p1, p2, x, y, turn, board);
            gotoxy(x, y);
        }
        gotoxy(x, y);
        if (key_pressed == 27) break;
        if(finish) break;
        // ==========================================
        // int key_pressed = _getch();
        // if (key_pressed == 0x4B || key_pressed == 'a') x -= 4;   // left
        // if (key_pressed == 0x4D || key_pressed == 'd') x += 4;   // right
        // if (key_pressed == 0x48 || key_pressed == 'w') y -= 2;   // up
        // if (key_pressed == 0x50 || key_pressed == 's') y += 2;   // down
        // if (key_pressed == ' ') {
        //  if (board_[(x - 5) / 4][(y - 2) / 2] != 0) continue;
        //  board_[(x - 5) / 4][(y - 2) / 2] = 1;
        //  // In quan co
        //  print_color("X", COLOR_X);
        //  bot_move(x, y);
        //  // Xet thang chua
        //  if (win_lose(x, y, board)) {
        //      gotoxy(x + 1, y + 1);
        //      return;
        //  }
        // }
        // if (key_pressed == 27) break;
        // x = min(5 + 4 * 18, x); x = max(5, x);
        // y = min(2 + 2 * 18, y); y = max(2, y);
        // gotoxy(x, y);
    }
}

void bot_move(int &x, int &y, int board_[30][30]) {
    // Vung co the nguy hiem
    int X = (x - 5) / 4;
    int Y = (y - 2) / 2;
    int zone_U, zone_D, zone_L, zone_R;
	zone_R = (X + 6); if (zone_R > 18) zone_R = 18;
	zone_L = (X - 6); if (zone_L > 0) zone_L = 0;
    zone_U = (Y - 6); if (zone_U < 0) zone_U = 0;
	zone_D = (Y + 6); if (zone_D > 18) zone_D = 18;
    // Tan cong danh 1 con la thang
    for (int a = 0; a <= 18; a++)
        for (int b = 0; b <= 18; b++) {
            if (board_[a][b] != 0) continue;
            // Gia su
            board_[a][b] = -1;
            if (win_lose(a * 4 + 5, b * 2 + 2, board_)) {
                x = a * 4 + 5; y = b * 2 + 2;
                gotoxy(x, y); print_color('O', COLOR_O);
                return;
            }
            board_[a][b] = 0;
        }
    // Phong thu khi nguoi choi danh 1 con la thang
    for (int a = zone_L; a <= zone_R; a++)
        for (int b = zone_U; b <= zone_D; b++) {
            if (board_[a][b] != 0) continue;
            // Gia su
            board_[a][b] = 1;
            if (win_lose(a * 4 + 5, b * 2 + 2, board_)) {
                x = a * 4 + 5; y = b * 2 + 2;
                gotoxy(x, y); print_color('O', COLOR_O);
                board_[a][b] = -1;
                return;
            }
            board_[a][b] = 0;
        }
    // Tan cong danh 2 con la thang
    for (int a = 0; a <= 18; a++)
        for (int b = 0; b <= 18; b++) {
            if (board_[a][b] != 0) continue;
            board_[a][b] = -1;
            for (int c = 0; c <= 18; c++)
                for (int d = 0; d <= 18; d++) {
                    if (board_[c][d] != 0) continue;
                    board_[c][d] = -1;
                    if (win_lose(c * 4 + 5, d * 2 + 2, board_)) {
                        x = c * 4 + 5; y = d * 2 + 2;
                        gotoxy(x, y); print_color('O', COLOR_O);
                        board_[a][b] = 0;
                        return;
                    }
                    board_[c][d] = 0;
                }
            board_[a][b] = 0;
        }
    // Phong thu khi nguoi choi danh 2 con la thang
    for (int a = zone_L; a <= zone_R; a++)
        for (int b = zone_U; b <= zone_D; b++) {
            if (board_[a][b] != 0) continue;
            // Gia su
            board_[a][b] = 1;
            for (int c = zone_L; c <= zone_R; c++)
                for (int d = zone_U; d <= zone_D; d++) {
                    if (board_[c][d] != 0) continue;
                    board_[c][d] = 1;
                    if (win_lose(c * 4 + 5, d * 2 + 2, board_)) {
                        x = c * 4 + 5; y = d * 2 + 2;
                        gotoxy(x, y); print_color('O', COLOR_O);
                        board_[c][d] = -1;
                        board_[a][b] = 0;
                        return;
                    }
                    board_[c][d] = 0;
                }
            board_[a][b] = 0;
        }
    // Tan cong khi danh 3 con la thang
    for (int a = 0; a <= 18; a++)
        for (int b = 0; b <= 18; b++) {
            if (board_[a][b] != 0) continue;
            board_[a][b] = -1;
            for (int c = 0; c <= 18; c++)
                for (int d = 0; d <= 18; d++) {
                    if (board_[c][d] != 0) continue;
                    board_[c][d] = -1;
                    for (int e = 0; e <= 18; e++)
                        for (int f = 0; f <= 18; f++) {
                            if (board_[e][f] != 0) continue;
                            board_[e][f] = -1;
                            if (win_lose(e * 4 + 5, f * 2 + 2, board_)) {
                                x = e * 4 + 5; y = f * 2 + 2;
                                gotoxy(x, y); print_color('O', COLOR_O);
                                board_[a][b] = 0; board_[c][d] = 0;
                                return;
                            }
                            board_[e][f] = 0;
                        }
                    board_[c][d] = 0;
                }
            board_[a][b] = 0;
        }
    // Phong thu khi nguoi choi danh 3 con la thang
    for (int a = zone_L; a <= zone_R; a++)
        for (int b = zone_U; b <= zone_D; b++) {
            if (board_[a][b] != 0) continue;
            // Gia su
            board_[a][b] = 1;
            for (int c = zone_L; c <= zone_R; c++)
                for (int d = zone_U; d <= zone_D; d++) {
                    if (board_[c][d] != 0) continue;
                    board_[c][d] = 1;
                    for (int e = zone_L; e <= zone_R; e++)
                        for (int f = zone_U; f <= zone_D; f++) {
                            if (board_[e][f] != 0) continue;
                            board_[e][f] = 1;
                            if (win_lose(e * 4 + 5, f * 2 + 2, board_)) {
                                x = e * 4 + 5; y = f * 2 + 2;
                                gotoxy(x, y); print_color('O', COLOR_O);
                                board_[c][d] = 0; board_[a][b] = 0; board_[e][f] = -1;
                                return;
                            }
                            board_[e][f] = 0;
                        }
                    board_[c][d] = 0;
                }
            board_[a][b] = 0;
        }
    // Danh thong thuong
    x += 4; y += 2; // Thuong danh xeo tot hon
    while (1) {
		x %= 76;
		y %= 38;
        if (board_[(x - 5) / 4][(y - 2) / 2] != 0) {
            x += 4;
            continue;
        }
        board_[(x - 5) / 4][(y - 2) / 2] = -1; gotoxy(x, y);
        print_color('O', COLOR_O);
        return;
    }
}

int win_lose(int x, int y, int board[30][30])
{
    x = (x - 5) / 4;
    y = (y - 2) / 2;
    // kiem tra cot doc
    float win = 1;
    for (int i = x - 1; i >= 0; i--) {
        if (board[i][y] == board[x][y]) win++;
        else {
            if (board[i][y] == 0)break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    for (int i = x + 1; i < 19; i++) {
        if (board[i][y] == board[x][y]) win++;
        else {
            if (board[i][y] == 0)break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    if (win >4)  return 1;
    else win = 1;
    // kiem tra hang ngang
    for (int i = y - 1; i >= 0; i--) {
        if (board[x][i] == board[x][y]) win++;
        else {
            if (board[x][i] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    for (int i = y + 1; i < 19; i++) {
        if (board[x][i] == board[x][y]) win++;
        else {
            if (board[x][i] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    if (win >4)return 1;
    else win = 1;
    // kiem tra cheo cheo chinh
    for (int i = x - 1; i >= 0; i--)
    {
        int j = y + x - i;
        if (board[i][j] == board[x][y]) win++;
        else {
            if (board[i][j] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    for (int i = x + 1; i < 19; i++)
    {
        int j = y - i + x;
        if (board[i][j] == board[x][y]) win++;
        else {
            if (board[i][j] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    if (win >4) return 1;
    else win = 1;
    // kiem tra cheo phu
    for (int i = x + 1; i < 19; i++)
    {
        int j = y + i - x;
        if (board[i][j] == board[x][y]) win++;
        else {
            if (board[i][j] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    for (int i = x - 1; i >= 0; i--)
    {
        int j = y - x + i;
        if (board[i][j] == board[x][y]) win++;
        else {
            if (board[i][j] == 0) break;
            else
            {
                win -= 0.5;
                break;
            }
        }
    }
    if (win >4) return 1;
    return 0;
}

int draw(int board[30][30])
{
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            if (board[i][j] == 0) return 0;
    return 1;
}
