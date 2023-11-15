#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int> parent, int n) {
    if(parent[n] == n) return n;
    else return getParent(parent, parent[n]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
        return a[2] < b[2];
    });
    vector<int> parent(n);
    for(int i = 0; i < n; i ++) parent[i] = i;
    
    for(int idx = 0; idx < costs.size(); idx ++) {
        int p1 = getParent(parent, costs[idx][0]);
        int p2 = getParent(parent, costs[idx][1]);
        
        if(p1 != p2) {
            parent[p2] = p1;
            answer += costs[idx][2];
        }
    }
        
    return answer;
}