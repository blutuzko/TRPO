#ifndef CEASAR_H
#define CEASAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ceasar(const char *eng, const char *ENG, int ceas,
            int lorr, int desh, FILE * fout, char ** word);

#endif
