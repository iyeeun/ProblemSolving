#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long num;
    cin >> num;
    string res = "";

    /*
    1, 110, 111, 100, 101, 11010, 11011, 11000, 11001
    10 11 00 01 -> 
    11 10 1011 1010 
    -3 = 4 - 8 + 1
    */
    if(num == 0) {
        cout << "0\n";
        return 0;
    }

    while(true) {
        if(num == 0) break;
        if(num % -2 == 0) {
            res += '0';
            num /= -2;
        } else {
            res += '1';
            num = (num-1) / -2;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}