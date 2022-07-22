#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int m;
    string num;
    int cnt = 0;
    cin >> num;
    cin.ignore();
    cin >> m;
    int * button = new int[m];
    for(int i = 0; i < m; i ++) {
        cin >> button[i];
    }

    if(num != "100") {
        cnt += num.length();
        if(m != 0) {
            for(int i = 0; i < num.length(); i ++) {
                int target = num[i] - '0';
                cout << target << ' ';
            }

        }
    }

    cout << cnt << '\n';

    return 0;
}