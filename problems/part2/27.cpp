#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> res;

    for(int i = 0; i < moves.size(); i ++) {
        int move = moves[i]-1;
        int idx = 0;
        while(board[idx][move] == 0 && idx < board.size()-1) {
            idx ++;
        }
        if(!res.empty() && res.top() == board[idx][move]) {
            answer += 2;
            res.pop();
            board[idx][move] = 0;
        } else {
            if(board[idx][move] != 0) {
                res.push(board[idx][move]);
                board[idx][move] = 0;
            }
        }
    }
    
    return answer;
}