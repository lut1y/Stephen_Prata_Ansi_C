// ������ ����������, ������ �����
#include <stdio.h>
#define SLEN 40
#define LIM 5
int arrchar(void) {
	const char *mytalents[LIM] = {
		"instant addition of numbers", // ���������� ����������� �����
		"exact mupliplication", // ������ ���������
		"accumulation of data", // ������������ ������
		"execution of instructions to the letter", // ���������� ���������� � ��������� �� �����
		"knowledge language of programming C" // ������ ����� ���������������� �
	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Health sleep", "Watching TV",
		"mailing of letter", "Reading electronic mail"
	};
	int i;
	
	puts("Compare our talents.");
	printf("%-42s %-25s\n", "My talants", "Your talants");
	for(i=0; i < LIM; i++)
		printf("%-42s %-25s\n", mytalents[i], yourtalents[i]);
	printf("\nsize mytalents: %zd, size yourtalents: %zd\n",
		sizeof(mytalents), sizeof(yourtalents));
	return 0;
}
