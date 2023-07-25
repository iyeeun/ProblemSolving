#include <string>
#include <vector>

using namespace std;

vector<string> alpha({"A", "E", "I", "O", "U"});
int cnt = 0;
int answer = 0;

void dfs(string str, string target) {
    if(str == target) {
        answer = cnt;
        return;
    }
    
    if(str.length() > 5) return;
    
    cnt ++;
    for(string c : alpha) {
        dfs(str+c, target);
    }
        
}

int solution(string word) {
    dfs("", word);
    
    return answer;
}