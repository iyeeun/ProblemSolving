#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<string> v;

    for(int i = 0; i < str.length(); i ++) {
        v.push_back(str.substr(i, str.length()));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < str.length(); i ++) {
        cout << v[i] << endl;
    }

    return 0;
}