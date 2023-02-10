#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;

    for(int i = 2; i <= n; i ++) {
        dp[i] = i;
        if(sqrt(i) == (int) sqrt(i)) {
            dp[i] = 1;
        } else {
            for(int j = 1; j < i/2; j ++) {
                if(dp[i-j] + dp[j] < dp[i]) {
                    dp[i] = dp[i-j] + dp[j];
                }
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}