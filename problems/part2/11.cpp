#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int tmp = 0;
    while(true) {
        if(n < a) break;
        tmp = (n / a);
        n -= (tmp*a);
        n += (tmp*b);
        answer += (tmp*b);
    }
    return answer;
}