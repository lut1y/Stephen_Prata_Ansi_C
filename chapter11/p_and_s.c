// указатели и строки
#include <stdio.h>
int p_and_s(void) {
	const char *mesg = "Don't be confused!"; // не позволяйте себя запутать!
	const char *copy;
	
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n",
		mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n",
		copy, &copy, copy);
	
	
	return 0;
}
