#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    set<string> proc_report(report.begin(), report.end());
    vector<pair<string, string>> report_info;
    map<string, int> report_num;
    map<string, int> stop_num;

    for(auto i : id_list) {
        report_num[i] = 0;
        stop_num[i] = 0;
    }
    
    for(auto r : proc_report) {
        int idx = r.find(" ");
        string user1 = r.substr(0, idx);
        string user2 = r.substr(idx+1, r.length()-idx-1);
        report_info.push_back(make_pair(user1, user2));
        report_num[user2] ++;
    }
    
    int i = 0;
    for(auto p : report_info) {
        if(report_num[p.second] >= k) {
            stop_num[p.first] ++;
        }
        i ++;
    }
    
    i = 0;
    for(auto il : id_list) {
        answer[i] = stop_num[il];
        i ++;
    }
    
    return answer;
}