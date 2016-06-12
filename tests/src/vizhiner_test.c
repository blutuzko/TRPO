#include "../include/vizhiner_test.h"

extern const char *eng;
extern const char *ENG;

void VIZHTEST1()
{
  char *array = "abcdefghijk";
  char *onetestarray = "acceeggiikk";
  char *key = "ab";
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = vizhiner(eng, ENG, lorr, desh, t, &array, &key);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 1: success\n");
  }
  else {
    printf("VIZH TEST 1 : error\n");

  } 
}

void VIZHTEST2()
{
  char *array = "attackatdawn";
  char *onetestarray = "lxdopvedrnfr";
  char *key = "lemon";
  int lorr = 1;
  int desh = 0;
  FILE * t = fopen(".test","w");
  char *testarray = vizhiner(eng, ENG, lorr, desh, t, &array, &key);

  if (!(strcmp(onetestarray, testarray))) {
    printf("VIZH TEST 2: success\n");
  }
  else {
    printf("VIZH TEST 2 : error\n");

  } 
}

