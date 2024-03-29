#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long answer = 0;
    int arr[n+1][k+1];

    for(int i = 1; i <= k; i ++) {
        arr[1][i] = i;
    }
    for(int i = 1; i <= n; i ++) {
        arr[i][1] = 1;
    }

    for(int i = 2; i <= n; i ++) {
        for(int j = 2; j <= k; j ++) {
            arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % 1000000000;
        }
    }
    
    cout << arr[n][k] << endl;

    return 0;
}