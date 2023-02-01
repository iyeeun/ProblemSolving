#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    stack<char> st;
    string str;
    int isOpen = 0;

    getline(cin, str);
    str += " ";

    for(int i = 0; i < str.length(); i ++) {
        char c = str[i];
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            if(isOpen) {
                cout << c;
            } else {
                st.push(c);
            }
        } else if(c == '<') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            isOpen = 1;
            cout << "<";
        } else if(c == '>') {
            isOpen = 0;
            cout << ">";
        } else if(c == ' ') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }
    cout << "\n";


    return 0;
}