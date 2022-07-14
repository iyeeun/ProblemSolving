#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<vector<unsigned long long int>> 
    arr(N+1, vector<unsigned long long int>(10, 0));

    for(int i = 0; i < 10; i ++) {
        arr[1][i] = 1;
    }
    arr[1][0] = 0;

    for(int i = 2; i <= N; i ++) {
        arr[i][0] = arr[i-1][1];
        arr[i][9] = arr[i-1][8];
        for(int j = 1; j < 9; j ++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000;
        }
    }

    unsigned long long int cnt = 0;
    for(int i = 0; i < 10; i ++) {
        cnt += (arr[N][i]%1000000000);
    }

    cout << cnt%1000000000 << '\n';

    return 0;
}