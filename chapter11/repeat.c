// ������� repeat() � �����������
#include <stdio.h>
// ��������� -> ���������... ��������� ���������
int repeat(int argc, char *argv[]) {
	int count;
	
	printf("Count of arguments, shown in terminal: %d\n", argc-1);
	for(count = 1; count < argc; count++)
		printf("%d: %s\n", count, argv[count]);
	printf("\n");
	
	return 0;
}
