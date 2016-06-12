#include <stdio.h>
#include <string.h>

#include "../include/ceasar_test.h"
#include "../include/vizhiner_test.h"
#include "../include/atbash_test.h"

#define TESTS

 const char *eng = "abcdefghijklmnopqrstuvwxyz,.";
 const char *ENG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
  CEASTEST1();
  CEASTEST2();

  printf("\n\n");

  VIZHTEST1();
  VIZHTEST2();

  printf("\n\n");

  ATBATEST1();
  ATBATEST2();

  return 0;
}
