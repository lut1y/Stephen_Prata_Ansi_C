#include <stdio.h>

void mikado(int); // ���������� �������

int loccheck(void) {
	int pooh = 2,	// ��������� ���������� ��� main()
		bah = 5;
	
	printf("Inside main() pooh = %d and &pooh = %p\n",
			pooh, &pooh);
	printf("Inside main() bah = %d and &bah = %p\n",
			bah, &bah);	
	mikado(pooh);
	
	return 0;
}

void mikado(int bah) { // ����������� �������
	int pooh = 10; // ��������� ���������� ��� mikado()
	
	printf("Inside mikado() pooh = %d and &pooh = %p\n",
			pooh, &pooh);
	printf("Inside mikado() bah = %d and &bah = %p\n",
			bah, &bah);
	// �  ���������� bah ���������� ������ ��������, ������
	// ����� ��������� ������ ������. 
}
