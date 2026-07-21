#include <ncurses.h>
#include <locale.h>
#include <termios.h>
#include <unistd.h>
#include "signal_handler.h"
#include "mini_curses.h"

void WaitForKey(void) { 
	int ch;
	printf("\nDebug: Started WaitForKey\n");

	// Initialize the ncurses screen
	setlocale(LC_ALL, ""); // Required for wide characters with ncurses
	initscr();
	cbreak();		  // Line buffering disabled. Pass everything to the program
	noecho();		  // Do not echo input characters to the screen
	keypad(stdscr, TRUE); // Enable special keys like F1, arrow keys, etc.

	// PATCH to stop signal blocking: Set a 100ms timeout so getch() becomes non-blocking 
	// and returns ERR rather than waiting indefinitely.
	timeout(100);
	
	// flush any chars already in the buffer
	tcflush(STDIN_FILENO, TCIFLUSH);

	// main function
	printw("curses control \n");
	mvprintw(3,1,"Press x to continue.\n");
	refresh();
		
	while ((ch = getch()) != 'x' && ch != 'X') { 
		// sigint_received is set async - check for signal
		if(sigint_received) {
			break; 
		}

		if(ch != ERR){ // this ignores signals or any other non-keys
			mvprintw(5,1,"You pressed: %d      \n", ch);
		}
		
		refresh();
	}

	// Clean up ncurses
	endwin();

	return;
}

