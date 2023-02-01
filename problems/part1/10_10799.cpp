#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    int total = 0;
    int open = 0;
    int close = 0;

    cin >> str;

    for(int i = 0; i < str.length(); i ++) {
        if(i == str.length()-1) {
                total += open;
        } else if(str[i] == '(') {
            if(str[i+1] == ')') {
                // lazer
                total += open;
                open -= close;
                close = 0;
            } else {
                open ++;
            }
        } else if(str[i] == ')') {
            if(str[i-1] != '(') {
                close ++;
            }
        }
    }
    cout << total << '\n';


    return 0;
}