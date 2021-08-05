#include <stdio.h>

void chline(char ch, int i, int j);

int task2(void) {
	
	chline('A', 4, 8);	
		
	return 0;
}

void chline(char ch, int i, int j) {
	int k;
	for(k=1; k <= 10; k++) {
		if(k>=i && k<=j) 
			putchar(ch);
		else 
    		putchar('-');
	}
	putchar('\n');
	return;
}
