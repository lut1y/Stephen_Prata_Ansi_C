// использует указатели на структуры
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void getinfo1(struct namect *);
void makeinfo1(struct namect *);
void showinfo1(const struct namect *);
char *s_gets(char *st, int n);

int names1(void) {
	struct namect person;
	getinfo1(&person);
	makeinfo1(&person);
	showinfo1(&person);
	
	return 0;
}

void getinfo1(struct namect *pst) {
	printf("Enter your firstname.\n");
	s_gets(pst->fname, NLEN);
	printf("Enter your lastname.\n");
	s_gets(pst->lname, NLEN);
}

void makeinfo1(struct namect *pst) {
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo1(const struct namect *pst) {
	printf("%s %s, your firstname and lastname consists of %d letter(s).\n",
			pst->fname, pst->lname, pst->letters);
}
