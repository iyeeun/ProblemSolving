#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int groupnum = 0;
    vector<int> maxarea(1, 0);
    vector<int> answer(2);
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    vector<vector<bool>> visit(m, vector<bool>(n, false));

    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(picture[i][j] == 0) continue;
            if(visit[i][j]) continue;
            
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            visit[i][j] = true;
            
            groupnum ++;
            maxarea.push_back(1);
            
            while(!q.empty()) {
                auto fr = q.front();
                q.pop();
                
                for(int t = 0; t < 4; t ++) {
                    int nx = fr.first + dx[t];
                    int ny = fr.second + dy[t];
                    
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(picture[fr.first][fr.second] == picture[nx][ny] && !visit[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        visit[nx][ny] = true;
                        maxarea[groupnum] ++;
                    }
                }
                
            }
                        
        }
    }
    
    answer[0] = groupnum;
    answer[1] = *max_element(maxarea.begin(), maxarea.end());
    
    return answer;
}