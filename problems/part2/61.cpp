#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    stack<int> s;
    
    int first = ceil((100 - progresses[0]) / (double) speeds[0]);
    s.push(first);

    for(int i = 1; i < progresses.size(); i ++) {
        int day = ceil((100 - progresses[i]) / (double) speeds[i]);
        if(day <= first) {
            s.push(day);
        } else {
            int cnt = 0;
            while(!s.empty()) {
                s.pop();
                cnt ++;
            }
            answer.push_back(cnt);
            first = day;
            s.push(day);
        }
    }
    
    int cnt = 0;
    while(!s.empty()) {
        s.pop();
        cnt ++;
    }
    answer.push_back(cnt);
    
    return answer;
}