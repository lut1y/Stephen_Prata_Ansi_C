// строки как указатели
#include <stdio.h>
int strptr(void) {
	printf("%s, %p, %c\n", "We", " - ", *"space vagrants");
	
	return 0;
}
