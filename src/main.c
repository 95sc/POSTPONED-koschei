#include "config.h"
#include <stdio.h>
#include <stdbool.h>
#include "libkosdb.h"
#include "libkoslog.h"

int main(int argc, char const* argv[])
{
  printf("[%s]\n", PACKAGE_STRING);
  if(db_test() && log_test())
    printf("Hello, libraries!\n");
  return 0;
}
