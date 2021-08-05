#include <stdio.h>

int ptr_ops(void) {
	int urn[5] = {100, 200, 300, 400, 500};
	int *ptr1, *ptr2, *ptr3;
	
	ptr1 = urn;		// ������������ ��������� ������
	ptr2 = &urn[2];	// �� �� �����
					// ������������� ��������� � ���������
					// ������ ���������
	printf("value of pointer, noname pointer, address of pointer:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);
	// �������� ����������
	ptr3 = ptr1 + 4;
	printf("\nsizeof(int) = %zd byte(s)", sizeof (int));
	printf("\nadding value int with pointer:\n");
	printf("ptr1 + 4 =  %p, *(ptr1 + 3) = %d\n",
		ptr1 + 4, *(ptr1 + 3));
	ptr1++;		// ����������������� ���������
	printf("\nvalue after performing an operation ptr1++:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
		ptr1, *ptr1, &ptr1);
	ptr2--;		// ����������������� ���������
	printf("\nvalue after performing an operation ptr2--:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
		ptr2, *ptr2, &ptr2);
	--ptr1;		// �������������� ��������� ��������
	++ptr2;		// �������������� ��������� ��������
	
	printf("\nrecovery original values of pointer:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	
	// ��������� ������ ��������� �� �������
	printf("\nsubtraction one pointer from other:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2-ptr1 = %td\n",
		ptr2, ptr1, ptr2-ptr1);
	
	// ��������� ������ �������� �� ���������
	printf("\nsubtraction from pointer value type of int:\n");
	printf("ptr3 = %p, *ptr3 = %d, ptr3 - 2 = %p\n", ptr3, *ptr3, ptr3 - 2);
	
	return 0;
}
