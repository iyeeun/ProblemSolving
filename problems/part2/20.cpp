#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int score[7] = {6, 6, 5, 4, 3, 2, 1};
    
    int unknown = 0;
    int correct = 0;
    int idx = 0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(int i = 0; i < 6; i ++) {
        if(lottos[i] == 0) {
            unknown ++;
        } else {
            while(lottos[i] >= win_nums[idx]) {
                if(lottos[i] == win_nums[idx]) {
                    correct ++;
                    break;
                }
                idx ++;
            }
        }
    }
    
    int max = correct + unknown;
    int min = correct;
    
    answer.push_back(score[max]);
    answer.push_back(score[min]);
    
    return answer;
}