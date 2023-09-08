#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int calcTime(string s1, string s2) {
    int h1 = stoi(s1.substr(0, 2));
    int m1 = stoi(s1.substr(3, 2));
    int h2 = stoi(s2.substr(0, 2));
    int m2 = stoi(s2.substr(3, 2));
    
    return (60 * (h2 - h1) + (m2 - m1));
}

bool cmp(vector<string> a, vector<string> b) {
    if(a[1].substr(0, 2) == b[1].substr(0, 2)) {
        return (a[1].substr(3, 2) < b[1].substr(3, 2));
    } else return (a[1].substr(0, 2) < b[1].substr(0, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), cmp);
        
    stack<pair<string, int>> st;
    
    for(int i = 0; i < plans.size()-1; i ++) {
        int res = calcTime(plans[i][1], plans[i+1][1]);
        int playtime = stoi(plans[i][2]);
        if(res < playtime) {
            st.push(make_pair(plans[i][0], playtime-res));
        } else if(res >= playtime) {
            answer.push_back(plans[i][0]);
            res -= playtime;
            while(res > 0 && !st.empty()) {
                auto t = st.top();
                st.pop();
                int minval = min(res, t.second);
                res -= minval;
                t.second -= minval;
                if(t.second == 0) {
                    answer.push_back(t.first);
                } else {
                    st.push(t);
                }
            }
        }
    }
    
    answer.push_back(plans.back()[0]);
    
    while(!st.empty()) {
        answer.push_back(st.top().first);
        st.pop();
    }
    
    return answer;
}