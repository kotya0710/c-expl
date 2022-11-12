#include <curses.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define gotoxy(x,y) move(y,x)

int main()
{
	WINDOW *w = initscr();
	if(!w)
	{
		printf("initscr returns NULL\n");
		goto exit;
	}

	printf("This string will apear after program exit.\n");

	start_color();
	if(!has_colors())
	{
		printf("has_colors returns FALSE\n");
		goto exit;
	}

	const int cpi = 1; // 0 reserved so use 1
	init_pair(cpi, COLOR_BLUE, COLOR_WHITE);
	attrset(COLOR_PAIR(cpi));
	mvprintw(1, 1, "Available number of color pairs: %i", COLOR_PAIRS);

	int rows, cols;
	getmaxyx(w, rows, cols);
	mvprintw(2, 1, "Dimentions: %ix%i", cols, rows);

	noecho();
	keypad(w, TRUE); // allows non-character keys
	curs_set(FALSE); // hides cursor

	int ch = 0;
	while(ch != 'q')
	{
		ch = getch();
		mvprintw(3, 2, "You pressed 0x%x ", ch);
		mvprintw(4, 2, "& KEY_CODE_YES: %s ", (ch & KEY_CODE_YES)
			? "TRUE" : "FALSE");
	}

	clear();
	printw("Wait...");
	refresh(); // esential to use refresh before nap
	napms(3000);

	exit:
	if(w)
	{
		delwin(w);
		endwin();
		refresh();
	}
	return 0;
}
