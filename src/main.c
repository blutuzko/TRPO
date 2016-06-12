#include "../include/ceasar.h"
#include "../include/vizhiner.h"
#include "../include/atbash.h"
#include "../include/base64.h"

#include <unistd.h>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

#define FALSE 0
#define TRUE 1

int main(int argc, char * argv[])
{
  const char eng[28] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' , ',' , '.' };
  const char ENG[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
  char *a = NULL;
  FILE *fout = NULL;

  printf("Chipers\n");
  printf("1.Chiper ceasar\n");
  printf("2.Chiper Vizhiner\n");
  printf("3.Chiper Atbash\n");
  printf("4.Chiper Base64\n\n");

  int opt;

  int variant = 0, kluch = -1, lorr = 1, debug = 0;
  int flagword = FALSE;
  int flagkeyword = FALSE;
  char *word = NULL;
  char *keyword = NULL;

  opterr = 0;

  while ((opt = getopt(argc, argv, "cvabk:ldw:o:")) != -1) {
    switch (opt) {
      case 'c':
        if (variant == 0)
          variant = 1;
      break;

      case 'k':
        if (variant == 1)
          kluch = atoi(optarg);

        if (variant == 2) {
          keyword = optarg;
          flagkeyword = TRUE;
        }
      break;

      case 'v':
        if (variant == 0)
          variant = 2;
      break;

      case 'a':
        if (variant == 0)
          variant = 3;
      break;

      case 'b':
        if (variant == 0)
          variant = 4;
      break;

      case 'l':
        lorr = 0;
      break;

      case 'd':
        debug = 1;
      break;

      case 'w':
        word = optarg;
        flagword = TRUE;
      break;

      case 'o':
        fout = fopen(optarg, "a");
      break;
    }
  }

  switch (variant) {
    case ONE:
      a = ceasar(eng, ENG, kluch, lorr, debug, fout, &word);
      free(a);
    break;

    case TWO:
      a = vizhiner(eng, ENG, lorr, debug, fout, &word, &keyword);
      free(a);
    break;

    case THREE:
      a = atbash(eng, ENG, debug, fout, &word);
      free(a);
    break;

    case FOUR:
      a = BASE64(debug, fout, &word);
      free(a);
    break;

    default:
      printf("Miss chiper\n");
    break;
  }

  fcloseall();
  if (!(flagword)) {
    free(word);
  }

  if (!(flagkeyword)) {
    free(keyword);
  }
  return 0;
}
