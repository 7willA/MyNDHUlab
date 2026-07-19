#include <stdio.h>

int main (){
int n;
scanf("%d",&n);

for(int a=2; a<=n; a++){
    while(n%a==0){
        printf("%d",a);
        n = n/a;
    }
}
}
