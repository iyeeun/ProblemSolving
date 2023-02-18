#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    deque<int> dq(people.begin(), people.end());

    while(dq.size() > 0) {
        if(dq.size() != 1 && dq[0] + dq[dq.size()-1] <= limit) {
            dq.pop_front();
            dq.pop_back();
        } else {
            dq.pop_front();
        }
        answer ++;
    }
    
    return answer;
}