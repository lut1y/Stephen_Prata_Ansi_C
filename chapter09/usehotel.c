// программа определ€юща€ стоимости номеров
// 	”ѕ–ј¬Ћяёў»… ћќƒ”Ћ№
#include <stdio.h>
#include "hotel.h" // определ€ет константы, объ€вл€ет функции

int usehotel(void) {
	int nights;
	double hotel_rate;
	int code;
	
	while((code = menu()) != QUIT) {
		switch(code) {
			case 1:
				hotel_rate = HOTEL1;
				break;
			case 2:
				hotel_rate = HOTEL2;
				break;
			case 3:
				hotel_rate = HOTEL3;
				break;
			case 4:
				hotel_rate = HOTEL4;
				break;
			default:
				hotel_rate = 0.0;
				printf("Error!\n");
				break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you for using and wish you success.\n");
	return 0;
}
