#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int total = 0, visit = 0;
    
    for(int i = 0; i < len; i ++) {
        if(name[i] != 'A') total ++;
    }
    
    int i = 0, j = 0;
    while(visit < total) {
        int cur = name[i] - 'A';
        if(cur < 13) {
            answer += cur;
        } else {
            answer += (26 - cur);
        }
        if(cur != 0) visit ++;
        if(visit == total) break;
        
        int dist = 1;
        int left = i-1, right = i+1;
        int ldist = 1, rdist = 1;
        
        for(int t = 0; t < len; t ++) {
            if(left < 0) left += len;
            if(name[left] != 'A') break;
            left --;
            ldist ++;
        }
        
        for(int t = 0; t < len; t ++) {
            if(right >= len) right -= len;
            if(name[right] != 'A') break;
            right ++;
            rdist ++;
        }
        
        if(ldist == 1 && rdist == 1) {
            j = right;
            answer ++;
        } else if(left == right) {
            j = left;
            answer += min(ldist, rdist);
        } else if(ldist < rdist) {
            j = left;
            answer += ldist;
        } else if(ldist >= rdist) {
            j = right;
            answer += rdist;
        }
        i = j;
    }
    
    return answer;
}