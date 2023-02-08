#include <iostream>
#include <string>

using namespace std;

int main() {
    long n, b;
    cin >> n >> b;
    string str = "";

    char arr[36];
    for(int i = 0; i < 10; i ++) {
        arr[i] = i+'0';
    }
    for(int i = 0; i < 26; i ++) {
        arr[10+i] = i+'A';
    }

    while(n > 0) {
        int tmp = n % b;
        n /= b;
        str = arr[tmp] + str;
    }

    cout << str << endl;

    return 0;
}