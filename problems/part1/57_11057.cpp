#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > arr(n, vector<int>(10, 0));
    for(int i = 0; i < 10; i ++) {
        arr[0][i] = 1;
    }

    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < 10; j ++) {
            for(int t = j; t < 10; t ++) {
                arr[i][j] += (arr[i-1][t]) % 10007;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; i ++) {
        sum += (arr[n-1][i]) % 10007;
    }
    cout << sum % 10007 << endl;

    return 0;
}