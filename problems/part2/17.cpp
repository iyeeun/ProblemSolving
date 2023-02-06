#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    double a_num = 0, b_num = 0;
    if(a.second.second != 0) {
        a_num = a.second.first / double(a.second.second);
    }
    if(b.second.second != 0) {
        b_num = b.second.first / double(b.second.second);
    }
    if(a_num == b_num) {
        return a.first < b.first;   
    } else {
        return a_num > b_num;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, pair<int, int>>> stage_info(N);
    
    int users = stages.size();
    for(int i = 0; i < N; i ++) {
        int cnt = 0;
        for(int j = 0; j < stages.size(); j ++) {
            if(i+1 < stages[j]) cnt ++;
        }
        stage_info[i] = make_pair(i+1, make_pair(users-cnt, users));
        users -= users-cnt;
    }
    
    sort(stage_info.begin(), stage_info.end(), compare);
    
    for(int i = 0; i < N; i ++) {
        answer.push_back(stage_info[i].first);
    }
    
    return answer;
}