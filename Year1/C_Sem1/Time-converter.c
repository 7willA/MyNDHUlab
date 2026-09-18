#include <stdio.h>

int main(){
    int S;
    scanf("%d", &S);
    int H, M, R;
    H = S / 3600;
    M = (S/60)%60;
    R = S % 60;

    printf("%d seconds is equal to %d hours, %d minutes, and %d seconds\n", S, H, M, R);

    return 0;
}