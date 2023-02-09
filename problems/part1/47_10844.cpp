#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<unsigned long int> > arr(n+1, vector<unsigned long int>(10, 0));
    arr[1][0] = 0;
    for(int i = 1; i <= 9; i ++) {
        arr[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i ++) {
        arr[i][0] = arr[i-1][1] % 1000000000;
        for(int j = 1; j < 9; j ++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
        }
        arr[i][9] = arr[i-1][8] % 1000000000;
    }

    unsigned long int res = 0;
    for(int i = 0; i < 10; i ++) {
        res += arr[n][i] % 1000000000;
    }
    cout << res % 1000000000 << endl;

    return 0;
}