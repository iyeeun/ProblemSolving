#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parse(vector<string> str) {
    vector<int> res;
    res.push_back(stoi(str[0].substr(0, 2)));
    res.push_back(stoi(str[0].substr(3, 2)));
    res.push_back(stoi(str[1].substr(0, 2)));
    res.push_back(stoi(str[1].substr(3, 2))+10);
    if(res[3] >= 60) {
        res[3] -= 60;
        res[2] ++;
    } 
    return res;
}

int solution(vector<vector<string>> book_time) {
    int answer = -1;
    vector<vector<int>> time(25, vector<int>(60, 0));
    
    for(vector<string> t : book_time) {
        vector<int> tmp = parse(t);
        time[tmp[0]][tmp[1]] += 1;
        time[tmp[2]][tmp[3]] -= 1;
    }
    
    for(int i = 0; i < 25; i ++) {
        for(int j = 0; j < 59; j ++) {
            time[i][j+1] += time[i][j];
        }
        if(i != 24) time[i+1][0] += time[i][59];
    }

    for(auto i : time) {
        answer = max(answer, *max_element(i.begin(), i.end()));
    }
    
    return answer;
}