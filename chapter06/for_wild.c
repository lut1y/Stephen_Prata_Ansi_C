#include <stdio.h>

int for_wild(void) {
	int x;
	int y = 55;
	
	for(x=1; y <= 75; y = (++x * 5) + 50) // ���������: x*5, ++�, +50
		printf("%10d %10d\n", x, y);
	return 0;
}
