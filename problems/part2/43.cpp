#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long m = n+1;
    int ncnt = 0;
    while(n > 0) {
        if(n % 2 == 1) ncnt ++;
        n /= 2;
    }
    
    while(true) {
        int t = m;
        int onecnt = 0;
        while(t > 0) {
            if(t % 2 == 1) onecnt ++;
            t /= 2;
        }
        if(onecnt == ncnt) {
            answer = m;
            break;
        }
        m ++;
    }
    
    return answer;
}