#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    
    for(int i = 0; i < numbers.size(); i ++) {
        answer.push_back(-1);
        while(!st.empty() && numbers[st.top()] < numbers[i]) {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }
    
    return answer;
}