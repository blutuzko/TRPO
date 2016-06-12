#include "../include/atbash_test.h"

extern const char *eng;
extern const char *ENG;

void ATBATEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = ".,zyxwvutsr";
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = atbash(eng, ENG, desh, t, &array);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 1: success\n");
  }
  else {
    printf("ATBA TEST 1 : error\n");

  } 
}

void ATBATEST2()
{
  char *array = "word";
  char *onetestarray = "fnky";
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = atbash(eng, ENG, desh, t, &array);

  if (!(strcmp(onetestarray, testarray))) {
    printf("ATBA TEST 2: success\n");
  }
  else {
    printf("ATBA TEST 2 : error\n");

  } 
}

