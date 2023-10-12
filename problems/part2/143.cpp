#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    vector<vector<vector<bool>>> lines(55, vector<vector<bool>>(55, vector<bool>(4, false)));
    // left, right, up, down
    
    for(int i = 0; i < rectangle.size(); i ++) {
        auto rect1 = rectangle[i];
        int xd1 = rect1[0], yd1 = rect1[1], xu1 = rect1[2], yu1 = rect1[3];
        // left & right
        for(int t = xd1; t < xu1; t ++) {
            lines[t][yd1][1] = true;
            lines[t][yu1][1] = true;
            lines[t+1][yd1][0] = true;
            lines[t+1][yu1][0] = true;
        }
        // up & down
        for(int t = yd1; t < yu1; t ++) {
            lines[xd1][t][2] = true;
            lines[xu1][t][2] = true;
            lines[xd1][t+1][3] = true;
            lines[xu1][t+1][3] = true;
        }

        for(int j = 0; j < rectangle.size(); j ++) {
            if(i == j) continue;
            auto rect2 = rectangle[j];
            int xd2 = rect2[0], yd2 = rect2[1], xu2 = rect2[2], yu2 = rect2[3];
            // left side
            if(xd1 > xd2 && xd1 < xu2) {
                for(int t = max(yd1, yd2); t < min(yu1, yu2); t ++) {
                    lines[xd1][t][2] = false;
                    lines[xd1][t+1][3] = false;
                }
            }
            // right side
            if(xu1 > xd2 && xu1 < xu2) {
                for(int t = max(yd1, yd2); t < min(yu1, yu2); t ++) {
                    lines[xu1][t][2] = false;
                    lines[xu1][t+1][3] = false;
                }
            }
            // down side
            if(yd1 > yd2 && yd1 < yu2) {
                for(int t = max(xd1, xd2); t < min(xu1, xu2); t ++) {
                    lines[t][yd1][1] = false;
                    lines[t+1][yd1][0] = false;
                }
            }
            // up side
            if(yu1 > yd2 && yu1 < yu2) {
                for(int t = max(xd1, xd2); t < min(xu1, xu2); t ++) {
                    lines[t][yu1][1] = false;
                    lines[t+1][yu1][0] = false;
                }
            }
        }
    }
        
    // BFS
    
    vector<vector<vector<int>>> dist(55, vector<vector<int>>(55, vector<int>(4, -1)));
    dist[characterX][characterY][0] = 0;
    
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(characterX, characterY, 0));
    while(!q.empty()) {
        int x, y, dir;
        tie(x, y, dir) = q.front();
        q.pop();
                                
        // left
        if(lines[x][y][0] && dist[x-1][y][0] == -1) {
            dist[x-1][y][0] = dist[x][y][dir] + 1;
            q.push(make_tuple(x-1, y, 0));
        }
        // right
        if(lines[x][y][1] && dist[x+1][y][1] == -1) {
            dist[x+1][y][1] = dist[x][y][dir] + 1;
            q.push(make_tuple(x+1, y, 1));
        }
        // up
        if(lines[x][y][2] && dist[x][y+1][2] == -1) {
            dist[x][y+1][2] = dist[x][y][dir] + 1;
            q.push(make_tuple(x, y+1, 2));
        }
        // down
        if(lines[x][y][3] && dist[x][y-1][3] == -1) {
            dist[x][y-1][3] = dist[x][y][dir] + 1;
            q.push(make_tuple(x, y-1, 3));
        }   
    }
            
    for(int i = 0; i < 4; i ++) {
        if(dist[itemX][itemY][i] == -1) continue;
        if(answer == 0 || answer > dist[itemX][itemY][i]) {
            answer = dist[itemX][itemY][i];
        }
    }
    
    return answer;
}