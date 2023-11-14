#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<bool> visit(n+1, false);
    for(int i = 0; i < stations.size(); i ++) {
        for(int j = stations[i]-w; j <= stations[i]+w; j ++) {
            if(j < 0 || j > n) continue;
            visit[j] = true;
        }
    }
    
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(!visit[i]) {
            num ++;
            if(num == 2*w+1) {
                answer ++;
                num = 0;
            }
        } else {
            if(num != 0) answer ++;
            num = 0;
        }
    }
    if(num != 0) answer ++;

    return answer;
}