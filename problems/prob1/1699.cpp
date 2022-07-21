#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    int max_sqrt = (int) sqrt((double)n);

    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i ++) {
        int m = (int) sqrt((double)i);
        if(m == 1) {
            dp[i] = i;
        } else if(m*m == i) {
            dp[i] = 1;
        } else {
            dp[i] = 1 + dp[i-(m*m)];
            for(int j = m; j > 1; j --) {
                int new_dp = 1 + dp[i-(j*j)];
                if(new_dp < dp[i]) {
                    dp[i] = new_dp;
                }
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}