// инкремент: префиксная и постфиксная формы
#include <stdio.h>
int add_one(void) {
	int ultra = 0,
		super = 0;
	while(super < 5) {
		super++;
		++ultra;
		printf("super = %d, ultra = %d \n", super, ultra);
	}
	return 0;
}
