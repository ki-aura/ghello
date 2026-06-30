#ifndef GHELLO_H
#define GHELLO_H

#include <sys/stat.h>		// Provides functions for retrieving and manipulating file status (e.g., stat, fstat)
//#include <glob.h>		// Provides pattern matching for filenames (pathname expansion)
//#include <regex.h>		// Provides functions for regular expression matching
#include <assert.h>		// Provides the assert macro for debugging and checking invariant conditions
#include <ctype.h>		// Provides functions for character classification (e.g., isalpha, isdigit) and conversion
#include <errno.h>		// Defines macros for reporting error conditions (e.g., errno, EACCES)
#include <fcntl.h>		// Provides file control functions (e.g., open, creat, file status flags)
#include <limits.h>		// Defines characteristics of integral types (e.g., INT_MAX, CHAR_BIT)
#include <ncurses.h>		// Provides functions for terminal-independent screen-handling and text-based UIs
#include <panel.h>		// Provides functions for stacking and manipulating ncurses windows as panels
#include <signal.h>		// Provides functions and constants for signal handling (e.g., kill, raise)
#include <stdarg.h>		// Provides support for functions with variable numbers of arguments (variadic functions)
#include <stdbool.h>		// Defines the boolean type bool and the macros true and false
#include <stdint.h>		// Defines exact-width integer types (e.g., int32_t, uint64_t)
#include <stdio.h>		// Provides standard input/output functions (e.g., printf, scanf, file I/O)
#include <stdlib.h>		// Provides general utilities (e.g., memory allocation, random numbers, process control)
#include <string.h>		// Provides functions for manipulating strings and memory blocks (e.g., strcpy, memcpy)
#include <sys/mman.h>		// Provides memory management declarations (e.g., mmap, munmap)
#include <unistd.h>		// Provides access to POSIX operating system API (e.g., fork, exec, read, close)

#define GHELLO_VERSION "1.2.1"  

// keys we need that aren't already defined by ncurses
#define KEY_MAC_ENTER 10	// KEY_ENTER already defined as send key for terminal


extern volatile sig_atomic_t sigint_received;
int final_close(void);

#endif
