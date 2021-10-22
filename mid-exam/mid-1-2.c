#include <stdio.h>

int main(){
    int *zPtr;
    int num, i;
    int z[5] = {1,2,3,4,5};
    zPtr = &z[2];
    ++zPtr[1];
    num = *zPtr;
    printf("%d\n", num);
    for (i=0; i<4; i++)
        printf("z=%d zPtr=%d\n", z[i], zPtr[i]);
}
