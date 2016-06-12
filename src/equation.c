 #include "discriminant.h"
 #include "equation.h"
 #include <math.h>
 // Функция вычисления корней квадратного уравнения
 // Принимает на вход целые значение коэффициентов
 // и указатель на массив длины два.
 // Возвращает целое число-флаг, которое показывает
 // количество корней квадратного уравнения.
 // 0 - нет корней; 1 - один корень; 
 // 2 - два корня; 3 - бесконечно много корней.  
 
 int equation(int a, int b, int c, float root[])
 {
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				return 3;
			}
			return 0;
		}
		root[0] = -c/b;
		return 1;
	}
	else {
		float d = discriminant(a,b,c);
		if (d == -1) {
			return 0;
		}
		if (d == 0) {
			root[0] = -b/(2 * a);
			return 1;
		}
		root[0] = (-b - sqrt(d))/(2 * a);
		root[1] = (-b + sqrt(d))/(2 * a);
		return 2;
	}
 }
