#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    vector<pair<int, int>> candidates;
    
    int start = 0, end = 1;
    long sum = sequence[0];
    
    while(end <= sequence.size() && start < sequence.size()) {
        if(sum < k) {
            sum += sequence[end];
            end ++;
        } else if(sum > k) {
            sum -= sequence[start];
            start ++;
        } else {
            candidates.push_back(make_pair(start, end-1));
            sum += sequence[end];
            end ++;
        }
    }
    
    int len = -1, shortest = 0;
    for(int i = 0; i < candidates.size(); i ++) {
        pair<int, int> c = candidates[i];
        if(len == -1) len = c.second - c.first;
        else {
            int t = c.second - c.first;
            if(t < len) {
                len = t;
                shortest = i;
            }
        }
    }
        
    answer[0] = candidates[shortest].first;
    answer[1] = candidates[shortest].second;
    
    return answer;
}