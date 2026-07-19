#include <stdio.h>
#include <string.h>
#include <math.h>

// Structure definition
struct Number {
    char digit[1024]; // Holds the number as a string
    int base;         // Holds the base of the number
};

// Function: convertToDec
// Purpose: Converts a number in any given base (specified by num.base) to decimal (base 10)
// Parameters:
//   num - A structure containing a string `digit` (the number in its original base) and the `base` (the base of the number)
// Returns:
//   A structure containing the decimal representation of the number in `digit`
struct Number convertToDec(struct Number num) {
    struct Number dec;
    int decimalValue = 0;
    int length = strlen(num.digit);

    // Convert each digit to decimal
    for (int i = 0; i < length; i++) {
        char currentChar = num.digit[i];
        int value;

        if (currentChar >= '0' && currentChar <= '9') {
            value = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'Z') {
            value = currentChar - 'A' + 10;
        } else if (currentChar >= 'a' && currentChar <= 'z') {
            value = currentChar - 'a' + 10;
        } else {
            printf("Invalid character in number\n");
            strcpy(dec.digit, "0");
            dec.base = 10;
            return dec;
        }

        if (value >= num.base) {
            printf("Invalid digit for the base\n");
            strcpy(dec.digit, "0");
            dec.base = 10;
            return dec;
        }

        decimalValue = decimalValue * num.base + value;
    }

    // Store the decimal value as a string in dec.digit
    sprintf(dec.digit, "%d", decimalValue);
    dec.base = 10;

    return dec;  // Return the decimal number as a structure
}
