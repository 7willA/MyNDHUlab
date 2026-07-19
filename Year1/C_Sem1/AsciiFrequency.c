#include <stdio.h>
int main() {
    int ascii_count[128];
    char ch;
    int first = 1;
    while (1) {
        for (int i = 32; i < 128; i++) {
            ascii_count[i] = 0;
        }
        int len = 0;
        while (scanf("%c", &ch) == 1 && ch != '\n') {
            if (ch >= 32 && ch <= 127) {
                ascii_count[(int)ch]++;
                len++;
            }
        }
        if (len == 0) {
            break;
        }
        if (!first) {
            printf("\n");
        }
        first = 0;
        for (int freq = 1; freq <= len; freq++) {
            for (int i = 127; i >= 32; i--) { 
                if (ascii_count[i] == freq) {
                    printf("%d %d\n", i, ascii_count[i]);
                }
            }
        }
    }
    return 0;
}