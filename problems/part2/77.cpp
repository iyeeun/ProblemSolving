#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> idinfo;
    vector<pair<int, string>> parsed;
    for(string s : record) {
        int action;
        string userid = "";
        string nickname = "";
        bool isname = false;
        if(s[0] == 'E') {
            action = 0;
            for(int i = 6; i < s.length(); i ++) {
                if(s[i] == ' ') {
                    isname = true;
                    continue;
                }
                if(!isname) userid += s[i];
                else nickname += s[i];
            }
            idinfo[userid] = nickname;
            parsed.push_back(make_pair(action, userid));
        } else if(s[0] == 'L') {
            action = 1;
            for(int i = 6; i < s.length(); i ++) {
                if(s[i] == ' ') break;
                userid += s[i];
            }
            parsed.push_back(make_pair(action, userid));
        } else if(s[0] == 'C') {
            for(int i = 7; i < s.length(); i ++) {
                if(s[i] == ' ') {
                    isname = true;
                    continue;
                }
                if(!isname) userid += s[i];
                else nickname += s[i];
            }
            idinfo[userid] = nickname;
        }
    }
    
    for(auto i : parsed) {
        string ans = idinfo[i.second];
        if(i.first == 0) {
            ans += "님이 들어왔습니다.";
        } else if(i.first == 1) {
            ans += "님이 나갔습니다.";
        }
        answer.push_back(ans);
    }
    
    return answer;
}