#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    vector<pair<int, int> > arr;
    
    if(yellow == 1) {
        answer[0] = 3;
        answer[1] = 3;
        return answer;
    }
    
    int tmp = yellow;
    for(int i = 1; i <= yellow; i ++) {
        if(i > yellow/i) break;
        if(yellow % i == 0) {
            arr.push_back(make_pair(i, yellow/i));
        }
    }
    
    for(int i = 0; i < arr.size(); i ++) {
        if(((arr[i].first + arr[i].second + 2) * 2) == brown) {
            
            answer[0] = arr[i].second + 2;
            answer[1] = arr[i].first + 2;
        }
    }
    
    return answer;
}