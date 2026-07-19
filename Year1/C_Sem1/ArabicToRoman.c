#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *result) {
    // la mwen kreye 2 variab pou fe conversion youn pou chif arab yo e you pou chif romain yo
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
// const char pou define ke pointer ki se tip char vale ki ladan yo pap chanje
    result[0] = '\0';  // Initialize result as an empty string

    for (int i = 0; i < 13; i++) {// to itarate the process/ repete action an
        while (num >= value[i]) { //This part convert the arabic num into romain
            strcat(result, symbol[i]);// use to concatane "Join" these two strings
            num = num - value[i];// this part is to make substraction
        }
    }
}

int main() {
    int ArabicNum;
    char RomanNum[100];
    scanf("%d", &ArabicNum);

    intToRoman(ArabicNum, RomanNum);
    printf("%s", RomanNum);

    return 0;
}
