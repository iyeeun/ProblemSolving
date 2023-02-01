#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    vector<vector<int>> b(board);
    
    for(int i = 0; i < board.size(); i ++) {
        for(int j = 0; j < board.size(); j ++) {
            if(board[i][j] == 1) {
                if(i > 0) {
                    b[i-1][j] = 1;
                    if(j > 0) {
                        b[i-1][j-1] = 1;
                        b[i][j-1] = 1;
                    }
                    if(j < board.size()-1) {
                        b[i-1][j+1] = 1;
                        b[i][j+1] = 1;
                    }
                }
                if(i < board.size()-1) {
                    b[i+1][j] = 1;
                    if(j > 0) {
                        b[i+1][j-1] = 1;
                    }
                    if(j < board.size()-1) {
                        b[i+1][j+1] = 1;
                    }
                }
            }
        }
    }   
    
    for(int i = 0; i < board.size(); i ++) {
        for(int j = 0; j < board.size(); j ++) {
            if(b[i][j] == 0) {
                answer ++;
            }
        }
    }
    
    return answer;
}