#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i ++) {
        string b = babbling[i];
        
        if(b.find("aya") != string::npos) {
            b.replace(b.find("aya"), 3, "#");
        }
        if(b.find("ye") != string::npos) {
            b.replace(b.find("ye"), 2, "#");
        }
        if(b.find("woo") != string::npos) {
            b.replace(b.find("woo"), 3, "#");
        }
        if(b.find("ma") != string::npos) {
            b.replace(b.find("ma"), 2, "#");
        }
        
        int isRight = 1;
        for(int i = 0; i < b.length(); i ++) {
            if(b[i] != '#') {
                isRight = 0;
                break;
            }
        }
        
        if(isRight) {
            answer ++;
        }
    }
    
    return answer;
}