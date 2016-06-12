#include "../include/vizhiner.h"

char *vizhiner(const char *eng, const char *ENG,
              int lorr, int desh, FILE * fout, char ** word, char ** keyword)
{
  int i, j, o, lenght = 0, klenght = 0, vvod = 1, mas = 1;

  if (*word == NULL) {
    *word = (char*)malloc(sizeof(word));

    printf("\nOriginal word :");

    while (vvod) {
      scanf("%c", &(*word)[lenght]);

      if ((*word)[lenght] == '\n') {
        (*word)[lenght] = '\0';
        break;
      }

      *word = (char *)realloc(*word, ++lenght+1);
    }
  }
  else {
    lenght = strlen(*word);
  }

  if (*keyword == NULL) {
    *keyword = (char *)malloc(sizeof(char *));

    printf("\nEnter keyword :");

    while (vvod) {
      scanf("%c", &(*keyword)[klenght]);

      if ((*keyword)[klenght] == '\n') {
        (*keyword)[klenght] = '\0';
        break;
      }

      *keyword = (char *)realloc(*keyword, ++klenght+1);
    }
  }
  else {
    klenght = strlen(*keyword);
  }

  int *ceas;
  ceas = (int *)malloc(klenght * sizeof(int));

  int flag = 0;

  char *codeword = (char *)malloc(lenght * sizeof(char *));

  o = 0;
  for (i = 0; i < lenght; i++) {
    flag = 0;
    if((*word)[i] == ' ') {
      codeword[i] = ' ';
      continue;
    }

    if (o == klenght) {
      o = 0;
      mas = 0;
    }

    if (mas == 1) {
      for (j = 0; j < 28; j++) {
        if(((*keyword)[o] == eng[j]) || ((*keyword)[o] == ENG[j])) {
          ceas[o] = j;
          break;
        }
      }
    }

    for (j = 0; j < 28; j++) {
      if ((*word)[i] == eng[j]) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 27) + (desh == 1) * ((j - ceas[o]) < 0)) {
            codeword[i] = eng[(desh == 0) * (j + ceas[o] - 28) + (desh == 1) * (j - ceas[o] + 28)];
            flag = 1;
            break;
          }
          else {
            codeword[i] = eng[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])];
            flag = 1;
            break;
          }
        }

        if (lorr == 0) {
          if ((desh == 0) * ((j-ceas[o]) < 0 ) + (desh == 1)*((j+ceas[o]) > 27)) {
            codeword[i] = eng[(desh == 0) * (j - ceas[o] + 28) + (desh == 1) * (j + ceas[o] - 28)];
            flag = 1;
            break;
          }
          else {
            codeword[i] = eng[(desh ==0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])];
            flag = 1;
            break;
          }
        }
      }

      if (((*word)[i] == ENG[j]) && (j <= 25)) {
        if (lorr == 1) {
          if ((desh == 0) * ((j + ceas[o]) > 25) + (desh == 1) * ((j - ceas[o]) < 0)) {
            codeword[i] = ENG[(desh == 0) * (j + ceas[o] - 26) + (desh == 1) * (j - ceas[o] + 26)];
            flag = 1;
            break;
          }
          else {
            codeword[i] = ENG[(desh == 0) * (j + ceas[o]) + (desh == 1) * (j - ceas[o])];
            flag = 1;
            break;
          }
        }

        if (lorr == 0) {
          if((desh == 0) * ((j - ceas[o]) < 0) + (desh == 1) * ((j + ceas[o]) > 25)) {
            codeword[i] = ENG[(desh == 0) * (j - ceas[o] + 26) + (desh == 1) * (j + ceas[o] - 26)];
            flag = 1;
            break;
          }
          else {
            codeword[i] = ENG[(desh == 0) * (j - ceas[o]) + (desh == 1) * (j + ceas[o])];
            flag = 1;
            break;
          }
        }
      }
    }

    o++;

    if (flag == 0) {
      codeword[i] = (*word)[i];
    }
  }

  if (fout == NULL) {
    printf("Vizhiner\n\n");
    if (desh == 1)
      printf("!--Decoding--!\n\n");
    printf("word: %s\n\n", *word);
    printf("keyword: %s\n\n", *keyword);
    printf("rezult: %s\n", codeword);
    printf("\n\n");
  }
  else {
    fprintf(fout, "Vizhiner\n\n");
    if (desh == 1)
      fprintf(fout, "!--Decoding--!\n\n");
    fprintf(fout, "word: %s\n\n", *word);
    fprintf(fout, "keyword: %s\n\n", *keyword);
    fprintf(fout, "rezult: %s\n", codeword);
    fprintf(fout,"\n\n");
  }

  free(ceas);
  
  return codeword;
}
