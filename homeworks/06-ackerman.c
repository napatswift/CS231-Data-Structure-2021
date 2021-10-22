#include<stdio.h>

int ac(int m, int n){
    printf("%d %d\n", m, n);
    if(m == 0){
        printf("1\n");
        return n + 1;
    } else if(m > 0 && n == 0){
        printf("2\n");
        return ac(m - 1, 1);
    } else if(m > 0 && n > 0){
        printf("3\n");
        return ac(m - 1, ac(m, n - 1));
    }
}

int main(){
    printf("%d", ac(1, 2));
}
