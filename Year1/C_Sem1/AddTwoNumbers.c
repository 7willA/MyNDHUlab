//Function definition

/*#include <stdio.h>

int Area_of_Rect(int lenght, int width){
    int area; 
    area = lenght * width;
    return area;
}


int main()
{
    int l, b;
    scanf("%d%d", &l,&b);
    int area=Area_of_Rect(l,b);
    
    printf("%d", area);

    return 0;
}*/

/*#include <stdio.h>

int add(int a, int b){
int sum;
sum = a + b;
return sum;
}

int main (){
 int m=30, n=24, sum;

 sum = add(m,n);

 printf("The sum is: %d", sum);

}*/

#include <stdio.h>
int add(int, int);

int main (){
int m=120, n=20, sum;

sum= add(m, n);
printf("Sum is : %d", sum);

}

int add(int a, int b){
    return a+b;

}