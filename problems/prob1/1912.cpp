#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> A(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
    }

    vector<long long int> dp(n+1);
    dp[1] = A[1];
    
    for(int i = 2; i <= n; i ++) {
        int new_sum = dp[i-1] + A[i];
        if(new_sum > A[i]) {
            dp[i] = new_sum;
        } else {
            dp[i] = A[i];
        }
    }

    cout << *(max_element(dp.begin()+1, dp.end())) << '\n';

    return 0;
}