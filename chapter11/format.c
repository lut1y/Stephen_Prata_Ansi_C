// форматирование строки sprintf()
#include <stdio.h>
#define MAX 20
char *s_gets(char *st, int n);

int format(void) {
	char first[MAX];
	char last[MAX];
	char formal[2*MAX+10];
	double prize;
	
	puts("Press your firstname: ");
	s_gets(first, MAX);
	puts("Press your lastname: ");
	s_gets(last, MAX);
	puts("Press sum money price: ");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);
	
	return 0;
}
