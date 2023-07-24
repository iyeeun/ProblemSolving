#include <string>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &answer, int n, int src, int dst) {
    if(n == 0) return;
    
    solve(answer, n-1, src, 6-src-dst);
    answer.push_back({src, dst});
    solve(answer, n-1, 6-src-dst, dst);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    solve(answer, n, 1, 3);
    return answer;
}