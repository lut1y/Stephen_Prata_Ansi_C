// когда цикл завершается?
#include <stdio.h>
int when(void) {
	int n = 5;
	while(n++ < 7);
	{
		printf("n = %d\n", n);
		n++;
		printf("Now n = %d\n", n);
	}
	printf("Cycle is finished.\n");
	return 0;
}
