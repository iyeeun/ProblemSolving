#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> inputcnt1;
    map<string, int> inputcnt2;
    
    for(int i = 0; i < str1.length()-1; i ++) {
        string sub = str1.substr(i, 2);
        if(sub[0] >= 'A' && sub[0] <= 'Z') {
            sub[0] = sub[0] - 'A' + 'a';
        } else if(!(sub[0] >= 'a' && sub[0] <= 'z')) {
            continue;   
        }
        if(sub[1] >= 'A' && sub[1] <= 'Z') {
            sub[1] = sub[1] - 'A' + 'a';
        } else if(!(sub[1] >= 'a' && sub[1] <= 'z')) {
            continue;
        }
        
        auto res = inputcnt1.insert(make_pair(sub, 1));
        if(!res.second) {
            inputcnt1[sub] ++;
        }
    }
    
    for(int i = 0; i < str2.length()-1; i ++) {
        string sub = str2.substr(i, 2);
        if(sub[0] >= 'A' && sub[0] <= 'Z') {
            sub[0] = sub[0] - 'A' + 'a';
        } else if(!(sub[0] >= 'a' && sub[0] <= 'z')) {
            continue;   
        }
        if(sub[1] >= 'A' && sub[1] <= 'Z') {
            sub[1] = sub[1] - 'A' + 'a';
        } else if(!(sub[1] >= 'a' && sub[1] <= 'z')) {
            continue;
        }
        
        auto res = inputcnt2.insert(make_pair(sub, 1));
        if(!res.second) {
            inputcnt2[sub] ++;
        }
    }
    
    int total = 0;
    int intersect = 0;
    set<string> inp;
    for(auto i : inputcnt1) {
        total += i.second;
        inp.insert(i.first);
    }
    for(auto i : inputcnt2) {
        auto res = inp.insert(i.first);
        if(!res.second) {
            intersect += min(inputcnt1[i.first], inputcnt2[i.first]);
            total -= inputcnt1[i.first];
            total += max(inputcnt1[i.first], inputcnt2[i.first]);
        } else {
            total += i.second;
        }
    }
        
    if(total == 0) answer = 65536;
    else {
        answer = intersect / (double) total * 65536;
    }
    
    return answer;
}