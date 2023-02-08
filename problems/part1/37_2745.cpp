#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string n;
    int b;
    long res = 0;

    cin >> n >> b;

    for(int i = 0; i < n.length(); i ++) {
        int num = 0;
        if(n[i] >= 'A') {
            num = n[i] - 'A' + 10;
        } else {
            num = n[i] - '0';
        }
        res += num * pow(b, n.length()-i-1);
    }

    cout << res << endl;

    return 0;
}