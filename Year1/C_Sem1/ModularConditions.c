#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i <= b; i++) {
        if (i % 3 == 2 && i % 7 == 5 && i % 11 == 7) 
        {
            printf("%d ", i);
        }
    }

    return 0;
}