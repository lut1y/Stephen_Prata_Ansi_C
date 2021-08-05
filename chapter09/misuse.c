// неправильное использование функции
#include <stdio.h>
int imax();		/* объ€вление в старом стиле */

int misuse(void) {
	printf("Higher value from  %d and %d is %d.\n",
		3, 5, imax(3));
	printf("Higher value from  %d and %d is %d.\n",
		3, 5, imax(3.0, 5.0));	
	return 0;
}

int imax(n, m)
int n, m;
{
	return (n > m ? n : m);
}
