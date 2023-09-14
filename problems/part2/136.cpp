#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end-begin+1, 1);
    
    for(int i = begin; i <= end; i ++) {
        if(i == 1) {
            answer[i-begin] = 0;
        }
        for(int j = 2; j*j <= i; j ++) {
            if(i % j == 0) {
                if(i/j <= 10000000) {
                    answer[i-begin] = i/j;
                    break;
                } else {
                    answer[i-begin] = j;
                }
            }
        }  
    }
    
    return answer;
}