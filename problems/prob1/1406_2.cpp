#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    string line;
    string a;
    string r;
    string command;
    stack<char> s;

    getline(cin, line);

    for(int i = 0; i < line.size(); i ++) {
        s.push(line[i]);
    }

    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i ++) {
        cin >> command;
        if(command == "L") {
            if(!s.empty()) {
                r += s.top();
                s.pop();
            }
        } else if(command == "D") {
            if(r.size() != 0) {
                s.push(r[0]);
                for(int j = 0; j < r.size(); j ++) {
                    r[j] = r[j+1];
                }
                r[r.size()-1] = '\0';
            }
        } else if(command == "B") {
            if(!s.empty()) {
                s.pop();
            }
        } else if(command == "P") {
            char c;
            cin >> c;
            cin.ignore();
            s.push(c);
        }
    }

    for(int i = 0; i < s.size(); i ++) {
        a += " ";
    }

    while(!s.empty()) {
        a[s.size()-1] = s.top();
        s.pop();
    }

    for(int i = r.size()-1; i >= 0; i --) {
        a += r[i];
    }

    cout << a << endl;

    return 0;
}