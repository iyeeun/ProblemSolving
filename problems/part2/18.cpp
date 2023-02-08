#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int s[3] = {0, };
    int scores[3];
    char bonus[3];
    char opt[3] = {'0', '0', '0'};
    int idx = -1;
    
    for(int i = 0; i < dartResult.length(); i ++) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9') {
            idx ++;
            if(dartResult[i] == '1' && dartResult[i+1] == '0') {
                scores[idx] = 10;
                i ++;
            } else {
                scores[idx] = dartResult[i] - '0';
            }
        } else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            bonus[idx] = dartResult[i];
        } else {
            opt[idx] = dartResult[i];
        }
    }
    
    for(int i = 0; i < 3; i ++) {
        if(bonus[i] == 'S') {
            s[i] += scores[i];
        } else if(bonus[i] == 'D') {
            s[i] += scores[i]*scores[i];
        } else if(bonus[i] == 'T') {
            s[i] += scores[i]*scores[i]*scores[i];
        }
        if(opt[i] == '*') {
            s[i] *= 2;
            if(i != 0) s[i-1] *= 2;
        } else if(opt[i] == '#') {
            s[i] *= -1;
        }
    }
    
    answer = s[0] + s[1] + s[2];
    
    return answer;
}