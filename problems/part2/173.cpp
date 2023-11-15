#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    set<string> s(gems.begin(), gems.end());
    int sz = s.size();
    map<string, int> m;
    
    int head = 0, tail = 0, mindist = -1;
    
    while(head < gems.size() && tail <= gems.size()) {
        if(m.size() < sz) {
            if(tail == gems.size()) break;
            m[gems[tail]] ++;
            tail ++;
        } else if(m.size() >= sz) {
            if(m.size() == sz && (mindist == -1 || tail - head < mindist)) {
                mindist = tail - head;
                answer[0] = head+1;
                answer[1] = tail;
            }
            m[gems[head]] --;
            if(m[gems[head]] == 0) m.erase(gems[head]);
            head ++;
        }
    }
    
    return answer;
}