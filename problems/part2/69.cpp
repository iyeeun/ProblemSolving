#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string, int> dict;
    
    for(int i = 0; i < players.size(); i ++) {
        dict.insert(make_pair(players[i], i));
    }
    
    for(auto i : callings) {
        int target = dict[i];
        dict[i] --;
        string tmp = answer[target];
        answer[target] = answer[target-1];
        dict[answer[target-1]] ++;
        answer[target-1] = tmp;
    }
    
    
    return answer;
}