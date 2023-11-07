#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    set<pair<long long, long long>> coors;
    
    for(auto l1 : line) {
        for(auto l2 : line) {
            if(l1 == l2) continue;
            long long xu = (long)l1[1]*l2[2] - (long)l1[2]*l2[1];
            long long down = (long)l1[0]*l2[1] - (long)l1[1]*l2[0];
            if(down == 0) continue;
            long long yu = (long)l1[2]*l2[0] - (long)l1[0]*l2[2];
            if(xu % down == 0 && yu % down == 0) {
                coors.insert(make_pair(xu/down, yu/down));
            }
        }
    }
        
    long long xmax = -10000000000000, xmin = 10000000000000, ymax = -10000000000000, ymin = 10000000000000;
    for(auto c : coors) {
        if(c.first > xmax) xmax = c.first;
        if(c.first < xmin) xmin = c.first;
        if(c.second > ymax) ymax = c.second;
        if(c.second < ymin) ymin = c.second;
    }

    string str = "";
    for(long long i = 0; i < (xmax-xmin+1); i ++) {
        str += ".";
    }
    for(long long i = 0; i < (ymax-ymin+1); i ++) {
        answer.push_back(str);
    }

    for(auto c : coors) {
        answer[ymax-c.second][c.first-xmin] = '*';
    }

    
    return answer;
}