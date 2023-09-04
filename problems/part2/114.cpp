#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> adj(N+1, vector<int>(N+1, 0));
    for(auto r : road) {
        if(adj[r[0]][r[1]] == 0) {
            adj[r[0]][r[1]] = r[2];
            adj[r[1]][r[0]] = r[2];
        } else if(adj[r[0]][r[1]] > r[2]) {
            adj[r[0]][r[1]] = r[2];
            adj[r[1]][r[0]] = r[2];
        }
    }
    
    vector<int> visit(N+1, -1);
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    
    while(!q.empty()) {
        int fr = q.front();
        q.pop();
        
        for(int i = 1; i <= N; i ++) {
            if(adj[fr][i] == 0) continue;
            if(visit[i] == -1) {
                q.push(i);
                visit[i] = visit[fr] + adj[fr][i];
            } else if(visit[i] > visit[fr] + adj[fr][i]) {
                q.push(i);
                visit[i] = visit[fr] + adj[fr][i];
            }
        }
    }
    
    for(int i = 1; i <= N; i ++) {
        if(visit[i] <= K) answer ++;
    }
    

    return answer;
}