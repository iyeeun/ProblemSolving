#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    set<string> prev;
    int fail = -1;
    
    for(int i = 0; i < words.size(); i ++) {
        if(words[i].length() == 1) {
            fail = i;
            break;
        } else if(i != 0 && words[i-1][words[i-1].length()-1] != words[i][0]) {
            fail = i;
            break;
        }
        auto isok = prev.insert(words[i]);
        if(isok.second == false) {
            fail = i;
            break;
        }
    }
    
    cout << fail << endl;
        
    if(fail == -1) {
        answer[0] = answer[1] = 0;
    } else {
        answer[0] = fail % n + 1;
        if(answer[0] == 0) answer[0] = n;
        answer[1] = fail / n + 1;
    }

    return answer;
}