// неэффективное и чреватое ошибками угадывание числа
#include <stdio.h>

int guess(void) {
	int guess = 1;
	char response;
	
	printf("Choice decimal number in range from 1 to 100. I try guess ");
	printf("this.\nPress key y, if my guess is true and ");
	printf("\nkey 'n' in otherwise.\n");
	printf("Your number is %d?\n", guess);
	while((response = getchar()) != 'y') {
		if(response == 'n')
			printf("Okay, then it is %d?\n", ++guess);
		else
			printf("Accepted only options 'y' or 'n'.\n");
		while(getchar() != '\n') continue; // пропускаем оставшуюся часть строки
	}
	printf("I knew, that I will successed!\n");
	return 0;
}
