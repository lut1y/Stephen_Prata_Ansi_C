// сохранение содержимого структуры в файле
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10	// максимальное количество книг

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

struct pack {
	struct book book;
	bool delete_me;
};


char *s_gets(char *st, int n);
int getlet(const char *s);
void updateRecord(struct pack *library);
bool getBook(struct pack *library);

int task7(void) {
	struct pack library[MAXBKS];	// массив структур
	int count = 0;
	int deleted = 0;
	int index, filecount, open;;
	FILE *pbooks;
	
	int size = sizeof(struct book);
	if((pbooks = fopen("book.dat", "r")) != NULL) {
		
		while(count < MAXBKS &&
				fread(&library[count], size, 1, pbooks) == 1) {
			if(count == 0)
				puts("Current content of file book.dat:");
			printf("%s of authority %s: $%.2f\n", library[count].book.title,
					library[count].book.author, library[count].book.value);
			
			printf("Do you want delete or update this record? ('y' or 'n'): ");
			if(getlet("yn") == 'y') {
				printf("What do you want with file? ('d' - delete or 'u' - update this record?): ");
				if(getlet("ud") == 'u')
					updateRecord(&library[count]);
				else {
					library[count].delete_me = true;
					deleted++;
					puts("Entry marked for deletion.");
				}
			}		
			count++;
		}
		fclose(pbooks);
	}
	filecount = count-deleted; // получаем действующее число книг
	if(count == MAXBKS) {
		fputs("File book.dat filled.", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Enter names of new books.");
	printf("To finish entring press [enter] in start string.\n");
	open = 0;	
	while(filecount < MAXBKS) {
		if(filecount < count) {
			while(library[open].delete_me == false)
				open++;
			if(getBook(&library[open]))	break;
			// если пропустить ввод, то вылет остальных
		}
		else 
			if(getBook(&library[filecount])) break;
		filecount++;
		if(filecount < MAXBKS)
			puts("Enter the next book title.");
	}
	
	if(filecount > 0) {
		puts("Catalog of your book:\n");
		for(index = 0; index < filecount; index++)
			if(library[index].delete_me == false)
				printf("%s of authority by %s: $%.2f\n", library[index].book.title,
					library[index].book.author, library[index].book.value);
		if((pbooks = fopen("book.dat", "w")) == NULL) {
			fputs("Can not open file book.dat!", stderr);
			exit(EXIT_FAILURE);
		}			
		for(index = 0; index < filecount; index++)
			if(library[index].delete_me == false)
				fwrite(&(library[index].book), size, 1, pbooks);
		fclose(pbooks);
	} else
		printf("No books? That's very bad.\n");	
	
	puts("Done!");
	return 0;
}

bool getBook(struct pack *library) {
	bool status = false;
	
	if(s_gets(library->book.title, MAXTITL) == NULL ||
			library->book.title[0] == '\0')
		status = true;
	else {
		puts("Now enter autor's name.");
		s_gets(library->book.author, MAXAUTL);
		puts("Now enter cost.");
		while(scanf("%f", &library->book.value) != 1) {
			scanf("%*s");
			printf("Please use numeric input: ");
		}
		while(getchar() != '\n') continue;
		library->delete_me = false;
	}
	return status;
}

int getlet(const char *s) {
	char ch;
	
	ch = getchar();
	while(strchr(s, ch) == NULL) {
		printf("Enter choice from \"%s\". Try again: ", s);
		while(getchar() != '\n') continue;
		ch = getchar();
	}
	while(getchar() != '\n') continue;
	
	return ch;
}

void updateRecord(struct pack *library) {
	/*char temp[MAXAUTL]; 
	
	puts("Updating:");	
	printf("\t- title[%s]: ", library->book.title);
	s_gets(temp, MAXAUTL);
	if(temp[0] != '\0') {
		*library->book.title = "";
		strcpy(library->book.title, temp);
	}
	
	printf("\t- author[%s]: ", library->book.author);
	s_gets(temp, MAXAUTL);
	if(temp[0] != '\0') {
		*library->book.author = "";
		strcpy(library->book.author, temp);
	}
	
	printf("\t- cost[%.2f]: ", library->book.value);
	s_gets(temp, MAXAUTL);
	if(temp[0] != '\0') 
		library->book.value = atof(temp);		
	
	library->delete_me = false;*/
	
	char ch;
	struct book copy;
	
	copy = library->book;
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title a) modify author");
	puts("v) modify value s) quit, saving changes");
	puts("q) quit, ignore changes");	
	printf("Choice: ");
	while((ch = getlet("tavsq")) != 's' && ch !='q') {
		switch(ch) {
			case 't':
				printf("Enter new title: ");
				s_gets(copy.title, MAXTITL);
				break;
			case 'a':
				printf("Enter new author: ");
				s_gets(copy.author, MAXTITL);
				break;
			case 'v':
				printf("Enter new value: ");
				while(scanf("%f", &copy.value) != 1) {
					printf("Enter numeric value: ");
					scanf("%*s");
				}
				while(getchar() != '\n') continue;
				break;
		}
		puts("Enter the letter that indicates your choice:");
		puts("t) modify title a) modify author");
		puts("v) modify value s) quit, saving changes");
		puts("q) quit, ignore changes");
		printf("Choice: ");
	}
	if(ch == 's') library->book = copy;
	library->delete_me = false;
}
