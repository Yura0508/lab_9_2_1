// lab_9_2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996)
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define z 5

#define SQR(p) (p)*(p) // макрос з параметром – визначення квадрата числа
// макрос визначення найбільшого з двох чисел
#define MAX(p,u) ((p)>(u))?(p):(u) // макрос як умовний вираз
#define ABS(p) ((p) >= 0 ? (p) : -(p)) // модуль
#define SQRT(p) (sqrt(ABS(p)))  //корінь числа
#define ADD(a, b) ((a) + (b)) 
#define SUB(a, b) ((a) - (b)) 
#define MUL(a, b) ((a) * (b)) 

// виведення повідомлення та значення цілого числа
#define PRINTI(w) puts("control output"); \
printf(#w"=%d\n",w)
// використовується символ продовження макроса '\'
// символ '#' використовується для об’єднання рядків
// виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts ("rezult :"); \
printf (#w"=%f\n",(float)w)


void main()
{
	int x, y, w, dod, sub, mul, xy, yz, zx, max1, max2,
		n_kvadr,
		maxmin,
		modul, modul1, modul2,
	    max_kvadr;
	int corin;
	char ch;
	do
	{
#if z>3 // якщо умова істинна,
		puts("define maximum of two numbers");
		puts("Input 2 integer numbers");
		PRINTI(z);
		scanf("%d", &x);// введення числа
		PRINTI(x); // макрос виведення числа
		scanf("%d", &y);
		PRINTI(y);

		corin = SQRT(x);
		PRINTI(corin);
		
		// w = max((x - z)^2, x - y)
		n_kvadr = SQR(SUB(x, z)); // (x - z)^2
		PRINTI(n_kvadr);

		sub = SUB(x, y); //  (x - y)
		PRINTI(sub);

		w = MAX(n_kvadr, sub); //  (x - z)^2 ? (x - y)
		PRINTI(w);
		modul = ABS(w);
		PRINTI(modul);
#else // компілювати іншу частину програми

		puts("define maximum of two numbers");
		puts("Input 2 integer numbers");
		PRINTI(z);
		scanf("%d", &x);// введення числа
		PRINTI(x); // макрос виведення числа
		scanf("%d", &y);
		PRINTI(y);
		
		corin = SQRT(x);
		PRINTI(corin);

		// w = max(xy, yz) + max(zx, yz)
		 xy = MUL(x, y); //  x * y
		 yz = MUL(y, z); //  y * z
		 zx = MUL(z, x); //  z * x

		PRINTI(xy);
		PRINTI(yz);
		PRINTI(zx);

		 max1 = MAX(xy, yz);
		 max2 = MAX(zx, yz);

		PRINTI(max1);
		modul1 = ABS(max1);
		PRINTI(modul1);

		PRINTI(max2);
		modul2 = ABS(max2);
		PRINTI(modul2);

		w = ADD(max1, max2); //  max(xy, yz) + max(zx, yz)
		PRINTI(w);


#endif // завершення блоку умовної компіляції
		puts("Repeat? y /n "); ch = getch();
	} while (ch == 'y');
}


