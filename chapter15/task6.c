#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEFT 0

struct font {
	unsigned int id: 8;
	unsigned int size: 7;
	unsigned int align: 2;
	bool bold: 1;
	bool italic: 1;
	bool underline: 1;
	
};

void eatline(void);
char getlet(const char *str);
int getmenu(struct font font);
void changefont(struct font *font);
void changesize(struct font *font);
void changealign(struct font *font);
void changebold(struct font *font);
void changeitalic(struct font *font);
void changeunderline(struct font *font);

int task6(void) {
	int choice;
	struct font font = { 1, 12, LEFT, 0, 0, 0 };
	
	while((choice = getmenu(font)) != 'q') {
		switch(choice) {
			case 'f':
				changefont(&font);
				break;
			case 's':
				changesize(&font);
				break;
			case 'a':
				changealign(&font);
				break;
			case 'b':
				changebold(&font);
				break;
			case 'i':
				changeitalic(&font);
				break;
			case 'u':
				changeunderline(&font);
				break;
				
		}
	}
	
	puts("Program is finished.");
	return 0;
}

void changeunderline(struct font *font) {
	if(font->underline) font->underline = false;
	else font->underline = true;
}

void changeitalic(struct font *font) {
	if(font->italic) font->italic = false;
	else font->italic = true;
}

void changebold(struct font *font) {
	if(font->bold) font->bold = false;
	else font->bold = true;
}

void changealign(struct font *font) {
	char ch;
	
	puts("Choice align: ");
	puts("l) left   c) center   r) right ");
	printf("choice: ");
	ch = getlet("lcr");
	switch(ch) {
		case 'l': font->align = 0; break;
		case 'c': font->align = 1; break;
		case 'r': font->align = 2; break;
	}	
}

void changesize(struct font *font) {
	unsigned int size;
	
	printf("Enter new id of font: ");
	while(scanf("%d", &size) != 1 || size > 127) {
		eatline();
		printf("Value is invalid. Value must be 0 to 127. Try again: ");		
	}
	eatline();
	font->size = size;
}

void changefont(struct font *font) {
	unsigned int id;
	
	printf("Enter new id of font: ");
	while(scanf("%d", &id) != 1 || id > 255) {
		eatline();
		printf("Value is invalid. Value must be 0 to 255. Try again: ");		
	}
	eatline();
	font->id = id;
}

int getmenu(struct font font) {
	int ch;
	
	puts("ID  SIZE  ALIGN   B    I    U");
	printf(" %d   %d   %s   %s  %s  %s\n\n",
		font.id, font.size,
		font.align == 0 ? "left" : (font.align == 1 ? "center" : "right"),
		font.bold == 0 ? "off" : "on",
		font.italic == 0 ? "off" : "on",
		font.underline == 0 ? "off" : "on"
		);
		
	puts("f) change font   s) change size   a) change align");
	puts("b) bold          i) italic        u) underline");
	puts("q) quit");
	printf("choice: ");
	ch = getlet("fsabiuq");	
		
	return ch;
}

char getlet(const char *str) {
	int ch;
	
	ch = getchar();
	eatline();
	while(strchr(str, ch) == NULL) {
		printf("Symbol must been from list: %s. Try again: ", str);
		ch = getchar();
		eatline();
	}
	return ch;
}

void eatline(void) {
	while(getchar() !='\n') continue;
}
