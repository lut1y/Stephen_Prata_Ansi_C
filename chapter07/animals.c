// использование оператора switch
#include <stdio.h>
#include <ctype.h>

int animals(void) {
	char ch;
	
	printf("Give me letter of alphabet, and I take you ");
	printf("name of animals,\nthat start with this letter.\n");
	printf("Enter letter or '#' for finishing.\n");
	while((ch=getchar()) != '#') {
		if('\n' == ch)
			continue;
		if(islower(ch)) // только строчные буквы
			switch (ch) {
				case 'a':
					printf("argali, wild mountain Asian sheep\n");
					break;
				case 'b':
					printf("babirussa, wild Malay pig\n");
					break;
				case 'с':
					printf("coati, common nose\n");
					break;
				case 'd':
					printf("desman, waterfowl\n");
					break;
				case 'e':
					printf("echidna, needle anteater\n");
					break;
				case 'f':
					printf("fisher, light brown marten\n");
					break;
				default:
					printf("Question puzzled!\n");
			} // конец оператора выбора
		else
			printf("Only lowercase letters are recognized.\n");
		while(getchar() != '\n') continue;
		printf("Enter next letter or # for finishing.\n");
	}
	printf("Good Bye!");
	return 0;
}
