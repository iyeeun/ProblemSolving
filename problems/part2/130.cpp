#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    if(k >= enemy.size()) return enemy.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int e : enemy) {
        pq.push(e);
        
        if(pq.size() > k) {
            n -= pq.top();
            pq.pop();
            if(n < 0) break;
        }
        answer ++;
    }
    
    return answer;
}