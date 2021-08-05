// использование указателей и функции malloc()
#include <stdio.h>
#include <string.h>	// strcpy(), strlen()
#include <stdlib.h> // malloc(), free();

#define SLEN 81

struct namect {
	char *fname;
	char *lname;
	int letters;
};

void getinfo3(struct namect *);	// выделение памяти
void makeinfo3(struct namect *);
void showinfo3(const struct namect *);
void cleanup(struct namect *);	// освобождение памяти, когда она не нужна
char *s_gets(char *st, int n);

int names3(void) {
	struct namect person;
	
	getinfo3(&person);
	makeinfo3(&person);
	showinfo3(&person);
	cleanup(&person);
	
	return 0;
}

void getinfo3(struct namect *pst) {
	char temp[SLEN];
	
	printf("Enter your firstname.\n");
	s_gets(temp, SLEN);
	
	// выделение памяти для хранения имени
	pst->fname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst->fname, temp);
	printf("Enter your lastname.\n");
	s_gets(temp, SLEN);
	pst->lname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void makeinfo3(struct namect *pst) {
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo3(const struct namect *pst) {
	printf("%s %s, your firstname and lastname consists of %d letter(s).\n",
			pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst) {
	free(pst->fname);
	free(pst->lname);
}
