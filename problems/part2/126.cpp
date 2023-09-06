#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    // board init
    pair<int, int> start, end;
    vector<vector<int>> arr(board.size(), vector<int>(board[0].length(), 0));
    for(int i = 0; i < board.size(); i ++) {
        for(int j = 0; j < board[0].length(); j ++) {
            if(board[i][j] == 'R') start = make_pair(i, j);
            else if(board[i][j] == 'G') end = make_pair(i, j);
            else if(board[i][j] == 'D') arr[i][j] = -1;
        }
    }
    
    // visit init
    vector<vector<vector<int>>> dist(board.size(), vector<vector<int>>(board[0].length(), vector<int>(4, -1)));
    
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(start.first, start.second, 0));
    for(int i = 0; i < 4; i ++) dist[start.first][start.second][i] = 0;
    
    while(!q.empty()) {
        int x, y, dir;
        tie(x, y, dir) = q.front();
        q.pop();
                
        if(x == end.first && y == end.second) break;
        
        int nx, ny;
        
        // up
        nx = x;
        while(nx >= 1) {
            if(arr[nx-1][y] == 0) {
                nx --;
            } else break;
        }
        if(dist[nx][y][0] == -1) {
            q.push(make_tuple(nx, y, 0));
            dist[nx][y][0] = dist[x][y][dir] + 1;
        }
        
        // down
        nx = x;
        while(nx < arr.size()-1) {
            if(arr[nx+1][y] == 0) {
                nx ++;
            } else break;
        }
        if(dist[nx][y][1] == -1) {
            q.push(make_tuple(nx, y, 1));
            dist[nx][y][1] = dist[x][y][dir] + 1;
        }
        
        // left
        ny = y;
        while(ny > 0) {
            if(arr[x][ny-1] == 0) {
                ny --;
            } else break;
        }
        if(dist[x][ny][2] == -1) {
            q.push(make_tuple(x, ny, 2));
            dist[x][ny][2] = dist[x][y][dir] + 1;
        }
        
        // right
        ny = y;
        while(ny < arr[0].size()-1) {
            if(arr[x][ny+1] == 0) {
                ny ++;
            } else break;
        }
        if(dist[x][ny][3] == -1) {
            q.push(make_tuple(x, ny, 3));
            dist[x][ny][3] = dist[x][y][dir] + 1;
        }
        
    }
    
    for(int i = 0; i < 4; i ++) {
        if(dist[end.first][end.second][i] == -1) continue;
        if(answer == -1 || dist[end.first][end.second][i] < answer) {
            answer = dist[end.first][end.second][i];
        }
    }
    
    return answer;
}