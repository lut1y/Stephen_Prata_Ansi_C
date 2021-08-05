// тестирование функции rand0()
#include <stdio.h>

extern int rand0(void);

int r_drive0(void) {
	int count;
	
	for(count = 0; count < 5; count++)	
		printf("%d\n", rand0());
	
	return 0;
}
