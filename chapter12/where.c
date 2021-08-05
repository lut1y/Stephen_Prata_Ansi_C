// где что находится в памяти
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String literal";
int where(void) {
	int auto_store = 30;
	char auto_string[] = "Automatic array char";
	int *pi;
	char *pcl;
	
	pi = (int *) malloc(sizeof(int));
	*pi = 35;
	pcl = (char *) malloc(strlen("Dynamic string") + 1);
	strcpy(pcl, "Dymanic string");
	
	printf("    static_store: %d in address %p\n", static_store, &static_store);
	printf("      auto_store: %d in address %p\n", auto_store, &auto_store);
	printf("             *pi: %d in address %p\n", *pi, pi);
	printf("      %s in address %p\n", pcg, pcg);
	printf("%s in address %p\n", auto_string, auto_string);
	printf("      %s in address %p\n", pcl, pcl);
	printf("    %s in address %p\n", "String in quotes", "String in quotes");
	free(pi);
	free(pcl);
	
	return 0;
}

