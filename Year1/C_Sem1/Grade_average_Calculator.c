#include <stdio.h>

int main() {
    int Literature;
    int English; 
    int Science;

    scanf("%d %d %d", &Literature, &English, &Science);
    int Total = Literature + English + Science;
    printf("Total score: %d\n", Total);

    int IntegerAvg = Total / 3;
    printf("Integer average: %d\n", IntegerAvg);

    double PreciseAvg = (double)Total / 3;
    printf("Precise average: %f\n", PreciseAvg);

    return 0;
}