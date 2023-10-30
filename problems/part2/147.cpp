#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
int scoregap = -1;

void calc(vector<int> &info, vector<int> &res) {
    int lscore = 0, ascore = 0;
    for(int i = 0; i <= 10; i ++) {
        if(res[i] == 0 && info[i] == 0) continue;
        else if(res[i] > info[i]) lscore += i;
        else ascore += i;
    }
    
    if(lscore > ascore) {
        if(scoregap == -1 || scoregap < (lscore - ascore)) {
            scoregap = (lscore - ascore);
            answer.assign(res.begin(), res.end());
        }
    }
}

void solve(int cur, int idx, vector<int> &info, vector<int> &res) {
    if(cur == 0) {
        calc(info, res);
        return;
    }
    
    for(int i = idx; i <= 10; i ++) {
        res[i] ++;
        solve(cur-1, i, info, res);
        res[i] --;
    }
}

vector<int> solution(int n, vector<int> info) {
    
    reverse(info.begin(), info.end());
    vector<int> res(11, 0);
    solve(n, 0, info, res);
    
    if(scoregap == -1) answer.assign({-1});
    else reverse(answer.begin(), answer.end());
    
    return answer;
}