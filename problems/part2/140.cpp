#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle);
    
    for(int i = 1; i < dp.size(); i ++) {
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        for(int j = 1; j < dp[i].size()-1; j ++) {
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
        int l = dp[i].size()-1;
        dp[i][l] = dp[i-1][l-1] + triangle[i][l];
    }
    
    return *max_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end());
}