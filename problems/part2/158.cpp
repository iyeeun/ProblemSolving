#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q(works.begin(), works.end());
    
    for(int i = 0; i < n; i ++) {
        int t = q.top();
        q.pop();
        if(t > 0) q.push(t-1);
        else break;
    }
    
    while(!q.empty()) {
        int t = q.top();
        answer += t*t;
        q.pop();
    }
    
    return answer;
}