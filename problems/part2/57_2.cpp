#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(string s) {
    set<int> input;
    int cntlst[100001] = {0};
    
    string str = "";
    vector<int> arr;
    
    for(int i = 1; i < s.length()-1; i ++) {
        if(s[i] >= '0' && s[i] <= '9') {
            str += s[i];
        } else if(s[i] == ',' || s[i] == '}') {
            if(str != "") {
                int num = stoi(str);
                arr.push_back(num);
                input.insert(num);
                cntlst[num] ++;
            }
            str = "";
        }
    }

    int sz = input.size();
    int cnt = 0;
    vector<int> answer(sz);
    
    for(int i = 1; i < 100001; i ++) {
        if(cnt == sz) break;
        if(cntlst[i] != 0) {
            answer[sz-cntlst[i]] = i;
            cnt ++;
        }
    }
    
    return answer;
}