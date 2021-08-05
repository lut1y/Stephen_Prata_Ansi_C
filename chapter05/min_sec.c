// переводит секунды в минуты и секунды
#include <stdio.h>
#define SEC_PER_MIN 60 // количество секунд в минуте
int min_sec(void) {
    int sec, min, left;

    printf("Translation of seconds in minutes and seconds!\n");
    printf("Enter count seconds (<=0 for exit):\n");
    scanf("%d", &sec);  // чтение количества секунд
    while (sec > 0) {
        min = sec / SEC_PER_MIN; // усечение количества минут
        left = sec % SEC_PER_MIN; // количество секунд в остатке
        printf("%d seconds - it's %d minute(s) %d seconds.\n",
               sec, min, left);
        printf("Enter next value (<=0 for exit):\n");
        scanf("%d", &sec);
    }
    printf("Ready!\n");
    return 0;
}

