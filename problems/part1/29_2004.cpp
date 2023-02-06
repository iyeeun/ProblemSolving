#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    unsigned long int a,b;
    cin >> a >> b;

    if(a-b < b) b = a-b;

    if(b == 0) {
        cout << "0\n";
        return 0;
    }

    unsigned long int cnt5 = 0, cnt2 = 0;
    unsigned long int start1, start2;

    if(a < 5) {
        start1 = 0;
    } else if(b < 5) {
        start2 = 0;
    } else {
        for(unsigned long int i = 0; i < 5; i ++) {
            if((a-i) % 5 == 0) {
                start1 = (a-i);
            }

            if((b-i) % 5 == 0) {
                start2 = (b-i);
            }
        }
    }

    for(unsigned long int i = start1; i > a-b; i -= 5) {
        unsigned long int tmp1 = i;
        while(tmp1 >= 5 && tmp1 % 5 == 0) {
            cnt5 ++;
            tmp1 /= 5;
        }
    }
    cout << "1 : " << cnt5 << endl;

    for(unsigned long int i = start2; i > 0; i -= 5) {
        unsigned long int tmp2 = i;
        while(tmp2 >= 5 && tmp2 % 5 == 0) {
            cnt5 --;
            tmp2 /= 5;
        }
    }
    cout << "2 : " << cnt5 << endl;

    if(a%2 == 0) start1 = a;
    else start1 = a-1;
    if(b%2 == 0) start2 = b;
    else start2 = b-1;

    for(unsigned long int i = start1; i > a-b; i -= 2) {
        unsigned long int tmp1 = i;
        while(tmp1 >= 2 && tmp1 % 2 == 0) {
            cnt2 ++;
            tmp1 /= 2;
        }
    }
    cout << "3 : " << cnt2 << endl;

    for(unsigned long int i = start2; i > 0; i -= 2) {
        unsigned long int tmp2 = i;
        while(tmp2 >= 2 && tmp2 % 2 == 0) {
            cnt2 --;
            tmp2 /= 2;
        }
    }
    cout << "4 : " << cnt2 << endl;

    // cout << min(cnt5, cnt2) << endl;
    cout << cnt5 << cnt2 << endl;


    return 0;
}