#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, int> all;
vector<set<string>> candidates(11);

void make(string str, string res, int cur, vector<bool> &visit, int len) {
    if(res.length() == len) {
        all[res] ++;
        if(all[res] >= 2) candidates[res.length()].insert(res);
        return;
    }
    
    for(int i = cur; i < str.length(); i ++) {
        if(!visit[i]) {
            visit[i] = true;
            make(str, res+str[i], i, visit, len);
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string order : orders) {
        vector<bool> v(order.length(), false);
        sort(order.begin(), order.end());
        for(int i : course) {
            make(order, "", 0, v, i);
        }
    }
    
    for(auto i : candidates) {
        int max = 1;
        for(auto j : i) {
            if(all[j] > max) {
                max = all[j];
            }
        }
        for(auto j : i) {
            if(all[j] == max) answer.push_back(j);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}