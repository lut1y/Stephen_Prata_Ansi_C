// правильно расставляйте точки с запятой
#include <stdio.h>
int while2(void) {
	int n=0;
	
	while(n++ < 3);
		printf("n equals %d\n", n);
	printf("It's all, that do that program.\n");
	
	return 0;
}
