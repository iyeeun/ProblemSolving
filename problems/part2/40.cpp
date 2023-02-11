#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int len = s.length();
    int numzero = 0;
    
    while(len > 1) {
        answer[0] ++;
        cout << s << endl;
        for(int i = 0; i < len; i ++) {
            if(s[i] == '0') numzero ++;
        }
        int newlen = len - numzero;
        s = "";
        while(newlen > 0) {
            int tmp = newlen % 2;
            newlen /= 2;
            s = to_string(tmp) + s;
        }
        answer[1] += numzero;
        len = s.length();
        numzero = 0;
    }    
    
    return answer;
}