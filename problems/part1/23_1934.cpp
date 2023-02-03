#include <iostream>

using namespace std;

int main() {

    int n, a, b, max, min;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        cin >> a >> b;

        if(a > b) {
            max = a; min = b;
        } else {
            max = b; min = a;
        }

        while(min > 0) {
            int tmp = max % min;
            max = min;
            min = tmp;
        }
        cout << a * b / max << '\n';
    }

    return 0;
}