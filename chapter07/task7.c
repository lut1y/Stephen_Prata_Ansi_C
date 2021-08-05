#include <stdio.h>
#define BASEPAY 10.00
#define BASEHRS 40
#define OVERTIME 1.5
#define	BREAK1 300
#define BREAK2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int task7(void) {
	int hours;
	float pay, tax, pure_pay;
	
	printf("Enter count hours when do you job: ");
	scanf("%d", &hours);
	
	if(hours <= BASEHRS) {
		pay = BASEPAY * hours;	
	} else {
		pay = BASEPAY * BASEHRS + OVERTIME * BASEPAY * (hours - BASEHRS);
	}
	if(pay <= BREAK1) {
		tax = pay * RATE1;
	} else if (pay <= BREAK2) {
		tax = BREAK1 * RATE1 + (pay - BREAK1) * RATE2; 
	  } else {
	  	tax =  BREAK1 * RATE1 + BREAK2 * RATE2 + (pay - (BREAK1 + BREAK2)) * RATE3;
	  	}
	pure_pay = pay - tax;
	printf("Total:\n\t-common pay: $%.2f\n\t-tax: $%.2f\n\t-pure pay: $%.2f",
		pay, tax, pure_pay);
		
	return 0;
}
