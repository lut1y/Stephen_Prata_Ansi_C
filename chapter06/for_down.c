#include <stdio.h>

int for_down(void) {
	int secs;
	for(secs = 5; secs > 0; secs--)
		printf("%d second(s)!\n", secs);
	printf("Key in ignition!\n");
	return 0;
}
