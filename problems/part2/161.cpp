#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    for(int i = 0; i < n; i ++) {
        
        while(idx < n && A[i] >= B[idx]) idx ++;
        if(idx == n) break;
        answer ++;
        idx ++;
    }
    
    return answer;
}