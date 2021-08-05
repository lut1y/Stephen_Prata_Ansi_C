#include <stdio.h>
#include <ctype.h>

int task3(void) {
	int ch,
		c_up, c_down, c_other;
	
	while((ch=getchar()) != EOF) {
		if(isupper(ch))
			c_up++;
		else if(islower(ch))
				c_down++;	
			 else
			 	c_other++;
	}
	
	printf("lower: %d\n", c_down);
	printf("upper: %d\n", c_up);
	printf("other: %d\n", c_other);
	return 0;
}
