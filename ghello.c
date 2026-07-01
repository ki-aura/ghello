#include "ghello.h"
#include "long_opt.h"
#include "signal_handler.h"
#include "mini_curses.h"

static void print_opts(Options *opts){
	// Print parsed options
	printf("Parsed Options:\n");
	printf("  quiet:	%d\n", opts->quiet);
	printf("  depth:	%d\n", opts->depth);
	printf("  iterate:  %s\n", opts->iterate ? "true" : "false");
	printf("  pattern:  \"%s\"\n", opts->pattern? opts->pattern : "(not set)");
	printf("  verbose:  %s\n", opts->verbose ? "true" : "false");
	printf("  woo:	  %s\n", opts->woo ? "true" : "false");

	printf("\nExcludes (%d):\n", opts->exclude_count);
	for (int i = 0; i < opts->exclude_count; i++) {
		printf("  [%d] \"%s\"\n", i, opts->excludes[i]);
	}
	printf("\nOperands (%d):\n", opts->operand_count);
	for (int i = 0; i < opts->operand_count; i++) {
		printf("  [%d] \"%s\"\n", i, opts->operands[i]);
	}
}


int main(int argc, char *argv[])
{
	// handle signal interrupts
	setup_signals();
	
	// parse options
	Options *opts = parse_options(argc, argv, NULL, true);		// no default operand required
	print_opts(opts); int hw = opts->depth;
	free_options(opts);
	
	// run a standard print and wait
	for(int i = 0; i<hw; i++) {
		printf("Hello  World\n");
		}
	sleep(4);	// time to allow an interrupt to be tested

	// run an ncurses / keyboard handler function
	WaitForKey();
	if(sigint_received) {return signal_close();}
	
	// Final exit reports if closed successfully or by a signal
	return signal_close();
}
