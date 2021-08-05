// цикл со счетчиком
#include <stdio.h>

int sweetie1(void) {
	const int NUMBER = 22;
	int count = 1;
	
	while(count <= NUMBER) {
		printf("%d: Will be my friend!\n", count);
		count++;
	}
	return 0;
}
