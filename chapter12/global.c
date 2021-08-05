// использование внешней переменной
#include <stdio.h>

int units = 0; /* внешн€€ переменна€ */
void critic(void);

int global(void) {
	extern int units; /* необ€зательное повторное объ€вление */
	
	printf("How much lbs is weigh small keg of oil?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You are know it!\n");
	
	return 0;
}

void critic(void) {
	/*необ€зательное повторное объ€вление опущено*/
	printf("You had the bad luck! Try again!\n");
	scanf("%d", &units);
}

