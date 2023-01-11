#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    int num_commands = 0;
    string buf;
    int num;
    stack<int> st;

    cin >> num_commands;

    for(int i = 0; i < num_commands; i ++) {
        cin >> buf;
        if (buf == "push") {
            int num;
            cin >> num;
            st.push(num);
        } else if(buf == "pop") {
            if(st.empty()) {
                cout << "-1" << endl;
            } else {
                int res = st.top();
                cout << res << endl;
                st.pop();
            }
        } else if(buf == "size") {
            int res = st.size();
            cout << res << endl;
        } else if(buf == "empty") {
            if(st.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        } else if(buf == "top") {
            
            if(st.empty()) {
                cout << "-1" << endl;
            } else {
                int res = st.top();
                cout << res << endl;
            }
        }
    }

    return 0;
}