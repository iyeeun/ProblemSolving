#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool cmp(vector<string> a, vector<string> b) {
    if(a[0].compare("ICN") == 0 && b[0].compare("ICN") == 0) {
        return a[1] < b[1];
    } else if(a[0].compare("ICN") == 0) {
        return true;
    } else if (b[0].compare("ICN") == 0) {
        return false;
    } else return a < b;
}

void solve(vector<vector<string>> &tickets, vector<bool> &visit, vector<vector<int>> &adj, int cur, vector<string> &ans) {
    if(ans.size() == visit.size()+1) {
        if(answer.empty()) answer.assign(ans.begin(), ans.end());
        return;
    }
    
    for(int i : adj[cur]) {
        if(visit[i]) continue;
        visit[i] = true;
        ans.push_back(tickets[i][1]);
        solve(tickets, visit, adj, i, ans);
        visit[i] = false;
        ans.pop_back();
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> ans;
    ans.push_back("ICN");
    
    sort(tickets.begin(), tickets.end(), cmp);

    vector<vector<int>> adj(tickets.size());
    for(int i = 0; i < tickets.size(); i ++) {
        for(int j = 0; j < tickets.size(); j ++) {
            if(i == j) continue;
            if(tickets[i][1] == tickets[j][0]) {
                adj[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < tickets.size(); i ++) {
        if(tickets[i][0] == "ICN") {
            vector<bool> visit(tickets.size(), false);
            visit[i] = true;
            ans.push_back(tickets[i][1]);
            solve(tickets, visit, adj, i, ans);
            if(!answer.empty()) return answer;
            ans.pop_back();
        } else break;
    }
    
    
    return answer;
}