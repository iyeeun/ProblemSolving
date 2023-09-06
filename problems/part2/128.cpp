#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = -1;
    map<string, int> m{{"diamond", 0}, {"iron", 1}, {"stone", 2}};
    
    int damage[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
    
    vector<int> tools;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < picks[i]; j ++) {
            tools.push_back(i);
        }
    }
    
    while(true) {
        int tmp = 0;
        for(int i = 0; i < min(minerals.size(), tools.size()*5); i ++) {
            tmp += damage[tools[i/5]][m[minerals[i]]];
        }
        if(answer == -1 || tmp < answer) answer = tmp;
        if(!next_permutation(tools.begin(), tools.end())) break;
    }
    
    return answer;
}