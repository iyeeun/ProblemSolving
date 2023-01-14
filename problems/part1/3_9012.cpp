#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;
    stack<char> st;
    
    for(int i = 0; i < n; i ++) {
        // input
        string str;
        cin >> str;

        for(int j = 0; j < str.length(); j ++) {
            char c = str[j];
            if(c == '(') {
                st.push(c);
            } else if(c == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        // result
        if(st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            while(!st.empty()) {
                st.pop();
            }
        }
    }

    return 0;
}