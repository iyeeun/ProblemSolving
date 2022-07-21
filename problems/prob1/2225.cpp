#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;

    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(k+1, 0));

    for(int i = 0; i < k; i ++) {
        dp[0][i] = 1;
    }

    for(int i = 0; i <= n; i ++) {
        dp[i][1] = 1;
        dp[i][2] = i+1;
    }
    
    for(int j = 3; j <= k; j ++) {
        for(int i = 1; i <= n; i ++) {    
            for(int t = 0; t <= i; t ++) {
                dp[i][j] += (dp[t][j-1] % 1000000000);
            }
        }
    }

    cout << (dp[n][k] % 1000000000) << '\n';

    return 0;
}