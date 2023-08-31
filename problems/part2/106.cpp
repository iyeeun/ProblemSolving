#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<string> maps) { 
    vector<int> answer;
    vector<vector<int>> arr(maps.size(), vector<int>(maps[0].size()));
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    
    for(int i = 0; i < maps.size(); i ++) {
        for(int j = 0; j < maps[0].size(); j ++) {
            if(maps[i][j] == 'X') arr[i][j] = -1;
            else arr[i][j] = maps[i][j] - '0';
        }
    }
    
    for(int i = 0; i < arr.size(); i ++) {
        for(int j = 0; j < arr[0].size(); j ++) {
            if(arr[i][j] > 0) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                int sum = arr[i][j];
                arr[i][j] = 0;
                
                while(!q.empty()) {
                    auto fr = q.front();
                    q.pop();

                    int x = fr.first, y = fr.second;

                    for(int i = 0; i < 4; i ++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size() && arr[nx][ny] > 0) {
                            q.push(make_pair(nx, ny));
                            sum += arr[nx][ny];
                            arr[nx][ny] = 0;
                        }
                    } 
                }
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}