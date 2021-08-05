#include <stdio.h>
#include <math.h>

int task14(int argc, char *argv[]) {
	double num;
	double exp;
	
	if(argc != 3) 
		printf("Usage: %s [double] [integer]\n", argv[0]);
	else {
		num = atof(argv[1]);
		exp = atof(argv[2]);
		printf("%g^%g = %g\n", num, exp, pow(num, exp));
	}
	
	return 0;
}
