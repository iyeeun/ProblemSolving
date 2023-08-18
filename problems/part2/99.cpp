#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= i; j ++) {
            arr[i].push_back(0);
        }
    }
    int x = 0, y = 0;
    int dir = 0;
    
    for(int i = 1; i <= n*(n+1)/2; i ++) {
        arr[x][y] = i;
        int nx = x, ny = y;
        if(dir == 0) {
            nx ++;
        } else if(dir == 1) {
            ny ++;
        } else if(dir == 2) {
            nx --;
            ny --;
        }
        if(!(nx >= 0 && nx < n && ny >= 0 && ny <= nx && arr[nx][ny] == 0)) {
            dir = (dir+1) % 3;
            if(dir == 0) {
                nx = x + 1;
                ny = y;
            } else if(dir == 1) {
                nx = x;
                ny = y + 1;
            } else if(dir == 2) {
                nx = x-1;
                ny = y-1;
            }
        } 
        x = nx;
        y = ny;
    }
    
    for(auto i : arr) {
        for(auto j : i) {
            answer.push_back(j);
        }
    }
    
    return answer;
}