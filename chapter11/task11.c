#include <stdio.h>
#include <string.h>

#define LIM 10
#define LEN 30

char *s_gets2(char *, int);
int menu(void);
void srtASCII(char *strings[], int n);
void srt_length(char *strings[], int n);
void srt_length_first_word(char *strings[], int n);
int length_first_word(char *str);

int task11(void) {
	char strings[LIM][LEN];
	char *ptsrt[LIM]; // массива из LIM указателей
	char *orig[LIM]; // массив исходного значения указателей
	char choice;
	int ct=0, i;
	
	puts("Enter list of strings.");
	while(ct<LIM && s_gets2(strings[ct], LEN) && 
			strings[ct][0] != '\0' && strings[ct][0] != EOF) {
		orig[ct] = ptsrt[ct] = strings[ct]; // каждый указатель указывает на свою строку в массиве
		ct++;				
	}
	
	while ((choice = menu()) != 5) {
		switch(choice) {
			case 1:
				for(i=0; i < ct; i++)
					ptsrt[i] = orig[i];
				break;
			case 2:
				srtASCII(ptsrt, ct); // отдаем массив 
				break;
			case 3:
				srt_length(ptsrt, ct);
				break;
			case 4:
				srt_length_first_word(ptsrt, ct);
				break;
			default:
				printf("Error of choice!\n");				
		}
		for(i=0; i < ct; i++)
			puts(ptsrt[i]);
		
	}
	
		
	
	return 0;
}

int menu(void) {
	int code, status;
	
	printf("\nEnter number, correcponding to choiced variant:\n");
	printf("1) output original order strings\t2) output sorted by ASCII sequence\n");	
	printf("3) output sorted by length\t\t4) output sorted by length first word\n");
	printf("5) quit\n");
	while((status = scanf("%d", &code)) != 1 || 
			(code < 1 || code > 5 )) {
		if(status != 1)
			scanf("%*s");
		printf("\nEnter integer number from 1 to 5: ");
	}
	
	return code;
}

void srtASCII(char *strings[], int n) { // в описании массив указателей
	char *temp; // указатель на строку
	int top, seek;
	
	for(top = 0; top < n-1; top++)
		for(seek=top+1; seek < n; seek++)
			if(strcmp(strings[top], strings[seek])>0) {
				temp = strings[top]; // temp принимает адрес строки в массиве
				strings[top] = strings[seek];
				strings[seek] = temp;				
			}
}

void srt_length(char *strings[], int n) {
	char *temp;
	int top, seek;
	
	for(top = 0; top < n-1; top++)
		for(seek=top+1; seek < n; seek++)
			if(strlen(strings[top]) < strlen(strings[seek])) {
				temp = strings[top]; // temp принимает адрес строки в массиве
				strings[top] = strings[seek];
				strings[seek] = temp;				
			}
}

void srt_length_first_word(char *strings[], int n) {
	char *temp;
	int top, seek;
	
	for(top=0; top < n-1; top++)
		for(seek = top + 1; seek < n; seek++)
			if(length_first_word(strings[top]) < length_first_word(strings[seek])) {
				temp = strings[top]; // temp принимает адрес строки в массиве
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

int length_first_word(char *str) {
	int ret_val = 0;
	
	while(*str != ' ' && *str != '\0') {
		ret_val++;
		str++;
	}
	return ret_val;
}
