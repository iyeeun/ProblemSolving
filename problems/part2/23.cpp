#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    answer = participant[participant.size()-1];
    
    int p_idx = 0, c_idx = 0;
    for(int i = 0; i < participant.size()-1; i ++) {
        if(participant[p_idx] != completion[c_idx]) {
            answer = participant[p_idx];
            break;
        }
        p_idx ++;
        c_idx ++;
    }
    
    return answer;
}