#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        if(tmp < 2) continue;
        int cnttmp = 0;
        for(int j = 2; j < tmp; j ++) {
            if(tmp%j == 0) cnttmp ++;
        }
        if(cnttmp == 0) cnt ++;
    }
    cout << cnt << endl;

    return 0;
}