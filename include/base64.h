#ifndef BASE64_H
#define BASE64_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

	void B64Encode(unsigned char in[3], int len, unsigned char out[4]);
	unsigned int getB64Index(unsigned char c);
	int B64Decode(unsigned char in[4], unsigned char out[3]);
	char *BASE64(int desh, FILE * fout, char ** test);

#endif
