#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<bool> rows;
vector<bool> cols;
vector<bool> rt;
vector<bool> lt;

int answer = 0;

void solve(vector<vector<bool>> &arr, int i) {
    int n = arr.size();
    
    if(i == n) {
        answer ++;
        return;
    }
    
    for(int j = 0; j < n; j ++) {
        if(cols[j]) continue;
        if(rt[i+j]) continue;
        if(lt[i+n-1-j]) continue;
        arr[i][j] = true;
        rows[i] = true;
        cols[j] = true;
        rt[i+j] = true;
        lt[i+n-1-j] = true;
        solve(arr, i+1);
        arr[i][j] = false;
        rows[i] = false;
        cols[j] = false;
        rt[i+j] = false;
        lt[i+n-1-j] = false;
    }
    
}



int solution(int n) {
    vector<vector<bool>> arr(n, vector<bool>(n, false));
    rows.assign(n, false);
    cols.assign(n, false);
    rt.assign(2*n-1, false);
    lt.assign(2*n-1, false);
    
    solve(arr, 0);
    
    return answer;
}