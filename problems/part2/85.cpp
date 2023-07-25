#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<bool> contain(27, false);
    for(char c : skill) contain[c-'A'] = true;
    
    for(string s : skill_trees) {
        int idx = 0;
        bool ok = true;
        for(char c : s) {
            if(!contain[c-'A']) continue;
            if(c == skill[idx]) {
                idx ++;
            } else {
                ok = false;
                break;
            }
        }
        if(ok) answer ++;
    }
    
    return answer;
}