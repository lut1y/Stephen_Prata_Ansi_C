// преобразует аргумент командной строки в число
#include <stdio.h>
#include <stdlib.h>

int hello(int argc, char *argv[]) {
	int i, times;
	
	if(argc < 2 || (times = atoi(argv[1])) < 1)
		printf("Using: %s positive-number\n", argv[0]);
	else
		for(i=0; i<times; i++)
			puts("Good day!");
	
	return 0;
}
