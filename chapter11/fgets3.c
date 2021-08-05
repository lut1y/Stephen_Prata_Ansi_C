// использование функции fgets()
#include <stdio.h>
#define STLEN 10

int fgets3(void) {
	char words[STLEN];
	int i;
	puts("Enter string (or empty string for exit from program): ");
	while(fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
		i=0;
		// fgets считывает STLEN-1 символов строки + \0, если
		// ввод составил больше STLEN-1
		while(words[i] != '\n' && words[i] != '\0')
			i++;
		if(words[i] == '\n')
			words[i] = '\0';
		else
			// иначе если не нужно финализировать строку
			// "прогоняем" оставшиеся символы
			while(getchar() != '\n')
				continue;
		puts(words);
	}
	puts("Ready.");
	return 0;
}
