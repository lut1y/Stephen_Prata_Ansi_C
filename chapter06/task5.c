#include <stdio.h>

int task5() {
	int i, j, space;
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char let;
	int ord_num=-1;
	
	printf("Enter letter: ");
	scanf("%c", &let);
	for(i=0; i < 27; i++) {
		if(lets[i] == let) {
			ord_num = i;
			break;
		}
	}
	if(ord_num == -1) {
		printf("This letter don't from array!");
		return -1; // ����� �� �� �������		
	}
	for(space=ord_num; space>=0; space--) { // ����� ��������
		printf("%*s", space, ""); 
		for(i=0; i < ord_num-space; i++) { // ����� ���� �� ����� � ������
				printf("%c", lets[i]);
		}
		for(j=ord_num-space; j>=0 ; j--) { // ����� ���� �� ����� � ��������
				printf("%c", lets[j]);
		}
		printf("\n");		
	}
	
	return 0;
}
