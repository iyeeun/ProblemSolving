#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<unsigned long int> arr0(n+1, 0);
    vector<unsigned long int> arr1(n+1, 0);
    arr1[1] = 1;
    arr0[2] = 1;
    
    for(int i = 3; i <= n; i ++) {
        arr0[i] = arr0[i-1] + arr1[i-1];
        arr1[i] = arr0[i-1];
    }
    
    cout << (arr0[n]+arr1[n]) << '\n';
    
    return 0;
}