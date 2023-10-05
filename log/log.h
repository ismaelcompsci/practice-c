#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef PROJECT_LOGGER
#define PROJECT_LOGGER

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

#define INFO 1
#define ERROR 2
#define DEBUG 3
#define SUCCESS 4

// extern int INFO_MODE;
// extern int ERROR_MODE;
// extern int DEBUG_MODE;
// extern int SUCCESS_MODE;

void logger(int, char *, ...);
void info(char *);
void success(char *);
void error(char *);
void debug(char *);

#endif