// использование оператора break для выхода из цикла
#include <stdio.h>

int break_(void) {
	float length, width;
	
	printf("Enter length rectangle:\n");
	while(scanf("%f", &length) == 1) {
		printf("Length = %0.2f:\n", length);
		printf("Enter width rectangle:\n");
		if(scanf("%f", &width) != 1)
			break;
		printf("Width = %0.2f:\n", width);
		printf("Square = %0.2f:\n", length * width);
		printf("Enter length rectangle:\n");
	}
	printf("Programm is finished!");
	return 0;
}
