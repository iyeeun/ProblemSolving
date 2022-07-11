#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    vector<int> queue(n);
    int q_size = 0;
    int q_front = 0;
    int q_back = 0;

    string cmd;
    for(int i = 0; i < n; i ++) {
        cin >> cmd;
        cin.ignore();

        if(cmd == "push") {
            int X;
            cin >> X;
            cin.ignore();

            queue[q_back] = X;
            q_size ++;
            q_back ++;

        } else if(cmd == "pop") {
            if(q_front == q_back) {
                cout << "-1\n";
            } else {
                q_size --;
                cout << queue[q_front] << '\n';
                q_front ++;
            }
        } else if(cmd == "size") {
            cout << q_size << '\n';
        } else if(cmd == "empty") {
            if(q_front == q_back) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(cmd == "front") {
            if(q_front == q_back) {
                cout << "-1\n";
            } else {
                cout << queue[q_front] << '\n';
            }
        } else if(cmd == "back") {
            if(q_front == q_back) {
                cout << "-1\n";
            } else {
                cout << queue[q_back-1] << '\n';
            }
        }

    }

    return 0;
}