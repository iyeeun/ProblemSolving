#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    int isRight = 0;

    string str;

    for(int i = 0 ; i < T; i ++) {
        getline(cin, str);
        str += "\n";

        stack<char> s;

        for(int j = 0; j < str.size(); j ++) {
            if(str[j] == '(') {
                s.push('(');
            } else if(str[j] == ')') {
                if(s.empty()) {
                    cout << "NO" << endl;
                    break;
                }
                s.pop();
            } else if(str[j] == '\n') {
                if(!s.empty())
                    cout << "NO" << endl;
                else
                    cout << "YES" << endl;
            }
        }
    }

    return 0;
}