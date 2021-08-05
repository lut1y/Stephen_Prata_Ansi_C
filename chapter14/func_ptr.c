// исользование указателей на функции
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char *s_gets(char *st, int n);

char showmenu(void);
void eatline(void);
void show(void (*fp) (char *), char *str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int func_ptr(void) {
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun) (char *);
	
	puts("Enter string (empty string - exit from program):");
	while(s_gets(line, LEN) != NULL && line[0] != '\0') {
		while((choice = showmenu()) != 'n') {
			switch(choice) {
				case 'u': pfun = ToUpper; break;
				case 'l': pfun = ToLower; break;
				case 't': pfun = Transpose; break;
				case 'o': pfun = Dummy; break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("Enter string (empty string - exit from program):");
	}
	puts("Program is finished.");
	return 0;
}

char showmenu(void) {
	char ans;
	puts("Enter choiced variant from menu:");
	puts("l) lower		u) upper");
	puts("t) transpose	o) original");
	puts("n) next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while(strchr("ulton", ans) == NULL) {
		puts("Enter u, l, t, o or n");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}

void eatline(void) {
	while(getchar() != '\n') continue;
}

void ToUpper(char *str) {
	while(*str) {
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str) {
	while(*str) {
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str) {
	while(*str) {
		if(islower(*str)) 
			*str = toupper(*str);
		else
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char *str) {
}

void show(void (*fp)(char *), char *str) {
	(*fp)(str);	// применить выбранную функцию к str
	puts(str);	// отобразить результат
}
