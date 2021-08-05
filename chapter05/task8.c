#include <stdio.h>

int task8(void) {
	int first, second;
	
	printf("This program calculate results of divide for module.\n");
	printf("Enter decimal number, that will be second operand: ");
	scanf("%d", &second);
	printf("And now enter first operand: ");
	scanf("%d", &first);
		
	while(first>0) {
		printf("%d %% %d equals %d", first, second, first % second);
		printf("\n\nEnter next number for first operand(<=0 for exit): ");
		scanf("%d", &first);
	}
	printf("Ready!");
	
	return 0;
}
