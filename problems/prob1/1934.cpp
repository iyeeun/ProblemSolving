#include <iostream>

using namespace std;

int main() {

    int T;
    int a, b;
    cin >> T;

    for(int i = 0; i < T; i ++) {
        cin >> a >> b;

        int c = a % b;
        int d = a * b;
        while(c != 0) {
            a = b;
            b = c;
            c = a % b;
        }
        cout << d/b << '\n';

    }


    return 0;
}