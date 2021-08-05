#include <stdio.h>
#include <ctype.h>

int task2(void) {
	char ch;
	int i;
	
	i=1;
	while((ch = getchar()) != '#') {
		printf("%c-%d ", ch, ch);
		if(i % 8 == 0) {
			printf("\n");
			i = 0;
		}
		i++;
	}
	return 0;
}
