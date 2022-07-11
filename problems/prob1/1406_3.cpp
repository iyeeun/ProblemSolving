#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    string line;
    string command;
    int n;
    stack<char> s1;
    stack<char> s2;

    getline(cin, line);

    for(int i = 0; i < line.size(); i ++) {
        s1.push(line[i]);
    }

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i ++) {
        cin >> command;
        cin.ignore();

        if(command == "L") {
            if(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        } else if(command == "D") {
            if(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        } else if(command == "B") {
            if(!s1.empty()) {
                s1.pop();
            }
        } else if(command == "P") {
            char c;
            cin >> c;
            cin.ignore();

            s1.push(c);
        }

    }

    string result = "";

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()) {
        result += s2.top();
        s2.pop();
    }

    cout << result << endl;

    return 0;
}