// преобразует размер обуви в дюймы
#include <stdio.h>
#define ADJUST 7.31 // один из видом символической константы

int shoes1(void) {
	
	const double SCALE = 0.333; // еще один вид символической константы
	double shoe, foot;
	
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Size of shoe (man)   length leg\n");
	printf("%10.1f %15.2f inch\n", shoe, foot);
	
	return 0;
}
