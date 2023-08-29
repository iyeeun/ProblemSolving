#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int del = 0, i = 0;
    stack<char> st;
    
    for(i = 0; i < number.length(); i ++) {
        char c = number[i];
        while(!st.empty() && st.top() < c) {
            st.pop();
            del ++;
            if(del == k) break;
        }
        st.push(c);
        if(del == k) break;
    }
    
    for(int j = i+1; j < number.length(); j ++) {
        st.push(number[j]);
    }
    
    while(!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }
    
    return answer.substr(0, number.length()-k);
}