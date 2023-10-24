#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    deque<int> pq;
    
    for(string op : operations) {
        if(op[0] == 'I') {
            // insert
            int num = stoi(op.substr(2, op.length() - 2));
            if(pq.size() == 0 || num >= pq.back()) {
                pq.push_back(num);
            } else {
                for(int i = 0; i < pq.size(); i ++) {
                    if(num < pq[i]) {
                        pq.insert(pq.begin() + i, num);
                        break;
                    }
                }
            }
            
        } else if(op == "D 1") {
            // delete max
            if(pq.empty()) continue;
            pq.pop_back();
        } else if(op == "D -1") {
            // delete min
            if(pq.empty()) continue;
            pq.pop_front();
        }
    }
    
    if(pq.size() != 0) {
        answer[0] = pq.back();
        answer[1] = pq.front();
    }
    
    return answer;
}