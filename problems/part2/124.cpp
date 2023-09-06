#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &arr, pair<int, int> s, pair<int, int> e) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(arr.size(), vector<int>(arr[0].size(), -1));
    
    dist[s.first][s.second] = 0;
    q.push(s);
    
    while(!q.empty()) {
        auto fr = q.front();
        q.pop();
        
        if(fr == e) break;
        
        int x = fr.first, y = fr.second;
        
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= arr.size() || ny < 0 || ny >= arr[0].size() || arr[nx][ny] == -1 || dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
        
    }
    
    return dist[e.first][e.second];
    
}

int solution(vector<string> maps) {
    pair<int, int> start, end, l;
    vector<vector<int>> arr(maps.size(), vector<int>(maps[0].length(), 0));
    
    for(int i = 0; i < maps.size(); i ++) {
        for(int j = 0; j < maps[0].length(); j ++) {
            char c = maps[i][j];
            if(c == 'S') start = make_pair(i, j);
            else if(c == 'E') end = make_pair(i, j);
            else if(c == 'L') l = make_pair(i, j);
            else if(c == 'X') arr[i][j] = -1;
        }
    }
    
    int lres = bfs(arr, start, l);
    int eres = bfs(arr, l, end);
    if(lres == -1 || eres == -1) return -1;
    else return lres + eres;
}