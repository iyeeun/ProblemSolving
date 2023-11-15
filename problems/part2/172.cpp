#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sz = jobs.size();
    
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    int curtime = 0;
    
    while(jobs.size() > 0) {
        int target = -1;
        
        for(int i = 0; i < jobs.size(); i ++) {
            if(jobs[i][0] > curtime) break;
            if(target == -1 || jobs[target][1] > jobs[i][1]) {
                target = i;
            }
        }
        if(target == -1) {
            curtime = jobs[0][0];
        } else {
            answer += (curtime - jobs[target][0] + jobs[target][1]);
            curtime += jobs[target][1];
            jobs.erase(jobs.begin()+target);
        }
    }
    answer /= sz;
    return answer;
}