#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = -1;

void solve(vector<int> &works, int cnt, int idx) {
    if(cnt == 0) {
        long long tmp = 0;
        for(auto w : works) {
            tmp += (w*w);
        }
        if(answer == -1 || tmp < answer) answer = tmp;
        return;
    }
    
    for(int i = idx; i < works.size(); i ++) {
        if(works[i] <= 0) {
            solve(works, cnt-1, i);
            continue;
        }
        works[i] --;
        solve(works, cnt-1, i);
        works[i] ++;
    }
}

long long solution(int n, vector<int> works) {
    solve(works, n, 0);
    
    return answer;
}