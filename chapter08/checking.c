// проверка допустимости ввода
#include <stdio.h>
#include <stdbool.h>
// проверка, является ли ввод целочисленным
long get_long(void);
// проверка, допустимы ли границы диапозона
bool bad_limits(long begin, long end, 
				long low, long high);
// вычисление суммы квадратов целых чисел от a до b
double sum_squares(long a, long b);

int checking(void) {
	const long MIN = -10000000L; // нижний предел диапозона
	const long MAX = +10000000L; // верхний предел диапозона
	long start;
	long stop;
	double answer;
	
	printf("This is program calculate sums of squares "
		"decimal numbers in a given range.\nLow border don't must "
		"be lower -10000000, \na high border don't must be "
		"higher +10000000.\nEnter value of "
		"limits (for finishing enter 0 for both limits):\n"
		"low limit: ");
	start = get_long();
	printf("high limit: ");
	stop = get_long();
	while(start != 0 || stop != 0) {
		if(bad_limits(start, stop, MIN, MAX))
			printf("Try again.");
		else {
			answer = sum_squares(start, stop);
			printf("Sums squares decimal number ");
			printf("from %ld to %ld equals %g\n",
				start, stop, answer);
		}
		printf("Enter values of limits (for finishing "
			"enter 0 for both limits):\n");
		printf("low limit: ");
		start = get_long();
		printf("high limit: ");
		stop = get_long();
	}
	printf("Program is finished.\n");
	return 0;
}

long get_long(void) {
	long input;
	char ch;
	
	while(scanf("%ld", &input) != 1) {
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not decimal.\nEnter ");
		printf("decimal number, as 25, -178 or 3: ");
	}
	return input;
}

double sum_squares(long a, long b) {
	double total = 0;
	long i;
	
	for(i=a; i<=b; i++) 
		total += (double) i * (double) i;
	return total;
}

bool bad_limits(long begin, long end,
					long low, long high) {
	bool not_good = false;
	
	if(begin > end) {
		printf("%ld don't lower than %ld.\n", begin, end);
		not_good = true;
	}
	if(begin < low || end < low) {
		printf("Value must be equals %d or higher.\n", low);
		not_good = true;
	}
	if(begin > high || end > high) {
		printf("Value must be equals %d or lower.\n", high);
		not_good = true;
	}
	return not_good;
}
