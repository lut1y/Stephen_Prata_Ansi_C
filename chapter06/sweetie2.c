// цикл for со счетчиком
#include <stdio.h>

int sweetie2(void) {
	const int NUMBER = 22;
	int count = 1;
	
	for(count = 1; count <= 100; count++)
		printf("%d: Will be my friend!\n", count);
	return 0;
}
