#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i <= citations[citations.size()-1]; i ++) {
        int cnt = 0;
        for(auto c : citations) {
            if(c >= i) cnt ++;
        }
        if(cnt >= i) answer = i;
    }
    
    
    return answer;
}