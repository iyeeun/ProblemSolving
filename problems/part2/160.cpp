#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    vector<vector<int >> dp(m, vector<int>(n, 0));
    vector<vector<bool>> water(m, vector<bool>(n, false));
    
    for(auto p : puddles) water[p[0]-1][p[1]-1] = true;
    
    for(int i = 0; i < m; i ++) {
        if(water[i][0]) break;
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; i ++) {
        if(water[0][i]) break;
        dp[0][i] = 1;
    }
    
    for(int i = 1; i < m; i ++) {
        for(int j = 1; j < n; j ++) {
            if(water[i][j]) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007; 
        }
    }
    
    return dp[m-1][n-1];
}