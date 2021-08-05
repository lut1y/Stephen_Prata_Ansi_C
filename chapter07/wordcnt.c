// производит подсчет символов, слов и строк
#include <stdio.h>
#include <ctype.h> // для isspace()
#include <stdbool.h> // для bool, true, false
#define STOP '|'

int wordcnt(void) {
	char c;				 // прочитанный символ
	char prev;  		 // предыдущий прочитанный символ
	long n_chars = 0L;	 // количество символов	
	int n_lines = 0;	 // количество строк
	int n_words = 0;	 // количество слов
	int p_lines = 0;	 // количество неполных строк
	bool inword = false; //  == true если символ с находится внутри слова
	
	printf("Enter text for analisys (| for finishing): \n");
	prev = '\n';
	while((c = getchar()) != STOP) {
		n_chars++;
		if(c == '\n')
			n_lines++;
		if(!isspace(c) && !inword) {
			inword = true; // начало слова
			n_words++;
		}
		if(isspace(c) && inword)
			inword = false; // достигнут конец слова
		prev = c;	// сохраяняем значение символа
	}
	if(prev !='\n')
		p_lines = 1;
	printf("symbols = %ld, words = %d, strings = %d, ",
		n_chars, n_words, n_lines);
	printf("incomplete line = %d\n", p_lines);
	
	return 0;
}

