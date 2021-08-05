// следите за фигурными скобками
// неправильное кодирование может приводить к бесконечному циклу
#include <stdio.h>
int while1(void) {
	int n=0;
	
	while(n<3)
		printf("n equals %d\n", n);
		n++;
	printf("It's all, that do that program.\n");
	
	return 0;
}
