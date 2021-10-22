#include<stdio.h>

/*
 * Napat
 * 6310400967
 */

int gcd(int m, int n){
    if (m == 0)
        return n;
    else
        return gcd(n%m, m);
}

int main(){
    int n1 = 0, n2 = 0;
    scanf("%d %d", &n1, &n2);
    printf("%d", gcd(n1, n2));
    return 0;
}
