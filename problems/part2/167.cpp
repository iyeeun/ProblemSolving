#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check(string ban, string id) {
    if(ban.length() != id.length()) return false;
    for(int i = 0; i < id.length(); i ++) {
        if(ban[i] == '*') continue;
        if(ban[i] != id[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<int> v;
    for(int i = 0; i < user_id.size(); i ++) v.push_back(i);
    
    set<vector<int>> candidates;
    set<vector<int>> ans;
    
    while(true) {
        vector<int> tmp;
        for(int i = 0; i < banned_id.size(); i ++) {
            tmp.push_back(v[i]);
        }
        candidates.insert(tmp);
        if(!next_permutation(v.begin(), v.end())) break;
    }
    
    for(auto c : candidates) {
        bool ok = true;
        for(int i = 0; i < banned_id.size(); i ++) {
            if(!check(banned_id[i], user_id[c[i]])) {
                ok = false;
                break;
            }
        }
        if(ok) {
            sort(c.begin(), c.end());
            if(ans.insert(c).second) answer ++;
        }
    }
    
    return answer;
}