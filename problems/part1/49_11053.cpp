#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int totalmax = 1;
    cin >> n;
    vector<int> lst(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i ++) {
        cin >> lst[i];
    }

    dp[0] = 1;
    for(int i = 1; i < n; i ++) {
        int max = 1;
        for(int j = 0; j < i; j ++) {
            if(lst[i] > lst[j] && dp[j]+1 > max) {
                max = dp[j]+1;
            }
        }
        dp[i] = max;
        if(dp[i] > totalmax) totalmax = dp[i];
    }

    cout << totalmax << endl;

    return 0;
}