#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int N;
    string cmd;

    cin >> N;
    cin.ignore();

    vector<int> deque(N);
    int front = 0;
    int back = 0;
    int size = 0;

    for(int i = 0; i < N; i ++) {
        cin >> cmd;
        cin.ignore();

        if(cmd == "push_front") {
            int x;
            cin >> x;
            cin.ignore();
            deque.push_back(0);
            back ++;
            for(int j = back-1; j >= front; j --) {
                deque[j+1] = deque[j];
            }
            deque[front] = x;
            size ++;
        } else if(cmd == "push_back") {
            int x;
            cin >> x;
            cin.ignore();
            deque[back++] = x; 
            size ++;
        } else if(cmd == "pop_front") {
            if(size == 0) {
                cout << "-1\n";
            } else {
                cout << deque[front++] << '\n';
                size --;
            }
        } else if(cmd == "pop_back") {
            if(size == 0) {
                cout << "-1\n";
            } else {
                cout << deque[--back] << '\n';
                size --;
            }
        } else if(cmd == "size") {
            cout << size << '\n';
        } else if(cmd == "empty") {
            if(size == 0) 
                cout << "1\n";
            else
                cout << "0\n";
        } else if(cmd == "front") {
            if(size == 0) {
                cout << "-1\n";
            } else {
                cout << deque[front] << '\n';
            }
        } else if(cmd == "back") {
            if(size == 0) {
                cout << "-1\n";
            } else {
                cout << deque[back-1] << '\n';
            }
        }
    }

    return 0;
}