#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int dx[4][2] = {{0, 0}, {0, 0}, {-1, -2}, {1, 2}};
    int dy[4][2] = {{-1, -2}, {1, 2}, {0, 0}, {0, 0}};
    
    int digx[] = {-1, 1, -1, 1};
    int digy[] = {-1, -1, 1, 1};
    
    for(vector<string> place : places) {
        bool ok = true;
        vector<vector<bool>> visit(5, vector<bool>(5, false));
        
        for(int i = 0; i < 5; i ++) {
            for(int j = 0; j < 5; j ++) {
                char c = place[i][j];
                if(c != 'P') continue;
                
                for(int dir = 0; dir < 4; dir ++) {
                    for(int t = 0; t < 2; t ++) {
                        int newx = i + dx[dir][t];
                        int newy = j + dy[dir][t];
                        if(newx < 0 || newx > 4 || newy < 0 || newy > 4) continue;
                        if(visit[newx][newy]) continue;
                        
                        if(place[newx][newy] == 'O') {
                            visit[newx][newy] = true;
                        } else if(place[newx][newy] == 'X') {
                            break;
                        } else if(place[newx][newy] == 'P') {
                            ok = false;
                            dir = 4;
                            j = 5;
                            i = 5;
                            break;
                        }
                    }
                    
                    int newx = i + digx[dir];
                    int newy = j + digy[dir];
                    if(newx < 0 || newx > 4 || newy < 0 || newy > 4) continue;
                    if(visit[newx][newy]) continue;
                    
                    if(place[newx][newy] == 'X' || place[newx][newy] == 'O') {
                        visit[newx][newy] = true;
                    } else if(place[newx][newy] == 'P') {
                        if(place[i][newy] == 'X' && place[newx][j] == 'X') {
                            visit[newx][newy] = true;
                        } else {
                            ok = false;
                            dir = 4;
                            j = 5;
                            i = 5;
                            break;
                        }
                    }
                }
                
                
            }
        }
        if(ok) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}