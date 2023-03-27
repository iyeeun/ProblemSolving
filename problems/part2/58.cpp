#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> category_cnt;
    set<string> category;
    
    for(int i = 0; i < clothes.size(); i ++) {
        auto res = category.insert(clothes[i][1]);
        if(res.second) {
            category_cnt.insert({clothes[i][1], 1});
        } else {
            category_cnt[clothes[i][1]] ++;
        }
    }
    
    for(auto i : category_cnt) {
        answer *= (i.second + 1);
    }
    
    answer --;
    
    return answer;
}