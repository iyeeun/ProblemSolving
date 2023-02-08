#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> daily;
    
    for(int i = 0; i < score.size(); i ++) {
        if(i < k) {
            daily.push_back(score[i]);
            int min = *min_element(daily.begin(), daily.end());
            answer.push_back(min);
        } else {
            int min = *min_element(daily.begin(), daily.end());
            if(min < score[i]) {
                daily.erase(min_element(daily.begin(), daily.end()));
                daily.push_back(score[i]);
            }
            min = *min_element(daily.begin(), daily.end());
            answer.push_back(min);
        }
    }
    
    return answer;
}