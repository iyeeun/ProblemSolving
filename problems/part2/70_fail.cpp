#include <string>
#include <vector>

using namespace std;

int answer = -1;

bool visit[10] = {false};

void explore(vector<vector<int>> &dungeons, int tot, int num, int k) {
    if(tot == dungeons.size()) {
        if(num > answer) answer = num;
        return;
    }

    for(int i = 0; i < dungeons.size(); i ++) {
        if(visit[i]) continue;
        
        if(k >= dungeons[i][0]) {
            k -= dungeons[i][1];
            num ++;
        }
        explore(dungeons, tot+1, num, k);
        visit[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    explore(dungeons, 0, 0, k);
    
    return answer;
}