#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string tmp;
    
    for(int i = 0; i <= t.length()-p.length(); i ++) {
        tmp = "";
        for(int j = i; j < i+p.length(); j ++) {
            tmp += t[j];
        }
        if(tmp <= p) {
            answer ++;
        }
    }
    
    return answer;
}