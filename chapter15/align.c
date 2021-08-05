// использование _Alignof и _Alignas (C11)
#include <stdio.h>

int align(void) {
	double dx;
	char ca,
		 cx;
	double dz;
	char cb;
	char _Alignas(double) cz;
	
	printf("Align char:   %u\n", _Alignof(char));
	printf("Align double: %u\n", _Alignof(double));
	printf("&dx: %p\n", &dx);
	printf("&ca: %p\n", &ca);
	printf("&cx: %p\n", &cx);
	printf("&dz: %p\n", &dz);
	printf("&cb: %p\n", &cb);
	printf("&cz: %p\n", &cz);
	
	return 0;
}
