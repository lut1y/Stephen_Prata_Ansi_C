#include <stdio.h>
#define ALONG 17850
#define HEAD_OF_FAMILY 23900
#define MARRIED_JOINT_HK 29750
#define MARRIED_SEPARATED_HK 14850
#define START_TAX .15
#define EXTRA_TAX .28

void menu_(void);
void calc_wage_(unsigned int start_income);

int task10(void) {
	char choice;			
	unsigned int start_income;
	
	menu_();
	
	while((choice = getchar()) != '5') {	
		if('\n' == choice) continue;
		switch (choice) {
			case '1':
				start_income = ALONG;				
				break;
			case '2':
				start_income = HEAD_OF_FAMILY;				
				break;
			case '3':
				start_income = MARRIED_JOINT_HK;				
				break;
			case '4':
				start_income = MARRIED_SEPARATED_HK;				
				break;		
			case '5':
				printf("Have a nice day!\n");
				return 0;
			default:
				printf("Choice must be 1-5!\n");
				choice = '0';
		}
		if(choice != '0') calc_wage_(start_income);		
		
		menu_();
		while(getchar() != '\n') continue;
	}
	printf("Have a nice day!\n");
	return 0;
}

void menu_(void) {
	printf("******************************************************************\n");
	printf("Enter number, corresponding to category or action:\n");
	printf("1) along\t\t\t2) head of family\n");
	printf("3) married_joint_housekeeping\t4) married_separated_housekeeping\n");
	printf("5) exit\n");
	printf("******************************************************************\n");
	printf("Choice: ");
}

void calc_wage_(unsigned int start_income) { // считаем ЗП (ДД), налоги и чистую ЗП(ДД)
	unsigned int income;
	float tax, pure_income;
	
	printf("Enter sum of income: ");
		scanf("%d", &income);
		
		if(income <= start_income)
			tax = income * START_TAX;
		else {
			tax = start_income * START_TAX + (income - start_income) * EXTRA_TAX;
		}
			 
		pure_income = income - tax;
		printf("Total:\n\t-common pay: $%d\n\t-tax: $%.2f\n\t-pure pay: $%.2f\n",
			income, tax, pure_income);
}
