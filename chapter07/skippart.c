// использование оператора continue для пропуска части цикла
#include <stdio.h>
#include <iso646.h>
#define COVERAGE 350	// число квадратных фунтов на одну банку краски

int skippart(void) {
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	
	printf("Enter result first game (or 'q' for finishing): ");
	while(scanf("%f", &score) == 1) {
		if(score < MIN or score > MAX) {
			printf("%0.1f - invalid value. Try again: ", score);
			continue;
		}
		printf("Accepting %0.1f: \n", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("Enter result next game (or 'q' for finishing): ");  
	}
	if(n>0) {
		printf("Average value %d results equals %0.1f.\n", n, total/n);
		printf("Min = %0.1f, max = %0.1f\n", min, max);
	} else 
		printf("There is not entered not one valid results.\n");
	return 0;
}
