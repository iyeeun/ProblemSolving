#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int a, b, t, num;
    unsigned int res10 = 0;
    vector<int> resb;
    cin >> a >> b >> t;

    /*
    1001011(2) -> 75(10) -> 113(8)
    1+2+8+64 = 75

    8 16
    4
    3 7 1 1 -> 1993
    => 7 12 9
    */

   // a->10진법으로 변환
    for(int i = 0; i < t; i ++) {
        cin >> num;
        res10 += num * pow(a, t-i-1);
    }
    // 10->b진법으로 변환
    while(res10 > 0) {
        unsigned int tmp = res10 % b;
        res10 /= b;
        resb.push_back(tmp);
    }
    
    if(resb.size() == 0) {
        cout << "0\n";
    } else {
        for(int i = resb.size()-1; i >= 0; i --) {
            cout << resb[i] << " ";
        }
        cout << endl;
    }

    return 0;
}