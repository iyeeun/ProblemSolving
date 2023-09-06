#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> answer;
int answernum = 0;

void check(int idx) {
    if(answer[idx].length() == 1) return;
    
    string target = answer[idx];
    
    for(int i = 0; i < answer.size(); i ++) {
        if(i == idx) continue;
        int cnt = 0;
        for(int j = 0; j < answer[i].length(); j ++) {
            for(int t = 0; t < target.length(); t ++) {
                if(target[t] == answer[i][j]) cnt ++;
            }
        }
        if(cnt == answer[i].length()) {
            answernum --;
            return;
        }
    }
}

void solve(vector<vector<string>> &relation, vector<bool> &visit,
           int cur, vector<int> &res, int n) {
    if(res.size() == n) {
        set<string> s;
        for(int i = 0; i < relation.size(); i ++) {
            string tmp = "";
            for(int j = 0; j < res.size(); j ++) {
                tmp += relation[i][res[j]];
                tmp += ",";
            }
            auto r = s.insert(tmp);
            if(!r.second) break;
        }
        if(relation.size() == s.size()) {
            string tmp = "";
            for(int j = 0; j < res.size(); j ++) {
                tmp += to_string(res[j]);
            }
            answer.push_back(tmp);
        }
        return;
    }
    
    
    for(int i = cur+1; i < relation[0].size(); i ++) {
        if(visit[i]) continue;
        visit[i] = true;
        res.push_back(i);
        solve(relation, visit, i, res, n);
        visit[i] = false;
        res.pop_back();
    }

}

int solution(vector<vector<string>> relation) {
    int len = relation[0].size();
    vector<bool> visit(len, false);
    vector<int> res;
    
    for(int i = 1; i <= len; i ++) {
        for(int j = 0; j < len; j ++) {
            res.push_back(j);
            solve(relation, visit, j, res, i);
            res.pop_back();
        }
    }
    
    answernum = answer.size();
    
    for(int i = 0; i < answer.size(); i ++) {
        check(i);
    }
    
    return answernum;
}