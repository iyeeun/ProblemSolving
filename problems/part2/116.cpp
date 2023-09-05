#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    
    vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
    
    dp[0].assign(board[0].begin(), board[0].end());
    int answer = *max_element(dp[0].begin(), dp[0].end());
    
    for(int i = 1; i < board.size(); i ++) {
        dp[i][0] = board[i][0];
        if(dp[i][0] > answer) answer = dp[i][0];
        for(int j = 1; j < board[0].size(); j ++) {
            if(board[i][j] == 0) continue;
            dp[i][j] = min(dp[i-1][j] , min(dp[i][j-1], dp[i-1][j-1])) + 1;
            if(dp[i][j] > answer) answer = dp[i][j];
        }
    }
    

    return (answer * answer);
}