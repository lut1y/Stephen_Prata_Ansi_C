#include <stdio.h>
#include <ctype.h>

void product_menu(void);

int task11(void) {
	const float ARTICHOKE_LB = 2.05; // артишоки
	const float BEET_LB = 1.15; // свекла
	const float CARROT_LB = 1.09; // свекла
	const float SALE_DELIVERY = 0.05; // скидка на доставку > $100
	const float DELIVERY_5 = 6.50; // доставка за <5Lb
	const float DELIVERY_5_20 = 14.00; // доставка за 5Lb> и <20Lb
	const float DELIVERY_20 = 0.05; // за каждый фунт доставки >20Lb
	
	char choice;
	double weight_artichoke = 0.0;
	double weight_beet = 0.0;
	double weight_carrot = 0.0;
	
	double common_weight_artichoke = 0.0;
	double common_weight_beet = 0.0;
	double common_weight_carrot = 0.0;
	
	double price_artichoke = 0.0;
	double price_beet = 0.0;
	double price_carrot = 0.0;
	double price_delivery = 0.0;
	
	double total_weight = 0.0;
	double total_price = 0.0;	
	double total_sale = 0.0;
	
	
	
	product_menu();
	while((choice = getchar()) != 'q') {
		// пропускаем пустой <Enter>
		if(choice == '\n') continue;
		choice = tolower(choice);
		switch(choice) {
			case 'a':
				printf("Enter weight artichoke (lb): ");
				scanf("%lf", &weight_artichoke);
				common_weight_artichoke += weight_artichoke;
				break;
			case 'b':
				printf("Enter weight beet (lb): ");
				scanf("%lf", &weight_beet);
				common_weight_beet += weight_beet;
				break;
			case 'c':
				printf("Enter weight carrot (lb): ");
				scanf("%lf", &weight_carrot);
				common_weight_carrot += weight_carrot;
				break;
			default:
				printf("Choice must be 'a', 'b', 'c' or 'q'!\n");
		}
		price_artichoke = common_weight_artichoke * ARTICHOKE_LB;
		price_beet = common_weight_beet * BEET_LB;
		price_carrot = common_weight_carrot * CARROT_LB;
		total_weight = common_weight_artichoke + common_weight_beet +
			common_weight_carrot;
		if(total_weight <= 5) 
			price_delivery = DELIVERY_5;
		else if(total_weight <= 20)
			price_delivery = DELIVERY_5_20;	
		else
			price_delivery = DELIVERY_5_20 + (total_weight-20) * DELIVERY_20;
		total_price = price_artichoke + price_beet + price_carrot; 
		printf("Total:\n\t-artichoke(%.2lflb)-$%.2lf\n"
			"\t-beet(%.2lflb)-$%.2lf\n"
			"\t-carrot(%.2lflb)-$%.2lf\n"
			"Delivery-$%.2lf\n",					
			common_weight_artichoke, price_artichoke,
			common_weight_beet, price_beet,
			common_weight_carrot, price_carrot,
			price_delivery);
		if(total_price > 100.00) {
			total_sale = total_price * SALE_DELIVERY;
			printf("Sale(5%%): $%.2lf\n", total_sale);
			total_price -= total_sale;
			printf("Total price: $%.2lf\n", total_price);
		} else
			printf("Total price: $%.2lf\n", total_price);
		
		
		
		product_menu();
		if(getchar() != '\n') continue;
	}
	printf("Have a nice day!\n");
	return 0;
}

void product_menu(void) {
	printf("******************************************************************\n");
	printf("Enter number, corresponding to category or action:\n");
	printf("a) weight of artichoke in lb\tb) weight of beet in lb\n");
	printf("c) weight of carrot in lb\tq) quit\n");
	printf("******************************************************************\n");
	printf("Choice: ");
}
