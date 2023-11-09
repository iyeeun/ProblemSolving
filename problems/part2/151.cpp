#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int idx1, idx2;
    
    for(int i = n-1; i >= 0; i --) {
        if(deliveries[i] > 0) {
            idx1 = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i --) {
        if(pickups[i] > 0) {
            idx2 = i;
            break;
        }
    }
    
    while(idx1 >= 0 || idx2 >= 0) {
        answer += (max(idx1, idx2)+1);
        
        int tmp1 = 0, tmp2 = 0;
        
        if(idx1 >= 0) {
            while(idx1 >= 0) {
                if(deliveries[idx1] > 0) {
                    if(tmp1 < cap) {
                        deliveries[idx1] --;
                        tmp1 ++;
                    } else break;
                } else idx1 --;
            }
        }
        if(idx2 >= 0) {
            while(idx2 >= 0) {
                if(pickups[idx2] > 0) {
                    if(tmp2 < cap) {
                        pickups[idx2] --;
                        tmp2 ++;
                    } else break;
                } else idx2 --;
            }
        }
    }
    
    return answer*2;
}