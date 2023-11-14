#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<pair<int, int>> ok;
    for(auto s : stations) {
        ok.push_back(make_pair(max(1, s-w), min(n, s+w)));
    }
    
    int start = 1, part;
    for(auto i : ok) {
        part = i.first-start; 
        if(part > 0) {
            answer += ((part-1) / (2*w+1)) + 1;
        }
        start = i.second+1;
    }
    
    if(n >= start) {
        answer += ((n-start) / (2*w+1)) + 1;
    }

    return answer;
}