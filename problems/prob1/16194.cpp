#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> p(N+1);

    for(int i = 1; i <= N; i ++) {
        cin >> p[i];
    }

    for(int i = 2; i <= N; i ++) {
        for(int j = 1; j <= i/2; j ++) {
            int new_price = p[j] + p[i-j];
            if(p[i] > new_price) {
                p[i] = new_price;
            }
        }
    }

    cout << p[N] << '\n';

    return 0;
}