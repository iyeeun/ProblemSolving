#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    // initial
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(3);
    answer.push_back(tmp);
    
    int num = 1;
    while(num < n) {
        vector<vector<int>> prev(answer);
        for(int i = 0; i < prev.size(); i ++) {
            for(int j = 0; j < 2; j ++) {
                if(prev[i][j] == 1) prev[i][j] = 2;
                else if(prev[i][j] == 2) prev[i][j] = 1;
            }
        }
        for(int i = 0; i < answer.size(); i ++) {
            for(int j = 0; j < 2; j ++) {
                if(answer[i][j] == 2) answer[i][j] = 3;
                else if(answer[i][j] == 3) answer[i][j] = 2;
            }
        }
        answer.push_back(tmp);
        answer.insert(answer.end(), prev.begin(), prev.end());
        num ++;
    }
    
    return answer;
}