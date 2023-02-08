#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    long n, s, num, res = 1000000000;
    vector<long> a;

    cin >> n >> s;

    /*
    3, 100 43 23 => 1
    3, 100 50 23 => 1
    3, 43 23 => 20
    */

    if(n == 1) {
        cin >> num;
        cout << abs(s-num) << endl;
        return 0;
    }

    for(int i = 0; i < n; i ++) {
        cin >> num;
        a.push_back(abs(s-num));
    }

    for(long i = 0; i < n; i ++) {
        int j = i+1;
        long max = (a[i] > a[j])? a[i] : a[j];
        long min = (a[i] > a[j])? a[j] : a[i];
        while(min > 0) {
            long tmp = max % min;
            max = min;
            min = tmp;
        }
        if(max < res) res = max;
    }

    cout << res << endl;

    return 0;
}