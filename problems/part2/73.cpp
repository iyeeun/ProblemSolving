#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    for(int i = 0; i < 26; i ++) {
        string s;
        s += 'A'+i;
        dict[s] = i+1;
    }
    int count = 27;
    
    int idx = 0;
    bool end = false;
    while(idx < msg.length()) {
        string target;
        int len = 2;
        
        while(true) {
            if(idx+len > msg.length()) { // last
                target = msg.substr(idx, msg.length()-idx);
                if(dict.find(target) == dict.end()) {
                    answer.push_back(count);
                } else {
                    answer.push_back(dict[target]);
                }
                idx += target.length();
                end = true;
                break;
            } else {
                target = msg.substr(idx, len);
            }
            if(dict.find(target) == dict.end()) {
                break;
            } else {
                len ++;
            }
        }
        if(!end) {
            string out = target.substr(0, target.length()-1);
            answer.push_back(dict[out]);
            dict[target] = count;
            count ++;
            idx += out.length();
        }
    }
    
    return answer;
}