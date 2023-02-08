#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> nums(n+1, 1);
    
    for(int i = 0; i < lost.size(); i ++) {
        nums[lost[i]] --;
    }
    
    for(int i = 0; i < reserve.size(); i ++) {
        nums[reserve[i]] ++;
    }
    
    for(int i = 1; i <= n; i ++) {
        if(nums[i] == 2) {
            answer ++;
            if(i >= 1 && nums[i-1] == 0) {
                answer ++;
            } else if(i < n && nums[i+1] == 0) {
                answer ++;
            }
        } else if(nums[i] == 1) {
            answer ++;
        }
    }
    
    answer = (answer > n)? n : answer;
    
    return answer;
}