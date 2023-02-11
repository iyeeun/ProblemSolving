#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i ++) {
        int num = n / i;
        int sum = 0;
        int start = num-((i-1)/2);
        if(start < 1) break;
        for(int j = 0; j < i; j ++) {
            sum += start+j;
            if(sum == n) {
                answer ++;
                break;
            } else if(sum > n) {
                break;
            }
        }
        cout << endl;
        if(start == 1) break;
    }
    
    
    return answer;
}