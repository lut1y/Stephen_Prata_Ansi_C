// информация о массиве zippo
#include <stdio.h>
int zippo1(void) {
	int zippo[4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
	
	printf("size of int: %zd byte(s)\n", sizeof(int));
	printf("size of zippo: %zd byte(s)\n", sizeof(zippo));
	printf("   zippo = %p,    zippo + 1 = %p\n",
		zippo, zippo + 1); // zippo - это указатель на zippo[0], zippo+1 - указатель на zippo[1] 
	// zippo - это 2 int'a, вроде {2, 4} или {6, 8}
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n", 
		zippo[0], zippo[0] + 1); // zippo[0] - указатель на zippo[0][0], zippo[0]+1 - это указатель на zippo[0]+int = zippo[0][1] 
	// zippo[0] - это 1 int
	printf("  *zippo = %p,   *zippo + 1 = %p\n",  *zippo, *zippo + 1); //*zippo - разыменование указателя дает значение,
															// представленное объектом, на который производится ссылка
	printf("zippo[0][0] = %d\n", zippo[0][0]);
	printf("  *zippo[0] = %d\n", *zippo[0]);
	printf(" **zippo[0] = %d\n", **zippo); // **zippo[0] => *(&zippo[0])[0] => zippo[0][0]
	printf("         zippo[2][1] = %d\n", zippo[2][1]);
	printf(" *(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));
	
	
	return 0;
}
