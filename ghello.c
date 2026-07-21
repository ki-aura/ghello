#include <unistd.h>		// Provides access to POSIX operating system API (e.g., fork, exec, read, close)
#include <stdio.h>		// Provides standard input/output functions (e.g., printf, scanf, file I/O)
#include <stdlib.h>		// Provides exit functions

#include "ghello.h"
#include "long_opt.h"
#include "signal_handler.h"
#include "mini_curses.h"

static int close_gracefully(Options *opts){
	// does any clean up required (e.g. free) and force closes
	free_options(opts);
	exit(signal_exit());
	return 0;
}

int main(int argc, char *argv[])
{
	// handle signal interrupts
	setup_signals();
	
	// parse options
	Options *opts = parse_options(argc, argv, NULL, true);		// no default operand required
	print_opts(opts);
	
	// run a standard print and wait
	for(int i = 0; i<opts->depth; i++) {
		printf("Hello  World!\n");
		}
	sleep(4);	// time to allow an interrupt to be tested
	if(sigint_received) {return close_gracefully(opts);}

	// run an ncurses / keyboard handler function
	WaitForKey();
	if(sigint_received) {return close_gracefully(opts);}
	
	// do whatever else
	// etc...
	
	// Finally close down
	return close_gracefully(opts);
}
