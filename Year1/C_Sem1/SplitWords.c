#include <stdio.h>
#include <string.h>

int main() {
    char str[1024];
    char words[100][1024];
    int i = 0, j = 0, k = 0;

    // Read the input sentence
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Split the sentence into words
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            words[j][k] = '\0';
            j++;
            k = 0;
        } else {
            words[j][k++] = str[i];
        }
        i++;
    }
    words[j][k] = '\0'; // Terminate the last word

    // Print the words in reverse order
    for (i = j; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}
