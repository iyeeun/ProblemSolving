#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1, 0);

    arr[2] = arr[3] = 1;
    
    for(int i = 4; i <= n; i ++) {
        arr[i] = 1 + arr[i-1];
        if(i % 3 == 0) {
            if(arr[i/3] + 1 < arr[i]) {
                arr[i] = arr[i/3] + 1;
            }
        }
        if(i % 2 == 0) {
            if(arr[i/2] + 1 < arr[i]) {
                arr[i] = arr[i/2] + 1;
            }
        }
    }

    cout << arr[n] << endl;

    return 0;
}