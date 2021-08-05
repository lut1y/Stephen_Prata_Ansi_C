// каталог для одной книги
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 41	// максимальная длина названия + 1
#define MAXAUTL 31	// максимальная длина имени автора + 1

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int book(void) {
	struct book library; // объявление library в качестве переменной типа book
	
	printf("Press name of book.\n");
	s_gets(library.title, MAXTITL);	// доступ к разделу названия книги
	printf("Now press author's name.\n");
	s_gets(library.author, MAXAUTL);
	printf("Now press cost.\n");
	scanf("%f", &library.value);
	printf("%s of authority %s: $%.2f\n", library.title,
		library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author,
		library.title, library.value);
	printf("Ready!\n");	
	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_value;
	char *find;
	
	ret_value = fgets(st, n, stdin);
	if(ret_value) {
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n') continue;
	}	
	
	return ret_value;
}
