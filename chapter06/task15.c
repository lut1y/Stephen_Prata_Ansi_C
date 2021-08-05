#include <stdio.h>

int task15() {
	char str[255];
	char ch;
	int i, j;
	
	printf("Enter string: ");
	i=0;
	
	for(i=0, scanf("%c", &ch); ch!='\n'; i++) {
		str[i] = ch;
		scanf("%c", &ch);
	}
	
	printf("\n");
	for(j=i; j>=0; j--)
		printf("%c", str[j]);
	
	return 0;
}
