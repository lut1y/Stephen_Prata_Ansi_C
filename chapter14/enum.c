// использование перечислимых значений
#include <stdio.h>
#include <string.h>	// strcmp(), strchr()
#include <stdbool.h>	// средство —99

char *s_gets(char *st, int n);

enum spectrum {
	red, orange, yellow, green, blue, violet
};

const char *colors[] = {
	"red", "orange", "yellow", "green", "blue", "violet"
};

#define LEN 30

int enum_(void) {
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;
	
	puts("Enter color (or empty string for exit):");
	while(s_gets(choice, LEN) != NULL && choice[0] != '\0') {
		for(color = red; color <= violet; color++) {
			if(strcmp(choice, colors[color]) == 0) {
				color_is_found = true;
				break;
			}
		}
		if(color_is_found)
			switch(color) {
				case red:
					puts("Rose is red.");
					break;
				case orange:
					puts("Poppies is orange.");
					break;
				case yellow:
					puts("Sunflowers is yellow.");
					break;
				case green:
					puts("Grass is green.");
					break;
				case blue:
					puts("Bells is blue.");
					break;
				case violet:
					puts("Violet is purple.");
					break;
			}
		else
			printf("Color %s is unknown.\n", choice);
		color_is_found = false;
		puts("Enter next color (or empty string for exit):");
			
	}
	puts("Program is finished.");
	return 0;
}
