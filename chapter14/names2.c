// использует указатели на структуры
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

struct namect getinfo2(void);
struct namect makeinfo2(struct namect);
void showinfo2(struct namect);
char *s_gets(char *st, int n);

int names2(void) {
	struct namect person;
	
	person = getinfo2();
	person = makeinfo2(person);
	showinfo2(person);
	
	return 0;
}

struct namect getinfo2(void) {
	struct namect temp;
	
	printf("Enter your firstname.\n");
	s_gets(temp.fname, NLEN);
	printf("Enter your lastname.\n");
	s_gets(temp.lname, NLEN);
	return temp;
}

struct namect makeinfo2(struct namect info) {
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}

void showinfo2(const struct namect info) {
	printf("%s %s, your firstname and lastname consists of %d letter(s).\n",
			info.fname, info.lname, info.letters);
}
