#include <string>
#include <vector>
#include <iostream>

using namespace std;

void cardopen(vector<int> &cards, vector<bool> &open, vector<int> &group, 
              int n, int res) {
    if(open[n]) {
        if(res != 0) group.push_back(res);
        return;
    }
    
    open[n] = true;
    if(open[cards[n]]) {
        group.push_back(res+1);
        return;
    } else cardopen(cards, open, group, cards[n], res+1);
}

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int i = 0; i < cards.size(); i ++) cards[i] --;
    
    vector<bool> open(cards.size(), false);
    vector<int> group;
    
    for(int i = 0; i < cards.size(); i ++) {
        if(open[i]) continue;
        cardopen(cards, open, group, i, 0);
    }
    
    for(int i = 0; i < group.size(); i ++) {
        for(int j = 0; j < group.size(); j ++) {
            if(i == j) continue;
            if(answer < group[i]*group[j]) answer = group[i]*group[j];
        }
    }
    
    return answer;
}