#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    stack<string> st;
    
    for(int i = 0; i < strings.size(); i ++) {
        char c = strings[i][n];
        if(st.empty()) {
            st.push(strings[i]);
        } else {
            if(st.top()[n] < c) {
                while(!st.empty() && st.top()[n] < c) {
                    answer.push_back(st.top());
                    st.pop();  
                }
            } else if(st.top()[n] > c) {
                //push
            } else if(st.top()[n] == c) {
                if(st.top() < strings[i]) {
                    answer.push_back(st.top());
                    st.pop();
                }
            }
            st.push(strings[i]);
        }
    }
    
    while(!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }
    
    return answer;
}