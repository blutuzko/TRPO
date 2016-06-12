#include "../include/ceasar_test.h"

extern const char *eng;
extern const char *ENG;

void CEASTEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = "cdefghijklm";
  int ceas = 2;          
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, t, &array);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 1: success\n");
  }
  else {
    printf("CEAS TEST 1 : error\n");
  } 
}

void CEASTEST2()
{
  char *array = "word";
  char *onetestarray = "ey.n";
  int ceas = 10;          
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = ceasar(eng, ENG, ceas, lorr, desh, t, &array);

  if (!(strcmp(onetestarray, testarray))) {
    printf("CEAS TEST 2: success\n");
  }
  else {
    printf("CEAS TEST 2 : error\n");
  } 
}

