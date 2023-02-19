#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> cases(n+1);
    cases[1] = 1;
    cases[2] = 2;
    
    for(int i = 3; i <= n; i ++) {
        cases[i] = (cases[i-1] + cases[i-2]) % 1234567;
    }
    
    answer = cases[n];
    
    return answer;
}