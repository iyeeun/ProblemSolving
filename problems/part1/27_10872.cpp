#include <iostream>

using namespace std;

int main() {
    long num, n;
    cin >> num;
    n = num;
    for(int i = 2; i < num; i ++) {
        n *= i;
    }
    if(n == 0) n = 1;

    cout << n << endl;

    return 0;
}