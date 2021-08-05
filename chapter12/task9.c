#include <stdio.h>
#include <string.h>

int task9(void) {
	int ct_word, i;
	char str[128];
	char **ptr;
		
	printf("How much words do you want to enter? ");
	scanf("%d", &ct_word);
	printf("Enter %d words:\n", ct_word);
	
	ptr = (char**) malloc(ct_word * sizeof(char*));
	
	for(i=0; i < ct_word; i++) {
		scanf("%s", str);
		ptr[i] = (char *) malloc((strlen(str)+1) * sizeof(char));
		strcpy(ptr[i], str);
	}
	printf("This is your entered words:\n");	
	for(i=0; i < ct_word; i++) {
		printf("%d. %s\n", i+1, ptr[i]);
		free(ptr[i]);
	}
	
	free(ptr);
}

