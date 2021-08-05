#include <stdio.h>

void mikado(int); // объ€вление функции

int loccheck(void) {
	int pooh = 2,	// локальные переменные дл€ main()
		bah = 5;
	
	printf("Inside main() pooh = %d and &pooh = %p\n",
			pooh, &pooh);
	printf("Inside main() bah = %d and &bah = %p\n",
			bah, &bah);	
	mikado(pooh);
	
	return 0;
}

void mikado(int bah) { // определение функции
	int pooh = 10; // локальна€ переменна€ дл€ mikado()
	
	printf("Inside mikado() pooh = %d and &pooh = %p\n",
			pooh, &pooh);
	printf("Inside mikado() bah = %d and &bah = %p\n",
			bah, &bah);
	// в  переменную bah передаетс€ просто значение, однако
	// адрес перменной совсем другой. 
}
