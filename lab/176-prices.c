#include <stdio.h>
#include <string.h>

typedef struct Dish{
    char name[32];
    int id;
    float price;
} Dish;

int main(){
    int n = 0;

    Dish dishes[64];
    char dish[32];
    float price = 0.;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    int minx = 0, maxx = 0;
    for (size_t i = 0; i < n; i++){
        scanf("%s %f", dish, &price);
        dishes[i].id = i+1;
        dishes[i].price = price;
        strcpy(dishes[i].name, dish);
        if (dishes[minx].price >= dishes[i].price)
            minx = i;
        if (dishes[maxx].price <= dishes[i].price)
            maxx = i;
    }
    float m;
    scanf("%f", &m);
    printf("Max price product(s) is:\n");
    for (size_t idx = 0; idx < n; idx++)
        if (dishes[maxx].price == dishes[idx].price)
            printf("    id: %03d name: %s price: %.2f Baht\n",
            dishes[idx].id, dishes[idx].name, dishes[idx].price);
    printf("Min price product(s) is:\n");
    for (size_t idx = 0; idx < n; idx++)
        if (dishes[minx].price == dishes[idx].price)
    printf("    id: %03d name: %s price: %.2f Baht\n",
            dishes[idx].id, dishes[idx].name, dishes[idx].price);
    printf("Products' price that <= %.2f Baht is:\n", m);
    for (size_t idx = 0; idx < n; idx++)
        if (dishes[idx].price <= m)
            printf("    id: %03d name: %s price: %.2f Baht\n",
                dishes[idx].id, dishes[idx].name, dishes[idx].price);
    return 0;
}
