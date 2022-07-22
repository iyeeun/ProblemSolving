#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    int new_sum = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(i < n-3) {
                new_sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
            }
            if(new_sum > sum) {
                sum = new_sum;
            }
        }
    }

    return 0;
}