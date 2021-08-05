// разнообразные классы хранения
#include <stdio.h>

void report_count();
void accumulate(int k);
int count = 0;	// область видимости в пределах файла, внешнее связывание

int parta(void) {
	int value;		// автоматическая переменная
	register int i;	// регистровая переменная
	
	printf("Enter positive integer number (0 for finishing): ");
	while(scanf("%d", &value) == 1 && value > 0) {
		++count; 	// использование переменной с областью видимости в перелах файлах
		for(i = value; i >= 0; i--)
			accumulate(i);
		printf("Enter positive integer number (0 for finishing): ");
	}
	report_count();
	
	return 0;
}

void report_count() {
	printf("Cycle completed %d once(s)\n", count);
}
