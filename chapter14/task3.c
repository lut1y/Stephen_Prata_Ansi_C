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

//void sort_orig(struct book *ptrs[], int n);
void sort_alphabet(struct book *ptrs[], int n);
void sort_costs(struct book *ptrs[], int n);

int task3(void) {
	struct book library[MAXBKS];	// массив структур типа book
	struct book *orig[MAXBKS];
	struct book *ptrs[MAXBKS];
	int count = 0;
	int index;
	
	printf("Enter book's name.\n");
	printf("To finish entring press [enter] in start string.\n");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0') {
		printf("Now enter autor's name.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter cost.\n");
		scanf("%f", &library[count].value);
		// запоминаем указатели
		orig[count] = ptrs[count] = &library[count];
		count++;
		while(getchar() != '\n') continue;
		if(count < MAXBKS)
			printf("Enter next book's name.\n");
	}
	
	if(count > 0) {
		puts("Catalog of your book:");
		puts("*** Original order ***");
		for(index=0; index < count; index++)
			printf("%s authority %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		puts("*** Alphabet order ***");
		sort_alphabet(ptrs, count);
		for(index=0; index < count; index++)
			printf("%s authority %s: $%.2f\n", ptrs[index]->title,
					ptrs[index]->author, ptrs[index]->value);
		puts("*** Cost order ***");
		sort_costs(ptrs, count);
		for(index=0; index < count; index++)
			printf("%s authority %s: $%.2f\n", ptrs[index]->title,
					ptrs[index]->author, ptrs[index]->value);
	} else
		printf("No books? That's very bad.\n");
	
	return 0;
}

void sort_alphabet(struct book *ptrs[], int n) {
	struct book *temp;
	int top, seek;
	
	for(top = 0; top < n-1; top++)
		for(seek = top + 1; seek < n; seek++) {
			if(strcmp(ptrs[top]->title, ptrs[seek]->title) > 0) {
				temp = ptrs[top];
				ptrs[top] = ptrs[seek];
				ptrs[seek] = temp; 
			}
		}
}

void sort_costs(struct book *ptrs[], int n) {
	struct book *temp;
	int top, seek;
	
	for(top = 0; top < n-1; top++)
		for(seek = top + 1; seek < n; seek++) {
			if(ptrs[top]->value > ptrs[seek]->value) {
				temp = ptrs[top];
				ptrs[top] = ptrs[seek];
				ptrs[seek] = temp; 
			}
		}
}
