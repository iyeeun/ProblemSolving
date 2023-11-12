#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
// U, D, L, R : L, R
int map[][2] = {{2, 3}, {3, 2}, {1, 0}, {0, 1}};
vector<vector<vector<bool>>> visitlog;

void solve(vector<string> &grid,
           int dir, pair<int, int> cur, pair<int, int> start, int len) {
    
    int h = grid.size();
    int w = grid[0].length();
            
    if(visitlog[cur.first][cur.second][dir]) {
        if(cur == start) {
            answer.push_back(len);
        }
        return;
    }
    
    visitlog[cur.first][cur.second][dir] = true;
        
    int nextdir;
    pair<int, int> next;
    
    if(grid[cur.first][cur.second] == 'L') {
        nextdir = map[dir][0];
    } else if(grid[cur.first][cur.second] == 'R') {
        nextdir = map[dir][1];
    } else if(grid[cur.first][cur.second] == 'S') {
        nextdir = dir;
    }
    
    if(nextdir == 0) next = make_pair((h+cur.first-1)%h, cur.second);
    else if(nextdir == 1) next = make_pair((cur.first+1)%h, cur.second);
    else if(nextdir == 2) next = make_pair(cur.first, (w+cur.second-1)%w);
    else if(nextdir == 3) next = make_pair(cur.first, (cur.second+1)%w);
    
    solve(grid, nextdir, next, start, len+1);
}

vector<int> solution(vector<string> grid) {
    int h = grid.size();
    int w = grid[0].length();
    
    visitlog.assign(h, vector<vector<bool>>(w, vector<bool>(4, false)));
    
    for(int t1 = 0; t1 < h; t1 ++) {
        for(int t2 = 0; t2 < w; t2 ++) {
            for(int i = 0; i < 4; i ++) {
                if(visitlog[t1][t2][i]) continue;
                solve(grid, i, make_pair(t1, t2), make_pair(t1, t2), 0);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}