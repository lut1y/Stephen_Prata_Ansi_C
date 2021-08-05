// не делайте так!
#include <stdio.h>

int nono(void) {
	char side_a[] = "Side A";
	char dont[] = {'U', 'R', 'A', '!'};
	char side_b[] = "Side B";
	
	puts(dont);	// не является строкой
	
	return 0;
}
