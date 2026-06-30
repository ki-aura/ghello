#include <ncurses.h>
#include <locale.h>
#include "signal_handler.h"


void WaitForKey() {
	setlocale(LC_ALL, ""); // Required for wide characters with ncurses

	// Initialize the ncurses screen
	initscr();
	cbreak();		  // Line buffering disabled. Pass everything to the program
	noecho();		  // Do not echo input characters to the screen
	keypad(stdscr, TRUE); // Enable special keys like F1, arrow keys, etc.

	printw("Press x to continue.\n");
	refresh();
	
	// PATCH to stop signal blocking: Set a 100ms timeout so getch() becomes non-blocking 
	// and returns ERR rather than waiting indefinitely.
	timeout(100);
	
	int ch;
	while ((ch = getch()) != 'x') { 
		// PATCH: Filter out the ERR return to avoid printing "-1"
		if (ch == ERR) {
			if(sigint_received) {
				break;
			}
			continue;
		}
		printw("You pressed: %d\n", ch);
		refresh();
	}

	// Clean up ncurses
	endwin();

	return;
}

