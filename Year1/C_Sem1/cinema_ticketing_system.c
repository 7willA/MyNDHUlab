#include <stdio.h>
int main(){
int age;
scanf("%d", &age);

if (age <= 5){
    printf("Free");
} else if(age <=12){
    printf("Child Ticket: $150");
} else if (age <= 18){
    printf("Student Ticket: $180");
} else if(age <= 64){
    printf("Adult Ticket: $250");
} else{
    printf("Senior Ticket: $125");
}


return 0;
}
