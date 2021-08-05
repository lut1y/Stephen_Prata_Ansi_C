#include <stdio.h>

int task13(int argc, char *argv[]) {
	int i;
	
	if(argc < 1) {
		printf("Usage: %s [string]...\n", argv[0]);
	} else {
		i = argc;
		while(i-->1) 
			printf("%s ", argv[i]);			
	}
	return 0;
}
