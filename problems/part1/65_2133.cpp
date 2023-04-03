#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n+1, 0);

    arr[0] = 1;
    arr[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        arr[i] = arr[i-2] * 3;
        for(int j = 4; j <= i; j ++) {
            arr[i] += 2*arr[i-j];
        }
    }
    
    cout << arr[n] << endl;

    return 0;
}