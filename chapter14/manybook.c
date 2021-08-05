// каталог нескольких книг
#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100	// максимальное количество книг

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int manybook(void) {
	struct book library[MAXBKS];	// массив структур типа book
	int count = 0;
	int index;
	
	printf("Enter book's name.\n");
	printf("To finish entring press [enter] in start string.\n");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0') {
		printf("Now enter autor's name.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter cost.\n");
		scanf("%f", &library[count++].value);
		while(getchar() != '\n') continue;
		if(count < MAXBKS)
			printf("Enter next book's name.\n");
	}
	
	if(count > 0) {
		printf("Catalog of your book:\n");
		for(index=0; index < count; index++)
			printf("%s authority %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
	} else
		printf("No books? That's very bad.\n");
	
	return 0;
}
