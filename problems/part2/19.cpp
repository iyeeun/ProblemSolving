#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), compare);
    
    if(score.size() / m == 0) {
        return answer;
    }
    
    for(int i = m-1; i < score.size(); i += m) {
        answer += score[i] * m;
    }
    
    return answer;
}