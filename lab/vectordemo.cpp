#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> A = {0, 1, 2, 3, 4};
    A.push_back(5);
    A.push_back(6);
    A.erase(A.begin());

    int n = A.size();

    for (int i = 0; i < n; i++)
        cout<< A[i] << " ";
     cout << endl;
}

