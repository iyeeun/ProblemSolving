#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<bool>> adj(n+1, vector<bool>(n+1, false));
    for(vector<int> wire : wires) {
        adj[wire[0]][wire[1]] = true;
        adj[wire[1]][wire[0]] = true;
    }
    
    for(vector<int> wire : wires) {
        queue<int> q;

        // cut
        adj[wire[0]][wire[1]] = false;
        adj[wire[1]][wire[0]] = false;
        
        vector<bool> visit(n+1, false);
        int tower1 = 0;
        q.push(wire[0]);
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            
            tower1 ++;
            visit[fr] = true;
            
            for(int i = 1; i <= n; i ++) {
                if(adj[fr][i] && !visit[i]) {
                    q.push(i);
                }
            } 
        }
        
        visit.assign(n+1, false);
        int tower2 = 0;
        q.push(wire[1]);
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            
            tower2 ++;
            visit[fr] = true;
            
            for(int i = 1; i <= n; i ++) {
                if(adj[fr][i] && !visit[i]) {
                    q.push(i);
                }
            } 
        }
        
        int res = (tower1 > tower2)? tower1 - tower2 : tower2 - tower1;
        if(answer == -1 || answer > res) {
            answer = res;
        }
        
        adj[wire[0]][wire[1]] = true;
        adj[wire[1]][wire[0]] = true;
        
    }
    
    return answer;
}