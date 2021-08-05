#include <stdio.h>

int for_show(void) {
	int num = 0;
	
	for(printf("Continue to enter numbers!\n"); num != 6; )
		scanf("%d", &num);
	printf("That's it number, than will need!\n");
	return 0;
}
