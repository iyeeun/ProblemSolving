#include <iostream>

using namespace std;

int main() {
    int T;
    int num;
    int cnt = 0;
    cin >> T;

    for(int i = 0; i < T; i ++) {
        cin >> num;

        int isPrime = 1;
        if(num == 1) {
            isPrime = 0;
        } else {
            for(int j = 2; j <= num-1; j ++) {
                if(num % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if(isPrime == 1)
            cnt ++;
    }

    cout << cnt << '\n';

    return 0;
}