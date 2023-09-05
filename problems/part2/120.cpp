#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 1;
    
    vector<long long> nums;
    for(long long i = k * (d/k); i > 0; i -= k) nums.push_back(i);
    
    for(int i = 0; i < nums.size(); i ++) {
        long long cur = nums[i];
        long long t = sqrt(pow(d, 2) - pow(cur, 2));
        if(cur <= t) {
            answer += ((2*(cur/k + 1)) - 1);
        } else {
            answer += (2*((t/k) + 1));
        }
    }
    
    return answer;
}