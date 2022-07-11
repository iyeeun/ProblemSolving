#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n;
    int num;
    int curr = 0;
    stack<int> s;
    vector<char> r;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i ++) {
        cin >> num;
        cin.ignore();

        if(num > curr) {
            while(num > curr) {
                curr ++;
                s.push(curr);
                r.push_back('+');
            }
            s.pop();
            r.push_back('-');
        } else if (num < curr) {
            bool isPossible = false;
            if(!s.empty()) {
                if(num == s.top()) {
                    isPossible = true;
                }
                s.pop();
                r.push_back('-');
            }

            if(!isPossible) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    for(int i = 0; i < r.size(); i ++) {
        cout << r[i] << "\n";
    }

    return 0;
}