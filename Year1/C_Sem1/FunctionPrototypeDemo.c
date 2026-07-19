//Declaration of a function or function prototype
#include <stdio.h>
char fun(); //function protype
int main (){
char c = fun();
printf("character is: %c", c);
}

char fun(){
return 'a';

}
