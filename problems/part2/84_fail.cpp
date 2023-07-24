#include <string>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    vector<vector<bool>> updown(10, vector<bool>(11, false));
    vector<vector<bool>> leftright(11, vector<bool>(10, false));
    
    int x = 0;
    int y = 0;
    
    int num = 0;
    for(char c : dirs) {
        if(c == 'U') {
            y ++;
            if(y > 5) y = 5;
            if(!updown[5-y][5+x]) {
                updown[5-y][5+x] = true;
                answer ++;
            }
        } else if(c == 'D') {
            y --;
            if(y < -5) y = -5;
            if(!updown[4-y][5+x]) {
                updown[4-y][5+x] = true;
                answer ++;
            }
        } else if(c == 'L') {
            x --;
            if(x < -5) x = -5;
            if(!leftright[5-y][5+x]) {
                leftright[5-y][5+x] = true;
                answer ++;
            }
        } else if(c == 'R') {
            x ++;
            if(x > 5) x = 5;
            if(!leftright[5-y][4+x]) {
                leftright[5-y][4+x] = true;
                answer ++;
            }
        }
    }
    
    
    return answer;
}