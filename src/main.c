#include "config.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char v;
_Bool server;

int main(int argc, char const* argv[])
{
  printf("[%s]\n", PACKAGE_STRING);
  for (int opt; opt != -1; opt = getopt(argc, argv, "sv")) {
    switch(opt) {

      case 'v': // Verbosity level
        v=(char)atoi(optarg);
        break;
      case 's':
        server = true; 
        break;
      case '?':
        // TODO: log here with stdout
        return 1;
    }
  }
  return 0;
}
