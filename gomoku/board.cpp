#include "board.h"

void draw_board() {
	setcolor(7);
	// print the letters and numbers
	gotoxy(3, 0);
	for (int i = 1; i <= 19; i++)
		printf("%4d", i);
	for (int i = 1; i <= 19; i++) {
		gotoxy(1, i + 1 * i);
		printf("%c", 'A' + i - 1);
	}

	// draw the actual board
	for (int i = 0; i < 39; i++) {
		gotoxy(3, i + 1);
		for (int j = 0; j < 77; j++)
		{
			if (i == 0 && j == 76) { printf("%c", 191); continue; }
			if (i == 38 && j == 0) { printf("%c", 192); continue; }
			if (i == 38 && j == 76) { printf("%c", 217); continue; }
			if (i == 0 && j == 0) { printf("%c", 218); continue; }
			if (j == 0 && i % 2 == 0)printf("%c", 195);
			else {
				if (j == 76 && i % 2 == 0)printf("%c", 180);
				else {
					if (i == 38 && j % 4 == 0)printf("%c", 193);
					else {
						if (i == 0 && j % 4 == 0)printf("%c", 194);
						else {
							if (i % 2 == 0) {
								if (j % 4 == 0)printf("%c", 197);
								else printf("%c", 196);
							}
							else {
								if (j % 4 == 0)printf("%c", 179);
								else printf(" ");
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
}

void reset_board(int board[30][30]){
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            board[i][j] = 0;
}
