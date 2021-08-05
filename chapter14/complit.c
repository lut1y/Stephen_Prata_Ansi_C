// составные литералы
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {	// шаблон структуры: book - дескриптор
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int complit(void) {
	struct book readfirst;
	int score;
	printf("Enter rating: ");
	scanf("%d", &score);
	if(score >= 84)
		readfirst = (struct book) {"Crime and Punishment",
									"Fedor Dostoevsky",
									11.25 };
	else
		readfirst = (struct book) {"Beautiful hat mr.Baunsi",
									"Fred Winsom",
									5.99 };
	printf("Appointed by you ratings:\n");
	printf("%s by %s: $%.2f\n", readfirst.title, 
		readfirst.author, readfirst.value);
	return 0;
}
