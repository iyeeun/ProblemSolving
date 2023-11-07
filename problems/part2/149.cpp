#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<unsigned long long> dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        dp[i] = (3 * dp[i-2]) % 1000000007;
        int tmp = 0;
        for(int j = 0; j <= i-4; j += 2) {
            tmp = (tmp + (dp[j] % 1000000007)) % 1000000007;
        }
        dp[i] = (dp[i] + ((2*tmp) % 1000000007)) % 1000000007;
    }
    
    return (dp[n] % 1000000007);
}