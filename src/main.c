#include "config.h"
#include <ltdl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "module.h"

proc_state_t state = {.config = NULL, .verbosity = 127, .server = false};

int main(int argc, char const *argv[]) {
  printf("[%s]\n", PACKAGE_STRING);

  /* SET OPTIONS */
  int opt;
  while ((opt = getopt(argc, (char *const *)argv, ":vc:s")) != -1) {
    switch (opt) {

    case 'v': // Verbosity level
      state.verbosity = (char)atoi(optarg);
      break;
    case 's':
      state.server = true;
      break;
    case 'c':
      // TODO: fopen config
      break;
    case ':':
      // TODO: log
      return 1;
    case '?':
      // TODO: log here with stderr
      return 1;
    }
  }

  /* START PROCESS */

  // Dynamically load client/server from user opt
  // TODO: Check if client/server is disabled from user config
  int ltdl;
  lt_dlhandle app;
  startfunc_t *start_fp = 0;

  LTDL_SET_PRELOADED_SYMBOLS();

  ltdl = lt_dlinit();
  if (ltdl) {
    return 1;
  }
  // TODO: Log/error out

  const char *path = state.server ? "./app_types/server/server.la"
                                  : "./app_types/client/client.la";

  app = lt_dlopen("modules/server/server.la");
  if (app == 0) {
    return 1;
  }
  // TODO: Log/error out

  start_fp = (startfunc_t *)lt_dlsym(app, START_SYM);

  if (start_fp == 0) {
    return 1;
  }
  // TODO: Log/error out

  if (start_fp(&state))
    printf("Loaded!\n");

  lt_dlclose(app);
  lt_dlexit();

  return 0;
}
