#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

void generateSale(vector<int> &v, int idx, vector<vector<int>> &users, vector<int> &emoticons) {
    if(idx == v.size()) {
        int plus = 0;
        int total = 0;
        for(int i = 0; i < users.size(); i ++) {
            int sum = 0;
            for(int j = 0; j < v.size(); j ++) {
                if(v[j] >= users[i][0]) {
                    sum += ((emoticons[j]/100) * (100 - v[j]));
                }
            }
            if(sum >= users[i][1]) {
                plus ++;
            } else {
                total += sum;
            }
        }
        if(answer[0] < plus) {
            answer[0] = plus;
            answer[1] = total;
        } else if(answer[0] == plus) {
            if(answer[1] < total) {
                answer[1] = total;
            }
        }
        return;
    }
    
    if(v[idx] != 0) return;
    
    for(int i = 1; i <= 4; i ++) {
        v[idx] = 10*i;
        generateSale(v, idx+1, users, emoticons);
        v[idx] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    answer.assign(2, 0);
    vector<int> sales(emoticons.size(), 0);
    generateSale(sales, 0, users, emoticons);
    
    return answer;
}