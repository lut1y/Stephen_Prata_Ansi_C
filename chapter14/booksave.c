// сохранение содержимого структуры в файле
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10	// максимальное количество книг

char *s_gets(char *st, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int booksave(void) {
	struct book library[MAXBKS];	// массив структур
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	
	int size = sizeof(struct book);
	if((pbooks = fopen("book.dat", "a+b")) == NULL) {
		fputs("Can not open file book.dat\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while(count < MAXBKS && fread(&library[count], size, 
						1, pbooks) == 1) {
		if(count == 0)
			puts("Current content of file book.dat:");
		printf("%s of authority %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
		count++;						
	}
	filecount = count;
	if(count == MAXBKS) {
		fputs("File book.dat filled.", stderr);
		exit(2);
	}
	
	puts("Enter names of new books.");
	printf("To finish entring press [enter] in start string.\n");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0') {
		puts("Now enter autor's name.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter cost.");
		scanf("%f", &library[count++].value);
		while(getchar() != '\n') continue;
		if(count < MAXBKS)
			printf("Enter next book's name.\n");
	}
	
	if(count > 0) {
		puts("Catalog of your book:\n");
		for(index = 0; index < count; index++)
			printf("%s of authority %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	} else
		printf("No books? That's very bad.\n");
	
	return 0;
}
