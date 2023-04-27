#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> &v, int target, int cur, int sum) {
    if(cur == v.size()) {
        if(sum == target) {
            answer ++;
        }
        return;
    }
    
    dfs(v, target, cur+1, sum+v[cur]);
    dfs(v, target, cur+1, sum-v[cur]);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}