#include <string>
#include <vector>

using namespace std;

void solve(vector<int> &answer, vector<int> &lst, int n, long long k) {
    if(n == 1) {
        answer.push_back(lst[0]);
        return;
    }
    
    long long fac = 1;
    for(int i = 2; i < n; i ++) fac *= i;
    long long target = (k-1) / fac;
    answer.push_back(lst[target]);
    lst.erase(lst.begin() + target);
    solve(answer, lst, n-1, k - (fac * target));
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> lst;
    for(int i = 1; i <= n; i ++) lst.push_back(i);
    
    solve(answer, lst, n, k);
    
    return answer;
}