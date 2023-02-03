#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr(n+1, 1);
    
    for(int i = 2; i <= sqrt(n); i ++) {
        if(arr[i] == 0) continue;
        for(int j = 2*i; j <= n; j += i) {
            arr[j] = 0;
        }
    }
    
    for(int i = 2; i <= n; i ++) {
        if(arr[i] == 1) answer ++;
    }
    
    return answer;
}