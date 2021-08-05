// использует циклы и рекурсию для вычисления факториалов
#include <stdio.h>

long fact(int n);
long rfact(int n);

int factor(void) {
	int num;
	
	printf("This is program calculate factorials.\n");
	printf("Enter values in range 0-12 ('q' for finishing):\n");
	while(scanf("%d", &num) == 1) {
		if(num<0)
			printf("Negative numbers is invalid.\n");
		else if(num>12)
			printf("Entered value must be lower 13.\n");
		else {
			printf("cycle: factorial %d = %ld\n",
				num, fact(num));
			printf("recursion: factorial %d = %ld\n",
				num, rfact(num));
		}
		printf("Enter values in range 0-12 ('q' for finishing):\n");
	}
	printf("Program is finished.\n");
	return 0;
}

long fact(int n) { // функция основанная на цикле
	long ans;
	
	for(ans = 1; n>1; n--) 
		ans *= n;
	return ans;	
}

long rfact(int n) { // рекурсивная версия
	long ans;
	
	if(n>0)
		ans = n * rfact(n-1);
	else
		ans = 1;
	return ans;
}
