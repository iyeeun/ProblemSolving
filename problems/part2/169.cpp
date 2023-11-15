#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for(auto e : edge) {
        adj[e[0]-1][e[1]-1] = true;
        adj[e[1]-1][e[0]-1] = true;
    }
    
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()) {
        int fr = q.front();
        q.pop();
        
        for(int i = 0; i < n; i ++) {
            if(adj[fr][i] && dist[i] == -1) {
                dist[i] = dist[fr] + 1;
                q.push(i);
            }
        }
    }
        
    sort(dist.begin(), dist.end(), greater<int>());
    for(int i = 1; i < n; i ++) {
        if(dist[0] != dist[i]) break;
        answer ++;
    }
    
    return answer;
}