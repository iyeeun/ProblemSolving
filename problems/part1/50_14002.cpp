#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<vector<int> > dp(n);
    vector<int> maxlst;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    int totalmax = 1;

    dp[0].push_back(nums[0]);
    maxlst = dp[0];

    for(int i = 1; i < n; i ++) {
        int max = 1;
        int idx = -1;
        for(int j = 0; j < i; j ++) {
            if(nums[i] > nums[j] && dp[j].size()+1 > max) {
                max = dp[j].size()+1;
                idx = j;
            }
        }

        if(idx != -1) {
            dp[i].assign(dp[idx].begin(), dp[idx].end());
        }
        dp[i].push_back(nums[i]);

        if(max > totalmax) {
            maxlst.assign(dp[i].begin(), dp[i].end());
            totalmax = max;
        }
    }

    cout << totalmax << endl;
    for(int i = 0; i < maxlst.size(); i ++) {
        cout << maxlst[i] << " ";
    }
    cout << endl;


    return 0;
}