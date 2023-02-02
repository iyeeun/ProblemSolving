#include <iostream>
#include <string>
#include <stack>

using namespace std;

int get_type(char c) {
    if(c == '+' || c == '-') {
        return 1;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '(') {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    string str;
    cin >> str;

//A*(B+C)
// * ( +
    stack<char> st;

    for(int i = 0; i < str.length(); i ++) {
        char c = str[i];
        if(c >= 'A' && c <= 'Z') {
            cout << c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty()) {
                if(st.top() == '(') {
                    st.pop();
                    break;
                } else {
                    cout << st.top();
                    st.pop();
                }
            }
        } else {
            while(!st.empty()) {
                if(get_type(st.top()) >= get_type(c)) {
                    cout << st.top();
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << endl;

    return 0;
}

