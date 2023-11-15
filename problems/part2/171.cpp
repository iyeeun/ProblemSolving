#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<int>> adj(n, vector<int>(n, -1));
    for(auto c : costs) {
        adj[c[0]][c[1]] = c[2];
        adj[c[1]][c[0]] = c[2];
    }
    
    vector<bool> visit(n, false);
    visit[0] = true;
    vector<int> visited;
    visited.push_back(0);
    
    while(visited.size() < n) {
        int minval = -1, target = -1, cur;
        for(auto v : visited) {
            for(int i = 0; i < n; i ++) {
                if(!visit[i] && adj[v][i] > 0) {
                    if(minval == -1 || minval > adj[v][i]) {
                        minval = adj[v][i];
                        target = i;
                        cur = v;
                    }
                }
            }
        }
        
        if(target != -1) {
            visit[target] = true;
            answer += adj[cur][target];
            visited.push_back(target);
        }
    }
    
    
    return answer;
}