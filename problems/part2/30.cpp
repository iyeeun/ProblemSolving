#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    while(!s.empty()) {
        char x = s[0];
        int x_cnt = 0;
        int not_x_cnt = 0;
        int i;
        for(i = 0; i < s.length(); i ++) {
            if(s[i] == x) x_cnt ++;
            else not_x_cnt ++;
            if(x_cnt == not_x_cnt) break;
        }
        if(i >= s.length()) {
            s = "";
            answer ++;
            continue;
        }
        s = s.substr(i+1, s.length()-i-1);
        answer ++;
    }
    
    return answer;
}