#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0; i < discount.size(); i ++) {
        map<string, int> m;
        for(int j = 0; j < want.size(); j ++) {
            m.insert(make_pair(want[j], 0));
        }
        for(int j = 0; j < 10; j ++) {
            if(i+j >= discount.size()) continue;
            if(find(want.begin(), want.end(), discount[i+j]) != want.end()) {
                m[discount[i+j]] ++;
            }
        }
        bool poss = true;
        for(int j = 0; j < number.size(); j ++) {
            if(number[j] != m[want[j]]) {
                poss = false;
                break;
            }
        }
        if(poss) answer ++;
    }
    
    return answer;
}