// использование внешней переменной
#include <stdio.h>

void critic1(int *);

int task1(void) {
	int units = 0;
//	int status;
	
	printf("How much lbs is weigh small keg of oil?\n");
	
	/*while(((status = scanf("%d", &units)) == 1) && (units != 56)) {
		printf("You had the bad luck! Try again!\n");		
	}
	if(status == 1)
		printf("You are know it!\n");
	printf("Good Bye!");*/
	
	scanf("%d", &units);
	while(units != 56)
		critic1(&units);
	printf("You are know it!\n");
	
	return 0;
}

void critic1(int *units) {
	/*необязательное повторное объявление опущено*/
	printf("You had the bad luck! Try again!\n");
	scanf("%d", units);
}

