#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int pick = 0;
    vector<int> types(*max_element(tangerine.begin(), tangerine.end())+1, 0);
    
    for(int i = 0; i < tangerine.size(); i ++) {
        types[tangerine[i]] ++;
    }
    
    sort(types.begin(), types.end(), greater<int>());
    
    for(auto t : types) {
        if(pick >= k) break;
        pick += t;
        answer ++;
    }
    
    return answer;
}