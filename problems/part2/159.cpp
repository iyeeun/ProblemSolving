#include <string>
#include <vector>

using namespace std;

void solve(int s, int n, vector<int> &ans) {
    if(s < n) return;
    
    if(n == 1) {
        ans.push_back(s);
        return;
    }
    
    int t = s/n;
    ans.push_back(t);
    solve(s-t, n-1, ans);
}

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    solve(s, n, answer);
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}