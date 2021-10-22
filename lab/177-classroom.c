#include <stdio.h>

int main(){
    int chair[40] = {0};
    int snum, bookednum;
    scanf("%d", &snum);
    if (snum <= 0 || snum >= 40){
        if (snum < 1)
            printf("Students not enough.\n");
        if (snum > 40)
            printf("Too many students.\n");
        return 0;
   }

    scanf("%d", &bookednum);
    for (int i = 0; i < bookednum; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        if (r > 0 && r <= snum/6 + 1 && c > 0 && c <= 6)
            chair[(c-1) + (r-1) * 6] = 1;
    }
    for (int i = 0; i < snum; i++){
        if (((i + 1) % 6 == 1) && i)
            putchar('\n');
        printf("%c ", chair[i] ? 'S' : 'X');
    }
    putchar('\n');

    return 0;
}
