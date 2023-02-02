#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int vec[26] = {0};

    for(int i = 0; i < 26; i ++) {
        vec[i] = str.find('a'+i);
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}