#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
        
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    });
    
    vector<int> path = routes[0];
    for(int i = 1; i < routes.size(); i ++) {
        path[0] = max(path[0], routes[i][0]);
        path[1] = min(path[1], routes[i][1]);
        if(path[1] < path[0]) {
            answer ++;
            path = routes[i];
        }
    }
    if(path[0] <= path[1]) answer ++;
    
    return answer;
}