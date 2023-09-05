#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, int> count;
    vector<int> w;
    
    for(int i : weights) {
        count[i] ++;
        if(count[i] == 1) w.push_back(i);
    }
    
    sort(w.begin(), w.end());
    
    int ratio[3][2] = {{2, 1}, {3, 2}, {4, 3}};
    
    for(int i : w) {
        for(int j = 1; j < count[i]; j ++) answer += j;
    }
    
    for(int i = 0; i < w.size(); i ++) {
        for(int j = i+1; j < w.size(); j ++) {
            if(i == j) continue;
            for(int t = 0; t < 3; t ++) {
                if(w[i] * ratio[t][0] == w[j] * ratio[t][1]) {
                    answer += (count[w[i]] * count[w[j]]);
                    break;
                }
            }
        }
    }
    
    return answer;
}