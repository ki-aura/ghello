#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <signal.h>		// Provides functions and constants for signal handling (e.g., kill, raise)

// --------------------------------------------------------------
	//Put this first thing in main
	//setup_signals();
	
	//Put this final thing in main 
	//return signal_exit();
	
	// **** MODIFY signal_close() if you need to do more clear up
// --------------------------------------------------------------


// signal container
extern volatile sig_atomic_t sigint_received;

// signal handler functions
void setup_signals(void);
void signal_handler(int signum);

// example of a close function (with no additional clean up)
int signal_exit(void);

#endif