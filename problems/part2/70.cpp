#include <string>
#include <vector>

using namespace std;

int answer = -1;

bool visit[10] = {false};

void explore(vector<vector<int>> &dungeons, int num, int k) {
    for(int i = 0; i < dungeons.size(); i ++) {
        if(visit[i]) continue;
        if(k >= dungeons[i][0]) {
            visit[i] = true;
            explore(dungeons, num+1, k-dungeons[i][1]);
            visit[i] = false;
        }
    }
    if(num > answer) answer = num;
}

int solution(int k, vector<vector<int>> dungeons) {
    explore(dungeons, 0, k);
    
    return answer;
}