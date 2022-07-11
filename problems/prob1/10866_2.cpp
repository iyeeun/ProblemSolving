#include <iostream>
#include <deque>

using namespace std;

int main() {

    deque<int> d;

    int N;
    string cmd;

    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i ++) {
        cin >> cmd;
        cin.ignore();
        if(cmd == "push_front") {
            int x;
            cin >> x;
            cin.ignore();
            d.push_front(x);
        } else if(cmd == "push_back") {
            int x;
            cin >> x;
            cin.ignore();
            d.push_back(x);
        } else if(cmd == "pop_front") {
            if(d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if(cmd == "pop_back") {
            if(d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } else if(cmd == "size") {
            cout << d.size() << '\n';
        } else if(cmd == "empty") {
            if(d.empty()) 
                cout << "1\n";
            else
                cout << "0\n";
        } else if(cmd == "front") {
            if(d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.front() << '\n';
            }
        } else if(cmd == "back") {
            if(d.empty()) {
                cout << "-1\n";
            } else {
                cout << d.back() << '\n';
            }
        }
    }

    return 0;
}