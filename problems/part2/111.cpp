#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> arr(rows, vector<int>(columns));
    for(int i = 0; i < rows; i ++) {
        for(int j = 0; j < columns; j ++) {
            arr[i][j] = i*columns + j + 1;
        }
    }
    
            
    for(vector<int> q : queries) {
        for(int i = 0; i < q.size(); i ++) q[i] --;
                
        // right
        int tmp1 = arr[q[0]][q[3]];
        int minnum = tmp1;
        for(int i = q[3]; i > q[1]; i --) {
            arr[q[0]][i] = arr[q[0]][i-1];
            minnum = min(minnum, arr[q[0]][i-1]);
        }
        
        // down
        int tmp2 = arr[q[2]][q[3]];
        minnum = min(minnum, tmp2);
        for(int i = q[2]; i > q[0]+1; i --) {
            arr[i][q[3]] = arr[i-1][q[3]];
            minnum = min(minnum, arr[i-1][q[3]]);
        }
        arr[q[0]+1][q[3]] = tmp1;
        
        // left
        tmp1 = arr[q[2]][q[1]];
        minnum = min(minnum, tmp1);
        for(int i = q[1]; i < q[3]-1; i ++) {
            arr[q[2]][i] = arr[q[2]][i+1];
            minnum = min(minnum, arr[q[2]][i+1]);
        }
        arr[q[2]][q[3]-1] = tmp2;
        
        // up
        for(int i = q[0]; i < q[2]; i ++) {
            arr[i][q[1]] = arr[i+1][q[1]];
            minnum = min(minnum, arr[i+1][q[1]]);
        }
        arr[q[2]-1][q[1]] = tmp1;

        answer.push_back(minnum);
    }
    
    
    
    return answer;
}