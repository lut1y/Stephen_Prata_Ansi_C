#include <stdio.h>

int task5(void) {
	int low = 0,
		high = 100, 
		guess = (low + high) / 2;
	char response;
	
	printf("Choice decimal number in range from 1 to 100. I try guess ");
	printf("this.\nPress key y, if my guess is true and ");
	printf("\nkey 'l' if number lower and 'h' if number higher.\n");
	printf("Your number is %d?\n", guess);
	while((response = getchar()) != 'y') {
		if(response == 'l') {
			high = guess;
			printf("Okay, then it is %d?\n", guess = (low + high) / 2);
		} else if(response == 'h') {
			low = guess;
			printf("Okay, then it is %d?\n", guess = (low + high) / 2);
			   } else
					printf("Accepted only options 'y' or 'l' or 'h'.\n");
		while(getchar() != '\n') continue; // пропускаем оставшуюся часть строки
	}
	printf("I knew, that I will successed!\n");
	return 0;
}
