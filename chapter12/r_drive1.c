// тестирование функций rand1() и srand1()
#include <stdio.h> 
extern void srand1(unsigned int x);
extern int rand1(void);

int r_drive1(void) {
	int count;
	unsigned seed;
	
	printf("Enter wished start number.\n");
	while(scanf("%u", &seed) == 1) {
		srand1(seed); 	// переустановка начального числа
		for(count = 0; count < 5; count++)
			printf("%d\n", rand1());
		printf("Enter next start number (q for finishing):\n");
	}
	printf("Program is finished.\n");
	
	return 0;
}
