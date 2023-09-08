#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> enemy) {    
    if(k >= enemy.size()) return enemy.size();
    
    vector<vector<int>> dp(k+1, vector<int>(enemy.size()+1, 0));
    vector<int> answers(k+1, -1);
    
    for(int i = 0; i <= k; i ++) dp[i][0] = n;
    for(int i = 1; i <= enemy.size(); i ++) {
        dp[0][i] = dp[0][i-1] - enemy[i-1];
        if(dp[0][i] <= 0) {
            answers[0] = i-1;
            break;
        }
    }
    
    for(int i = 1; i <= enemy.size(); i ++) {
        for(int j = 1; j <= k; j ++) {
            if(answers[j] != -1) continue;
            dp[j][i] = max(dp[j-1][i-1], dp[j][i-1]-enemy[i-1]);
            if(dp[j][i] <= 0) {
                answers[j] = i-1;
            }
        }
    }
    
    return *max_element(answers.begin(), answers.end());
}