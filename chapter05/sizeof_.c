// ������������� �������� sizeof
// � ������� ����������� ������������ � ��������� �99 ����������� %z; ���� � �����
// ������� ����������� %zd �� ��������������, ���������� ������ ���� %u ��� %lu
#include <stdio.h>
int sizeof_(void) {
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n = %d, n consist of %zd bytes; all values 'int' have %zd bytes.\n",
           n, sizeof n, intsize);
    return 0;
}


