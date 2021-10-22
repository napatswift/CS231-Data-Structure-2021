#include<stdio.h>

int main(){
    int arr[5][3];
    for (int j = 0; j < 5; j++)
        for (int i = 0; i <3; i++)
            scanf("%d", &arr[j][i]);

    for (int j = 0; j < 5; j++){
        int sum = 0;
        for (int i = 0; i <3; i++)
            sum += arr[j][i];
        printf("sum in row %d = %d\n", j+1, sum);
    }
    for (int i = 0; i <3; i++){
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += arr[j][i];
        printf("sum in column %d = %d\n", i+1, sum);
    }
    return 0;
}
