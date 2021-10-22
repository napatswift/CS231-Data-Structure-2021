#include<iostream>
using namespace std;

void sos(int arr[], int size){
    size_t i = 0, si = 0;
    int sum[size - 1];
    if (size > 1){
        for (i = 0; i < size; i++)
            sum[si++] = arr[i] + arr[i + 1];
        sos(sum, size - 1);
        for (i = 0; i < si - 1; i++)
            cout << sum[i] << (i + 1 < si - 1 ? ", " : "");
        cout << endl;
    }
}


int main(){
    int num,floor[100][100];
    cin >> num;
    for(int i = 0; i < num; i++)
        cin >> floor[0][i];

    for(int i = 1; i < num; i++){
        for(int j = 1; j <= num-i; j++){
            floor[i][j-1] = floor[i-1][j-1] + floor[i-1][j]; 
        }
    }
    
    for(int i = num-1; i >= 0; i--){
        for(int j = 0; j < num-i; j++){
            if(j == num-i-1)
                cout << floor[i][j];
            else
                cout << floor[i][j] << ", ";
        }
        cout << endl;
    }
}
