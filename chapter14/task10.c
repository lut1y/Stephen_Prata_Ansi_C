#include <stdio.h>
#include <string.h>

float sum(float a, float b);
float sub(float a, float b);
float mul(float a, float b);
float div(float a, float b);
void show1(float (*fp)( float, float), float a, float b);

int task10(void) {
	float a, b;
	float (*pfun)(float, float);
	char ch;
	
	printf("Enter 1st operand: ");
	scanf("%f", &a);
	printf("Enter 2st operand: ");
	scanf("%f", &b);
	
	puts("Choice operation: ");
	puts("a) sum	c) sub");
	puts("c) mul	d) div");
	puts("q) exit");
	printf("Choice: ");
	
	while(getchar() != '\n') continue;
	ch = getchar();
	while(getchar() != '\n') continue;
	while(strchr("abcdq", ch) == NULL) {
		printf("Choice from \"abcdq\": ");
		ch = getchar();
	}
	
	switch(ch) {
		case 'a': pfun = sum; break;
		case 'b': pfun = sub; break;
		case 'c': pfun = mul; break;
		case 'd': pfun = div; break;
	}
	a = (*pfun)(a, b);
	
	printf("Result: %.2f\n", a);
	
	return 0;
}

float sum(float a, float b) {
	return a+b;
}
float sub(float a, float b) {
	return a - b;
}
float mul(float a, float b) {
	return a * b;
}
float div(float a, float b) {
	return a/b;
}
