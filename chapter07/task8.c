#include <stdio.h>
#include <ctype.h>
#define BASEPAY1 8.75
#define BASEPAY2 9.33
#define BASEPAY3 10.00
#define BASEPAY4 11.20
#define BASEHRS 40
#define OVERTIME 1.5
#define	BREAK1 300
#define BREAK2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

void menu(void);
void calc_wage(float basepay);
unsigned short check_right_choice(void);

int task8(void) {
	char choice;			
	float basepay;
	
	menu();
	
	while((choice = getchar()) != '5') {
		if(isspace(choice)) continue;	
		switch (choice) {
			case 'a':
				basepay = BASEPAY1;				
				break;
			case 'b':
				basepay = BASEPAY2;				
				break;
			case 'c':
				basepay = BASEPAY3;				
				break;
			case 'd':
				basepay = BASEPAY4;				
				break;		
			case 'q':
				printf("Have a nice day!\n");
				return 0;
			default:
				printf("Choice must be 'a', 'b', 'c' or 'd'!\n");
				choice = '0';
		}
		if(choice != '0') calc_wage(basepay);		
		
		menu();
		while(getchar() != '\n') continue;
	}
	printf("Have a nice day!\n");
	return 0;
}

void menu(void) {
	printf("******************************************************************\n");
	printf("Enter number, corresponding to the desired tariff rate or action:\n");
	printf("a) $8.75/h			b) $9.33/h\n");
	printf("c) $10.00/h			d) $11.20/h\n");
	printf("q) Exit\n");
	printf("******************************************************************\n");
	printf("Choice: ");
}

void calc_wage(float basepay) { // считаем ЗП (ДД), налоги и чистую ЗП(ДД)
	int hours;
	float pay, tax, pure_pay;
	
	printf("Enter count hours when do you job: ");
		scanf("%d", &hours);
		
		if(hours <= BASEHRS) {
			pay = basepay * hours;	
		} else {
			pay = basepay * BASEHRS + OVERTIME * basepay * (hours - BASEHRS);
		}
		if(pay <= BREAK1) {
			tax = pay * RATE1;
		} else if (pay <= BREAK2) {
			tax = BREAK1 * RATE1 + (pay - BREAK1) * RATE2; 
		  } else {
		  	tax =  BREAK1 * RATE1 + BREAK2 * RATE2 + (pay - (BREAK1 + BREAK2)) * RATE3;
		  	}
		pure_pay = pay - tax;
		printf("Total:\n\t-common pay: $%.2f\n\t-tax: $%.2f\n\t-pure pay: $%.2f\n",
			pay, tax, pure_pay);
}
