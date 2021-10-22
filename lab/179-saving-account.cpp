#include<iostream>
#include <stdio.h>
using namespace std;

double c(double s, double i, int y){
    if(y == 0){
        return s + s * i;
    } else{
        return c(s + s * i, i, y - 1);
    }
}

int main(){
    double saving, interest;
    int years;

    cin >> saving;
    cin >> interest;
    cin >> years;

    if(saving < 0 || interest < 0 || years < 0){
        return 0;
    }

    if (years > 0){
        printf("%.2f", c(saving, interest / 100, years - 1));
    } else if (years == 0){
        printf("%.2f", saving);
    }

    return 0;
}
