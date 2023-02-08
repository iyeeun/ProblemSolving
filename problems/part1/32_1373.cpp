#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string n;
    cin >> n;
    string ans = "";
    string sub = "";
    int sum = 0;

    if(n.length()%3 != 0) {
        for(int i = 0; i < 3-n.length()%3; i ++) {
            sub += "0";
        }
        n = sub + n;
    }
    
    for(int i = 0; i < n.length(); i += 3) {
        sum = 0;
        for(int j = 0; j < 3; j ++) {
            if(n[i+j] == '1') {
                sum += pow(2, 2-j);
            }
        }
        ans += to_string(sum);
    }
    cout << ans << endl;

    return 0;
}