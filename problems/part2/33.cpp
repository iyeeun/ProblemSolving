#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for(int i = 0; i < s.length(); i ++) {
        char c = s[i];
        
        int n = 0;
        int idx = 0;
        while(n < index) {
            idx ++;
            n ++;
            if(c+idx > 'z') c -= 26;
            for(int t = 0; t < skip.length(); t ++) {
                if(skip[t] == c+idx) {
                    n --;
                }
            }
        }
        answer += c+idx;
    }
    
    return answer;
}