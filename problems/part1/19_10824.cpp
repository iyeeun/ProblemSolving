#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getSize(int num) {
    int res = 0;
    while(num != 0) {
        num /= 10;
        res ++;
    }
    return res;
}

int main() {
    unsigned long a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fixed;
    cout.precision(0);
    cout << ((a*pow(10, getSize(b)) + b)+(c*pow(10, getSize(d)) + d)) << endl;

    return 0;
}