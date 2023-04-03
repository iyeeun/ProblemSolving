#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    
    set<int> s;
    
    for(int i = 0; i < len; i ++) {
        int sum = 0;
        for(int j = 0; j < len; j ++) {
            sum += elements[(i+j)%len];
            s.insert(sum);
        }
    }
    
    answer = s.size();
    
    return answer;
}