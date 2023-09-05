#include <cmath>
#include <algorithm>

using namespace std;

long long solution(int w,int h) {
    long long answer = (long long) w * h;
    
    int g = max(w, h);
    int l = min(w, h);
    int base = 0;
    
    for(int i = 1; i <= g; i ++) {
        long double tmp = i * (l / (double) g);
        if(base < tmp && tmp <= base+1) {
            answer --;
        } else if(tmp > base+1) {
            answer -= 2;
        }
        if(tmp >= base+1) base ++;
    }
    
    return answer;
}