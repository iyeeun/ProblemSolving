#include <string>
#include <vector>

using namespace std;

int answer = -1;

void dfs(string cur, string name, vector<vector<bool>> v, int res, int idx, int dir) {
    if(cur == name) {
        if(answer == -1 || res < answer) answer = res;
        return;
    }
    
    if(v[idx][dir]) return;
    
    v[idx][dir] = true;
    
    if(cur[idx] != name[idx]) {
        if(name[idx] - 'A' <= 13) {
            res += (name[idx] - 'A');
        } else {
            res += ('Z' - name[idx] + 1);
        }
        cur[idx] = name[idx];
    }
    
    int left = idx-1;
    int right = idx+1;
    if(left < 0) left += name.length();
    if(right >= name.length()) right -= name.length();
    
    dfs(cur, name, v, res+1, left, 0);
    dfs(cur, name, v, res+1, right, 1);
    
}

int solution(string name) {
    
    vector<vector<bool>> v(name.length(), vector<bool>(2, false));
    string c = "";
    for(int i = 0; i < name.length(); i ++) c += "A";
    
    if(name == c) return 0;
    
    dfs(c, name, v, -1, 0, 0);
    dfs(c, name, v, -1, 0, 1);
    
    return answer;
}