#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int idx_vec[26] = {0};
    
    for(int i = 0; i < s.length(); i ++) {
        int idx = s[i] - 'a';
        if(idx_vec[idx] == 0) answer.push_back(-1);
        else answer.push_back(i-idx_vec[idx]+1);
        idx_vec[idx] = i+1;
    }
    
    return answer;
}