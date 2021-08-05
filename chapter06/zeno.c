// сумма последовательности
#include <stdio.h>

int zeno(void) {
	int t_ct; // счетчик элементов
	double time, power_of_2;
	int limit;
	
	printf("Enter desired count elements of sequence: ");
	scanf("%d", &limit);
	for(time=0, power_of_2=1, t_ct=1; t_ct <= limit;
			t_ct++, power_of_2 *= 2.0) {
		time += 1.0 / power_of_2;
		printf("Time = %f, when count of elements = %d.\n", time, t_ct);			
	}
	return 0;
}
