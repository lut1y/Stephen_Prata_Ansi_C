#include <stdio.h>
#include <ctype.h>

char get_choice1(void);
char get_first1(void);
float get_float(void);

int task8(void) {
	int choice;
	float a, b;
	
	while((choice = get_choice1()) != 'q') {
		switch(choice) {
			case 'a':
				printf("Enter first operand: ");
				a = get_float();
				printf("Enter second operand: ");
				b = get_float();
				printf("%g + %g = %g\n", a, b, a + b);
				break;
			case 's':
				printf("Enter first operand: ");
				a = get_float();
				printf("Enter second operand: ");
				b = get_float();
				printf("%g - %g = %g\n", a, b, a - b);
				break;
			case 'm':
				printf("Enter first operand: ");
				a = get_float();
				printf("Enter second operand: ");
				b = get_float();
				printf("%g * %g = %g\n", a, b, a * b);
				break;
			case 'd':
				printf("Enter first operand: ");
				a = get_float();
				printf("Enter second operand: ");
				b = get_float();
				while(b==0) {
					printf("Error! Don't divide on zero! Enter othe number: ");
					b = get_float();
				}
				printf("%g / %g = %g\n", a, b, a / b);
				break;
			default:
				printf("Error!\n");				
		}
	}
	printf("Program is finished.\n");
	return 0;
}

char get_choice1(void) {
	int ch;
	printf("Select option:\n");
	printf("a. addition\t\ts. subtraction\n");
	printf("m. mutiplication\td. division\n");
	printf("q. quit\n");
	ch = get_first1();
	while(ch != 'a' && ch != 's' && ch != 'm' &&
		ch != 'd' && ch != 'q') {
		printf("Please enter 'a', 's', 'm', 'd' or 'q': ");
		ch = get_first1();
	}
}

char get_first1(void) {
	int ch;
	
	ch = getchar();
	while(isspace(ch)) {
		ch = getchar();
		continue;
	}
	while(getchar() != '\n') continue;
	return ch;
}

float get_float(void) {
	float a;
	char ch;
	
	while(scanf("%f", &a) != 1) {
		while((ch = getchar())!= '\n') 
			putchar(ch);
		printf(" is not number.\nEnter ");
		printf("number, as 2.5, -1.7E8 or 3: ");
	}
}
