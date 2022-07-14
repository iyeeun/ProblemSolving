#include <iostream>
#include <cmath>

using namespace std;

int getNum(int a, int b) {
    int cnt = 0;
    for(unsigned long long i = a; i <= b; i *= a) {
        cnt += b / i;
    }
    return cnt;
}

int main() {

    unsigned long long n, m;
    int start;
    int cnt_2 = 0;
    int cnt_5 = 0;

    cin >> n >> m;
    
    cnt_2 += getNum(2, n);
    cnt_2 -= getNum(2, m);
    cnt_2 -= getNum(2, n-m);

    cnt_5 += getNum(5, n);
    cnt_5 -= getNum(5, m);
    cnt_5 -= getNum(5, n-m);

    cout << min(cnt_2, cnt_5) << '\n';

    return 0;
}