#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    map<char, int> m;
    m.insert({{'A', 0}, {'C', 1}, {'F', 2}, {'J', 3}, 
             {'M', 4}, {'N', 5}, {'R', 6}, {'T', 7}});
    
    vector<int> v;
    for(int i = 0; i < 8; i ++) v.push_back(i);
    
    while(true) {
        bool ok = true;
        for(auto d : data) {
            auto it1 = find(v.begin(), v.end(), m[d[0]]);
            auto it2 = find(v.begin(), v.end(), m[d[2]]);
            
            int target = d[4] - '0';
            int dist = ((it1 > it2)? it1-it2 : it2-it1)-1;
            
            if(d[3] == '=' && dist != target) {
                ok = false;
                break;
            } else if(d[3] == '>' && dist <= target) {
                ok = false;
                break;
            } else if(d[3] == '<' && dist >= target) {
                ok = false;
                break;
            }
        }
        if(ok) answer ++;
        if(!next_permutation(v.begin(), v.end())) break;
    }
    
    
    return answer;
}