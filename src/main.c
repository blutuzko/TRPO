 #include "discriminant.h"
 #include "equation.h"
 #include <math.h>
 #include <stdio.h>
 int equation(int a, int b, int c, float root[]);
 
int main() {
	int a, b, c;
	float root[1];
	
	printf("Input a, b, c:");
	scanf("%d %d %d", &a, &b, &c);
	int flg = equation(a, b, c, root);
	if (flg == 3) {
		printf("The equation has infinite roots.");
	}
	if (flg == 2) {
		printf("The equation has two roots: %.2f and %.2f", root[0], root[1]);
	}
	if (flg == 1) {
		printf("The equation has one root: %.2f", root[0]);
	}
	if (flg == 0) {
		printf("The equation has no roots");
	}
 }
