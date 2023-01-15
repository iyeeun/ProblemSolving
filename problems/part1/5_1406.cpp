#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    string str;
    stack<char> st;
    int open = 0;

    getline(cin, str);
    str += ' ';

    for(int i = 0; i < str.length(); i ++) {
        char c = str[i];
        if(c == '<') {
            open = 1;
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << "<";
        } else if(c == '>') {
            cout << ">";
            open = 0;
        } else if(c == ' ') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        } else {
            if(open == 1) {
                cout << c;
            } else {
                st.push(c);
            }
        }
    }
    cout << '\n';

    return 0;
}