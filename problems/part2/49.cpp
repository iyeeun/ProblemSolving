#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i ++) {
        int n = arr[i];
        int minnum = min(n, answer);
        int maxnum = max(n, answer);
        int newnum = minnum * maxnum;
        
        while(minnum > 0) {
            int tmp = maxnum % minnum;
            maxnum = minnum;
            minnum = tmp;
        }
        
        answer = newnum / maxnum;
        
    }
    
    return answer;
}