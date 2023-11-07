#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    map<string, vector<int>> allcases;
    
    stringstream ss;
    
    for(string i : info) {
        vector<string> conds;
        int score;
        vector<string> s(4);
        ss.str("");
        ss.clear();
        ss.str(i);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> score;
        
        conds.push_back(s[0]);
        conds.push_back("-");
        
        for(int i = 1; i < 4; i ++) {
            vector<string> tmp;
            for(int j = 0; j < conds.size(); j ++) {
                tmp.push_back(conds[j]+s[i]);
                conds[j] += "-";
            }
            conds.insert(conds.end(), tmp.begin(), tmp.end());
        }
        for(auto i : conds) {
            allcases[i].push_back(score);
        }
    }
    
    for(auto it = allcases.begin(); it != allcases.end(); it ++) {
        sort(it->second.begin(), it->second.end());
    }

    for(auto q : query) {
        int score;
        vector<string> s(5);
        ss.str("");
        ss.clear();
        ss.str(q);
        ss >> s[0] >> s[4] >> s[1] >> s[4] >> s[2] >> s[4] >> s[3] >> score;
        string cond = s[0] + s[1] + s[2] + s[3];
        auto it = lower_bound(allcases[cond].begin(), allcases[cond].end(), score);
        answer.push_back((allcases[cond].end() - it));
    }
    
    return answer;
}