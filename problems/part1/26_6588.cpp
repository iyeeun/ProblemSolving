#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int vec[1000001];
    fill_n(vec, 1000001, 1);
    vec[0] = vec[1] = 0;

    for(int i = 3; i*i < 1000000; i += 2) {
        if(vec[i]) {
            for(int j = 2*i; j <= 1000000; j += i) {
                vec[j] = 0;
            }
        }
    }

    while(true) {
        cin >> n;
        if(n == 0) break;
        int a, b;
        
        int isRight = 0;
        for(int i = 3; i <= n; i += 2) {
            if(vec[i] && vec[n-i]) {
                a = i;
                b = n-i;
                isRight = 1;
                break;
            }
        }
        if(isRight) {
            cout << n << " = " << a << " + " << b << "\n";
        } else {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}