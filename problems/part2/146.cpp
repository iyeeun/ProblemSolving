#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0]) return a[1] < b[2];
    else return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    
    
    sort(targets.begin(), targets.end(), cmp);
    
    pair<int, int> range = make_pair(targets[0][0], targets[0][1]);
    int answer = 1;
    
    for(auto t : targets) {
        if(t[0] >= range.second) {
            // out of range
            range = make_pair(t[0], t[1]);
            answer ++;
        } else {
            range = make_pair(max(t[0], range.first), min(t[1], range.second));
        }
    }
    
    return answer;
}