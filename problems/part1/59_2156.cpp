#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> wine(t);
    for(int i = 0; i < t; i ++) {
        cin >> wine[i];
    }

    vector<long> dp(t, 0);
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0] + wine[1], max(wine[1] + wine[2], wine[0] + wine[2]));

    for(int i = 3; i < t; i ++) {
        dp[i] = max(dp[i-1], max(wine[i] + wine[i-1] + dp[i-3], wine[i] + dp[i-2]));
    }

    cout << dp[t-1] << endl;

    return 0;
}