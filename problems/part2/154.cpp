#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n, long long l, long long r) {
    long long t = pow(5, n-1);
    long long cur = pow(5, n);
    
    long long nl = l%cur, nr = r%cur;
    
    if(nl == 0) nl = cur;
    if(nr == 0) nr = cur;
        
    if(n == 1) {
        if(nl <= 3 && nr >= 3) return (nr-nl);
        else return (nr-nl+1);
    }
    
    long long lgroup = ((nl-1)/t)+1, rgroup = ((nr-1)/t)+1;    
    long long total = 0;
    
    if(lgroup == rgroup) {
        return solve(n-1, nl, nr);
    }
    
    if(lgroup != 3) {
        total += solve(n-1, nl, lgroup*t);
    }
    for(int i = lgroup+1; i < rgroup; i ++) {
        if(i == 3) continue;
        total += solve(n-1, (i-1)*t+1, t*i);
    }
    if(rgroup != 3) {
        total += solve(n-1, (rgroup-1)*t+1, nr);
    }
        
    return total;
    
    
}

int solution(int n, long long l, long long r) {
    return solve(n, l, r);
}