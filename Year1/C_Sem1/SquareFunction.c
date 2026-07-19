#include <stdio.h>
/* Nan pati sa function "square" la pran yon nonm de tip "Double" kom agiman nan antre a ki rele n,
 epi li retounen vale nonm nan kom yon "kare", ki kalkile konsa n * n */
double square (double n){
    return n*n;
    //Egzanp: Si nou fe apel square(3.0), function ap retounen bann 9.0 paske 3.0 × 3.0 =9.0
}

int main () {

double number; // La mwen kreye yon variab ki rele "number" de tip "double" ki se nonm flotant a vigil yo
printf("Please enter a number: ");

// Here I verify if the user enter a correct number
if (scanf("%lf", &number) != 1) {
    printf("This input is invalid, Please enter a valid number.\n");
    return 1;
}

//scanf("%lf", &number); // la mwen mande itilizate a antre nonm li a
// &number : Voye adres variab "number" a bay "scanf" pou stoke vale itilizate a antre a.
// %lf se yon "format specifier" nou itilize pou entepele yon variab ki se tip "double"
//printf("square(%lf): %lf", number, square(number)); // La se se function "printf" ki pral afiche kare nonm lan

printf(" The square of %0.2lf is: %0.2lf", number, square(number));

}
