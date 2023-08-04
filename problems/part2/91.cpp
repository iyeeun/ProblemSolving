#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    set<int> prev;
    set<int> nums;
    nums.insert(x);
    
    int ops = 0;
    
    while(!nums.empty()) {
        for(int num : nums) {
            if(num == y) {
                answer = ops;
            }
        }
        
        if(answer != -1) break;
        
        prev = nums;
        nums.clear();
        
        for(int p : prev) {
            
            if(p+n <= y) nums.insert(p+n);
            if(2*p <= y) nums.insert(2*p);
            if(3*p <= y) nums.insert(3*p);
        }
        ops ++;
    }
    
    return answer;
}