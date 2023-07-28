#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<int>> b(m, vector<int>(n));
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < m; j ++) {
            b[i][j] = board[i][j] - 'A';
        }
    }
    
    set<pair<int, int>> remove;
    while(true) {
        for(int i = 0; i < m-1; i ++) {
            for(int j = 0; j < n-1; j ++) {
                if(b[i][j] == -1) continue;
                if(b[i][j] == b[i+1][j] && b[i][j] == b[i][j+1] & b[i][j] == b[i+1][j+1]) {
                    remove.insert(make_pair(i, j));
                    remove.insert(make_pair(i+1, j));
                    remove.insert(make_pair(i, j+1));
                    remove.insert(make_pair(i+1, j+1));
                }
            }
        }
        
        if(remove.size() == 0) break;
        answer += remove.size();
        
        for(auto p : remove) {
            b[p.first][p.second] = -1;
        }
        remove.clear();
        
        for(int i = 0; i < n; i ++) {
            for(int j = m-2; j >= 0; j --) {
                if(b[j][i] == -1) continue;
                int idx = j+1;
                int cnt = 0;
                while(idx < m && b[idx][i] == -1) {
                    cnt ++;
                    idx ++;
                }
                if(cnt != 0) {
                    b[j+cnt][i] = b[j][i];
                    for(int t = 0; t < cnt; t ++) {
                        b[j+t][i] = -1;
                    }
                }
            }
        }
    }
    
    return answer;
}