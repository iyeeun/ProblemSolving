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
    
    int size = category.size();
    
    if(size == 30){ return 1073741823; }
    
    
    vector<int> cntlst;
    for(auto i : category) {
        cntlst.push_back(category_cnt[i]);
    }
    
    for(int i = 1; i < (1 << size); i ++) {
        int tmp = 1;
        for(int j = 0; j < size; j ++) {
            if(i & (1 << j)) {
                tmp *= cntlst[j];
            }
        }
        answer += tmp;
    }
        
    answer --;
    
    return answer;
}