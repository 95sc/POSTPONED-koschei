#ifndef MODULE_H
#define MODULE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define START_SYM "app_start"
#define END_SYM "app_end"

typedef struct {
  FILE *config;
  unsigned char verbosity;
  _Bool server;
} proc_state_t;

// Function pointer aliases

typedef int startfunc_t(proc_state_t *);
typedef int endfunc_t(void);

int app_start(proc_state_t *);
int app_end(void);

#endif
