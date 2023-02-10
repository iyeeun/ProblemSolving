#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int isfirst = 1;
    for(int i = 0; i < s.length(); i ++) {
        char c = s[i];
        if(c >= '0' && c <= '9') {
            answer += c;
            isfirst = 0;
        } else if(c == ' ') {
            isfirst = 1;
            answer += c;
        } else {
            if(isfirst) {
                if(c >= 'A' && c <= 'Z') {
                    answer += c;
                } else {
                    answer += c-'a'+'A';
                }
                isfirst = 0;
            } else {
                if(c >= 'A' && c <= 'Z') {
                    c = c-'A'+'a';
                    answer += c;
                } else {
                    answer += c;
                }
            }
        }
    }
    
    return answer;
}