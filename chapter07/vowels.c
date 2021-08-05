// использование множества меток
#include <stdio.h>

int vowels(void) {
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	
	printf("Enter text or # for finishing programm.\n");
	while((ch = getchar()) != '#') {
		ch = toupper(ch);
		switch (ch) {
			case 'A': 
				a_ct++;
				break;	
			case 'E': 
				e_ct++;
				break;
			case 'I': 
				i_ct++;
				break;
			case 'O': 
				o_ct++;
				break;
			case 'U': 
				u_ct++;
				break;
			default: break;
		}
	}
	printf("Count vowels:      A    E    I    O    U\n");
	printf("		%4d %4d %4d %4d %4d\n",
		a_ct, e_ct, i_ct, o_ct, u_ct);
	
	return 0;
}
