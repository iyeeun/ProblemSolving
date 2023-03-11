#include <iostream>

using namespace std;

int main() {
    long n, res = 0;
    cin >> n;

    long min = 1;
    long max = 9;
    int len = 1;

    while(max < n) {
        res += (max - min + 1)*len;
        max = 10*max + 9;
        min *= 10;
        len ++;
    }

    res += (n - min + 1)*len;

    cout << res << "\n";

    return 0;
}