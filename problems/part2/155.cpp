#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(auto b : balls) {
        int val, ans = -1;
        
        // up
        if(!(startX == b[0] && startY < b[1])) {
            val = pow(abs(startX-b[0]), 2) + pow((n-b[1])+(n-startY), 2);
            if(ans == -1 || ans > val) ans = val;
        }
            
        // down
        if(!(startX == b[0] && startY > b[1])) {
            val = pow(abs(startX-b[0]), 2) + pow(startY+b[1], 2);
            if(ans == -1 || ans > val) ans = val;
        }
        
        // left
        if(!(startY == b[1] && startX > b[0])) {
            val = pow(abs(startY-b[1]), 2) + pow(startX+b[0], 2);
            if(ans == -1 || ans > val) ans = val;
        }
            
        // right
        if(!(startY == b[1] && startX < b[0])) {
            val = pow(abs(startY-b[1]), 2) + pow((m-startX)+(m-b[0]), 2);
            if(ans == -1 || ans > val) ans = val;
        }
                
        answer.push_back(ans);        
    }
    
    return answer;
}