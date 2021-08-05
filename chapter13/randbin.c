// произваольный доступ, двоичный ввод-вывод
#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 1000

int randbin(void) {
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;
	
	// создание значений double
	for(i=0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0/(i+1);
	// попытка открыть файл
	if((iofile = fopen(file, "wb")) == NULL) {
		fprintf(stderr, "Can not open file %s for exit.\n", file);
		exit(EXIT_FAILURE);
	}
	// запись в файл массива в двоичном формате
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	
	if((iofile = fopen(file, "rb")) == NULL ) {
		fprintf(stderr, 
			"Can not open file %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}
	// чтение избранных элементов файла
	printf("Enter index in range 0-%d\n", ARSIZE-1);
	while(scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
		pos = (long) i * sizeof(double); // вычисление смещения
		fseek(iofile, pos, SEEK_SET); // переход в нужную позицию
		fread(&value, sizeof (double), 1, iofile);
		printf("In this index founded value %f.\n", value);
		printf("Enter next index (or value outside range for finishing):\n");
	}
	// завершение
	fclose(iofile);
	puts("Program is finished.");
		
	return 0;
}
