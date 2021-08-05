// использование операции sizeof
// в примере применяется определенный в стандарте С99 модификатор %z; если в вашей
// системе модификатор %zd не поддерживается, попробуйте вместо него %u или %lu
#include <stdio.h>
int sizeof_(void) {
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n = %d, n consist of %zd bytes; all values 'int' have %zd bytes.\n",
           n, sizeof n, intsize);
    return 0;
}


