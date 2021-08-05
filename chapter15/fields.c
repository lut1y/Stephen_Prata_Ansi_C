// определение и использование полей
#include <stdio.h>
#include <stdbool.h> // С99, определение bool, true, false
/* стили линии */
#define SOLID 	0
#define DOTTED 	1
#define DASHED 	2
/* основные цвета */
#define BLUE 	4
#define GREEN 	2
#define RED 	1
/* смешанные цвета */
#define BLACK 	0
#define YELLOW 	(RED | GREEN)
#define MAGENTA	(RED | BLUE)
#define CYAN	(GREEN | BLUE)
#define WHITE	(RED | GREEN | BLUE)

const char * colors[8] = { "black", "red", "green", "yellow", "blue",
		"purple", "cyan", "white" };
		
struct box_props {
	bool opaque					: 1;	// или unsigned int (до С99)
	unsigned int fill_color		: 3;
	unsigned int				: 4;
	bool show_border			: 1;	// или unsigned int (до C99)
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
	unsigned int				: 2;
};
void show_settings(const struct box_props *pb);

int fields(void) {
	/* Создание и инициализация структуры box_props */
	struct box_props box = { true, YELLOW, true, GREEN, DASHED };
	
	printf("Original settings of window:\n");
	show_settings(&box);
	
	box.opaque = false;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf("\nChanged settings of window:\n");
	show_settings(&box);
	
	return 0;
}

void show_settings(const struct box_props *pb) {
	printf("Window %s.\n",
		pb->opaque == true ? "untransparently" : "transparently");
	printf("Color of background %s.\n", colors[pb->border_color]);
	printf("Style of borders ");
	switch(pb->border_style) {
		case SOLID	: printf("solid.\n"); break;
		case DOTTED	: printf("dotted.\n"); break;
		case DASHED	: printf("dashed.\n"); break;
		default		: printf("unknown type.\n");
		
	}
}
