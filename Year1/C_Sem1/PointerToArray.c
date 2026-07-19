#include <stdio.h>

int main() {
    int array[9][7] = {0}; 
    int (*p)[7] = array;    

    p[0][4] = 10;
    p[4][3] = 20;


    printf("%d\n", p[0][4]); 
    printf("%d\n", p[4][3]); 

    return 0;
}
