#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    int cnt = 0;
    cin >> N;

    for(int i = 1; i <= N; i ++) {
        int tmp = i;
        while(tmp % 5 == 0) {
            cnt ++;
            tmp /= 5;
        }
    }

    cout << cnt << '\n';

    return 0;
}