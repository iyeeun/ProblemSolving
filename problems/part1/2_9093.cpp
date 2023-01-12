#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    cin.ignore();
    string buf;
    string word = "";
    stack<char> st = stack<char>();

    for(int i = 0; i < n; i ++) {
        getline(cin, buf);
        buf += '0';
        for(int j = 0; j < buf.length(); j ++) {
            if(buf[j] >= 'A' && buf[j] <= 'z') {
                st.push(buf[j]);
            } else {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << " ";                
            }
        }
        cout << endl;
    }
    
    return 0;
}