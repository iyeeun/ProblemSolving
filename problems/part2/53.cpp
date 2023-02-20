#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;
    
    for(int i = 0; i < s.length(); i ++) {
        for(int j = 0; j < s.length(); j ++) {
            char c = s[(i+j)%s.length()];

            if(c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else if(c == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    st.push('#');
                    break;
                }
            } else if(c == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push('#');
                    break;
                }
            } else if(c == '}') {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    st.push('#');
                    break;
                }
            }
        }    
        
        if(st.empty()) {
            answer ++;
        } else {
            while(!st.empty()) st.pop();
        }
    }
    
    return answer;
}