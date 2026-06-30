#include "ghello.h"
#include "long_opt.h"
#include "signal_handler.h"
#include "mini_curses.h"

int main(int argc, char *argv[])
{
	// handle signal interrupts
	setup_signals();
	
	// parse options
	Options *opts = parse_options(argc, argv, NULL, true);		// no default operand required
	
	// run an ncurses / keyboard handler function
	WaitForKey();
	if(sigint_received) {return signal_close();}
	
	// run a standard print and wait
	for(int i = 0; i<opts->depth; i++) {
		printf("Hello World\n");
		}
	sleep(4);	// time to allow an interrupt to be tested
	
	// Final exit reports if closed successfully or by a signal
	return signal_close();
}
