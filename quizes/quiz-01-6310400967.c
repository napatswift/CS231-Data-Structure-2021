#include <stdio.h>

void cal_rec_area(float width, float height, float* ptArea){
    *ptArea = width * height;
}

void enterInput(float *width, float *length){
    printf("Enter width: ");
    scanf("%f", width);
    printf("Enter length: ");
    scanf("%f", length);
}

void printArea(float area){
    printf("Rectangle area is %.2f", area);
}

int main(){
    float width, length, area;

    enterInput(&width, &length);
    cal_rec_area(width,length,&area);
    printArea(area);
    return 0;
}
