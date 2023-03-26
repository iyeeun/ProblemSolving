#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int size = 0;
    for(int i = 1; i < s.length()-1; i ++) {
        if(s[i] == '{') size ++;
    }
    
    vector<int> answer(size, 0);
    vector<vector<int>> input(size);
    
    int cnt = 0;
    bool open = false;
    vector<int> tmp;
    string str = "";
        
    for(int i = 1; i < s.length()-1; i ++) {
        if(s[i] == '{') {
            open = true;
        } else if(s[i] == '}') {
            open = false;
            cnt ++;
            tmp.push_back(stoi(str));
            str = "";
            input[cnt-1].assign(tmp.begin(), tmp.end());
            tmp.clear();
            cnt = 0;
        } else if(s[i] == ',') {
            if(open) {
                cnt ++;
                tmp.push_back(stoi(str));
                str = "";
            }
        } else if(s[i] <= '9' && s[i] >= '0') {
            if(open) {
                str += s[i];
            }
        }
    }
    
    answer[0] = input[0][0];
    for(int i = 1; i < size; i ++) {
        for(int j = i; j < size; j ++) {
            auto t = find(input[j].begin(), input[j].end(), answer[i-1]);
            input[j].erase(t);
        }
        answer[i] = input[i][0];
    }
    
    return answer;
}