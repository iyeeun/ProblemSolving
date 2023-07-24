#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    bool possible = false;
    
    queue<pair<int, int>> q;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    int curx = 0;
    int cury = 0;
    maps[curx][cury] = -1;
    q.push(make_pair(curx, cury));
    
    while(!q.empty()) {
        auto f = q.front();
        q.pop();
        curx = f.first;
        cury = f.second;
                
        if(curx == n-1 && cury == m-1) {
            possible = true;
            break;
        }
        
        for(int i = 0; i < 4; i ++) {
            if(curx+dx[i] >= 0 && curx+dx[i] < n && cury+dy[i] >= 0 && cury+dy[i] < m && maps[curx+dx[i]][cury+dy[i]] == 1) {
                q.push(make_pair(curx+dx[i], cury+dy[i]));
                maps[curx+dx[i]][cury+dy[i]] = maps[curx][cury]-1;
            }
        }
        
    }
    
    if(maps[n-1][m-1] != 1) answer = -maps[n-1][m-1];

    return answer;
}