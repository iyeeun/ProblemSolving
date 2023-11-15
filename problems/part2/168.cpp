#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = -1;
    
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < k; i ++) q.push(make_pair(stones[i], i));
    answer = q.top().first;
    
    for(int i = k; i < stones.size(); i ++) {
        q.push(make_pair(stones[i], i));
        if(q.size() >= k) {
            while(q.top().second < i-k+1) q.pop();
            if(answer == -1 || answer > q.top().first) answer = q.top().first;
        }
    }
    
    return answer;
}