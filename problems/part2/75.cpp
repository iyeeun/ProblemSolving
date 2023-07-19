#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    for(int i = 0; i < scoville.size(); i ++) {
        pq.push(-scoville[i]);
    }
    
    while(-pq.top() < K) {
        int m1 = pq.top();
        pq.pop();
        int m2 = pq.top();
        pq.pop();
        pq.push(m1 + 2*m2);
        answer ++;
        if(pq.size() < 2) {
            if(!pq.empty() && -pq.top() >= K) ;
            else answer = -1;
            break;
        }
    }
    
    return answer;
}