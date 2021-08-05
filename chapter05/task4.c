#include <stdio.h>

int task4(void) {
	const float SM_PER_FT = 30.48;
	const float SM_PER_INCH = 2.54;
	float h_sm;
	int h_ft;
	
	printf("Enter height in sm: ");
	scanf("%f", &h_sm);
	while(h_sm>0) {
		h_ft = h_sm / SM_PER_FT;
		printf("%.1f sm = %d ft(s) and %.1f inche(s)",
			h_sm, h_ft, (h_sm-h_ft*SM_PER_FT)/SM_PER_INCH);
		printf("\nEnter height (<=0 for exit): ");
	scanf("%f", &h_sm);
	}
	
	printf("Work is finished!\n");
	return 0;
}
