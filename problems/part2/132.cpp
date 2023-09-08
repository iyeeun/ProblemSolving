#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long i = 1; i < r2; i ++) {
        long double val = sqrt(pow(r2, 2) - pow(i, 2));
        answer += (long long) val;
    }
        
    for(long long i = 1; i < r1; i ++) {
        long double val = sqrt(pow(r1, 2) - pow(i, 2));
        if(val == floor(val)) val --;
        answer -= (long long) val;
    }
    
    answer *= 4;
    
    // x축, y축 위의 점
    answer += ((r2 - r1 + 1) * 4);
    
    return answer;
}