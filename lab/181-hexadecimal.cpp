#include <iostream>
using namespace std;
 
void decToHexa(int n){
    if (n <= 0 || n > 1000000){
        cout << n << " not in a scope" << endl;
        return ;
    }
    cout << n << " = "; 
        
    char hexaDeciNum[100];
 
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        hexaDeciNum[i++] = temp + (temp < 10 ? 48 : 55);
        n /= 16;
    }
 
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
    cout << endl;
}
 
int main(){
    int n[100];
    int n_line = 0;
    cin >> n_line;
    for (int i = 0; i < n_line; i++)
        cin >> n[i];

    for (int i = 0; i < n_line; i++)
        decToHexa(n[i]);
 
    return 0;
}
