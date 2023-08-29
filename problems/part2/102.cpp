#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int n = queue1.size();
    
    int idx1 = 0, idx2 = n;
    unsigned long sum1 = 0, sum2 = 0;
    
    for(auto i : queue1) sum1 += i;
    for(auto i : queue2) sum2 += i;
    
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    
    int tmp = 0;
    
    while(idx2 != 0) {
        if(sum1 < sum2) {
            sum1 += queue1[idx2];
            sum2 -= queue1[idx2];
            idx2 = (idx2 + 1) % (2*n);  
        } else if(sum1 > sum2) {
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            idx1 = (idx1 + 1) % (2*n);
        } else {
            answer = tmp;
            break;
        }
        tmp ++;
    }
    
    return answer;
}