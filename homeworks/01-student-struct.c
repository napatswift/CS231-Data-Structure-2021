/*
 * Napat 6310400967
 */

#include <stdio.h>

typedef struct {
    char name[30];
    int age;
} Student[5];

int main(){
    Student std, *p_std;
    for(int i = 0;i < 5;++i){
        printf("enter student's name: ");
        scanf("%s", std[i].name);
        printf("enter student's age: ");
        scanf("%d", &std[i].age);
    }
    
    p_std = &std;
    
    for(int i = 0;i < 5;++i){
        if((*p_std)[i].age > 20){
            printf("Name: %s\n", (*p_std)[i].name);
            printf("Age: %d\n", (*p_std)[i].age);
        }
    }
}
