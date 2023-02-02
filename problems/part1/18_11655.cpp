#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    for(int i = 0; i < str.length(); i ++) {
        int c = str[i];
        if(c >= 'A' && c <= 'Z') {
            c += 13;
            if(c > 'Z') {
                c -= 26;
            }
        } else if(c >= 'a' && c <= 'z') {
            c += 13;
            if(c > 'z') {
                c -= 26;
            }
        }
        cout << (char)c;
    }
    cout << endl;

    return 0;
}