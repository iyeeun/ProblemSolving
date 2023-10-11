#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, false);
    
    for(int i = 0; i < n; i ++) {
        if(visit[i]) continue;
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            
            for(int j = 0; j < n; j ++) {
                if(!visit[j] && computers[fr][j] == 1) {
                    q.push(j);
                    visit[j] = true;
                }
            }
        }
        answer ++;
    }
    
    return answer;
}