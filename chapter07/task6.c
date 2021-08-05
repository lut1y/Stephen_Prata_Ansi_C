#include <stdio.h>
#include <stdbool.h>

int task6(void) {
	char ch;
	bool entry_e;
	int count=0;
	
	while((ch = getchar()) != '#') {
		if(ch == 'e') 
			entry_e = true;
		else 
			if(entry_e) {
				if(ch == 'i') {
					count++;
					entry_e = false;
				} else {
					entry_e = false;	
				}
			}
	}
	printf("\nIn this sentence 'ei' was %d changes:\n", count);
	return 0;
}
