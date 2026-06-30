#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <signal.h>		// Provides functions and constants for signal handling (e.g., kill, raise)

// signal container
extern volatile sig_atomic_t sigint_received;

// signal handler functions
int signal_close(void);
void signal_handler(int signum);
void setup_signals(void);

#endif