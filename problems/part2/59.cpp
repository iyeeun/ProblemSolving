#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for(long long i = 0; i < (long long) n*n; i += n) {
        if(i < (left/n)*n) continue;
        if(i > right) break;
        
        int first = i/n + 1;
                
        long long idx = 0;
        for(long long j = 0; j < first; j ++) {
            if(i+j >= left && i+j <= right) {
                answer.push_back(first);
            }
            idx = j;
            // if(i+j > right) break;
        }
        
        int num = first+1; 
        for(long long j = idx + 1; j < n; j ++) {
            if(i+j >= left && i+j <= right) answer.push_back(num);
            num ++;
            // if(i+j > right) break;
        }
    }
            
    return answer;
}