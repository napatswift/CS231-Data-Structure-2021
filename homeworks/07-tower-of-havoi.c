#include <stdio.h>
#include <math.h>

char A[32];
char B[32];
char C[32];
char curr_a = -1;
char curr_b = -1;
char curr_c = -1;


void init(int n) {
    for(int i = 0; i < n; ++i) { 
        A[i] = n-i-1;
        curr_a++;
    }
}

void show(char from_rod, char to_rod) {
    if(from_rod == 'A') {
        if( to_rod == 'B')
            B[++curr_b] = A[curr_a];
        if(to_rod == 'C')
            C[++curr_c] = A[curr_a];
        --curr_a;
    }

    if(from_rod == 'B') {
        if( to_rod == 'A')
            A[++curr_a] = B[curr_b];
        if(to_rod == 'C')
            C[++curr_c] = B[curr_b];
        --curr_b;
    }

    if(from_rod == 'C') {
        if( to_rod == 'B')
            B[++curr_b] = C[curr_c];
        if(to_rod == 'A')
            A[++curr_a] = C[curr_c];
        --curr_c;
    }
    
    printf("tower A:");
    for(int i = 0; i <= curr_a; ++i)
        printf(" %d", A[i]);
    printf("\n");
    printf("tower B:");
    for(int i = 0; i <= curr_b; ++i)
        printf(" %d", B[i]);
    printf("\n");
    printf("tower C:");
    for(int i = 0; i <= curr_c; ++i)
        printf(" %d", C[i]);
    printf("\n\n");
    
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int *i) {
    if(n == 1) {
        printf("move#%d:move(1,%c,%c,%c)\n", *i, from_rod, aux_rod, to_rod);
        show(from_rod, to_rod);
        (*i)++;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod, i);

    printf("move#%d:move(1,%c,%c,%c)\n", *i, from_rod, aux_rod, to_rod);
    show(from_rod, to_rod);
    (*i)++;

    towerOfHanoi(n-1, aux_rod, to_rod, from_rod, i);
}


int main() {
    int n, i = 1;
    scanf("%d", &n);
    init(n);
    printf("Start\ntower A:");
    for(int i = 0; i <n; ++i)
        printf(" %d", A[i]);
    printf("\ntower B:\ntower C:\n\n");
    towerOfHanoi(n, 'A', 'C', 'B', &i);
}
