// ��������� ������� � ������ � �������
#include <stdio.h>
#define SEC_PER_MIN 60 // ���������� ������ � ������
int min_sec(void) {
    int sec, min, left;

    printf("Translation of seconds in minutes and seconds!\n");
    printf("Enter count seconds (<=0 for exit):\n");
    scanf("%d", &sec);  // ������ ���������� ������
    while (sec > 0) {
        min = sec / SEC_PER_MIN; // �������� ���������� �����
        left = sec % SEC_PER_MIN; // ���������� ������ � �������
        printf("%d seconds - it's %d minute(s) %d seconds.\n",
               sec, min, left);
        printf("Enter next value (<=0 for exit):\n");
        scanf("%d", &sec);
    }
    printf("Ready!\n");
    return 0;
}

