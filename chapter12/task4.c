#include <stdio.h>

int get_count_calls(void) {
	static int count;
	return ++count;
}

int task4(void) {
	for(int i = 0; i < 5; i++) 
		printf("function calls %d once(s).\n", get_count_calls());
	
	return 0;
}
