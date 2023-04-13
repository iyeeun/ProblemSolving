#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> q;
    
    for(auto p : priorities) q.push(p);
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    int maxidx = 0;
    
    while(!q.empty()) {
        int fr = q.front();
        if(fr == priorities[maxidx]) {
            q.pop();
            answer ++;
            maxidx ++; 
            if(location == 0) break;
        } else {
            q.pop();
            q.push(fr);
        }
        location --;
        if(location == -1) location = q.size()-1;
    }
    
    return answer;
}