#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    stringstream ss;
    map<string, string> idinfo;
    vector<pair<string, string>> parsed;
    
    for(string s : record) {
        ss.str("");
        ss.clear();
        
        ss.str(s);
        
        string action;
        string userid ;
        string nickname;
        
        ss >> action >> userid >> nickname;
        
        if(action == "Enter") {
            idinfo[userid] = nickname;
            parsed.push_back(make_pair(action, userid));
        } else if(action == "Leave") {
            parsed.push_back(make_pair(action, userid));
        } else {
            idinfo[userid] = nickname;
        }
    }
    
    for(auto i : parsed) {
        string ans = idinfo[i.second];
        if(i.first == "Enter") {
            ans += "님이 들어왔습니다.";
        } else if(i.first == "Leave") {
            ans += "님이 나갔습니다.";
        }
        answer.push_back(ans);
    }
    
    return answer;
}