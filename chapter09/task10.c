#include <stdio.h>

void to_base_n(unsigned long, unsigned short);

int task10(void) {
	unsigned long number;
	unsigned short ns, status;
	
	printf("Enter integer number and numerical system ('q' for finishing):\n");
	while((status = scanf("%lu %hd", &number, &ns)) != 2 || 
		(ns < 2 || ns > 10)) {
		if(status != 2)
			scanf("%*s");	// отбрасывание нецелочисленного ввода
		printf("Enter numerical system from 2 to 10.\n");
	}
	printf("In numerical system %hd number equals ", ns);
	to_base_n(number, ns);
	putchar('\n');
	
	printf("Program is finished.\n");	
	return 0;
}

void to_base_n(unsigned long number, unsigned short ns) {
	int r;
	
	r = number % ns;
	if(number >=ns) to_base_n(number/ns, ns);
	switch(r) {
		case 0: 
			putchar('0');
			break;
		case 1: 
			putchar('1');
			break;
		case 2: 
			putchar('2');
			break;
		case 3: 
			putchar('3');
			break;
		case 4: 
			putchar('4');
			break;
		case 5: 
			putchar('5');
			break;
		case 6: 
			putchar('6');
			break;
		case 7: 
			putchar('7');
			break;
		case 8: 
			putchar('8');
			break;
		case 9: 
			putchar('9');
			break;
	}
	return;
}
